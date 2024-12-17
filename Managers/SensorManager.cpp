#include "SensorManager.h"
#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <chrono>

std::mutex dataMutex;
std::mutex printMutex;

bool SensorManager::AddSensor(const std::string& type,
    const std::string& name, const std::string& connType,
    const std::string& dataType, const std::string& ipAddress, int port) {
    std::lock_guard<std::mutex> lock(dataMutex);
    auto sensor = SensorFactory::MakeSensor(type, name, connType, dataType, ipAddress, port);
    if (sensor) {
        Data.AddSensor(std::move(sensor));
        return true;
    }
    return false;
}

bool SensorManager::DelSensor(const std::string& name) {
    std::lock_guard<std::mutex> lock(dataMutex);
    return Data.RemoveSensor(name);
}

std::unique_ptr<SensorIF> SensorManager::GetSensor(const std::string& name) {
    std::lock_guard<std::mutex> lock(dataMutex);
    return Data.GetSensor(name);
}

bool SensorManager::PrintSensors() {
    std::lock_guard<std::mutex> lock(printMutex);
    auto sensors = Data.GetAllSensors();
    if (sensors.empty()) {
        return false;
    }
    std::cout << std::left << std::setw(20) << "Name" << std::setw(20) << "Type" << std::setw(20) << "IP" << std::setw(10) << "Port" << std::endl;
    std::cout << std::string(70, '-') << std::endl;
    for (const auto& sensor : sensors) {
        std::cout << std::left << std::setw(20) << sensor->GetSensorName() << std::setw(20) << sensor->GetSensorType()
            << std::setw(20) << sensor->GetConnection()->GetIpAddress() << std::setw(10) << sensor->GetConnection()->GetPort() << std::endl;
    }
    return true;
}

bool SensorManager::PrintSensorData() {
    std::lock_guard<std::mutex> lock(printMutex);
    auto sensors = Data.GetAllSensors();
    if (sensors.empty()) {
        return false;
    }
    std::unordered_map<std::string, std::vector<SensorIF*>> sensorMap;
    for (const auto& sensor : sensors) {
        sensorMap[sensor->GetSensorType()].push_back(sensor);
    }

    for (const auto& entry : sensorMap) {
        std::cout << "Type: " << entry.first << std::endl;
        std::cout << std::left << std::setw(20) << "Name";
        for (const auto& sensor : entry.second) {
            std::cout << std::setw(20) << sensor->GetSensorName();
        }
        std::cout << std::endl;

        std::cout << std::left << std::setw(20) << "Data";
        for (const auto& sensor : entry.second) {
            std::cout << std::setw(20) << sensor->GetSensorData();
        }
        std::cout << std::endl;
    }
    return true;
}

void SensorManager::RetrieveAndPrintData() {
    auto sensors = Data.GetAllSensors();
    std::vector<std::thread> threads;
    std::unordered_map<std::string, std::vector<std::string>> sensorDataMap;

    for (const auto& sensor : sensors) {
        threads.emplace_back([&sensor, &sensorDataMap, this]() {
            auto data = sensor->GetSensorData();
            std::lock_guard<std::mutex> lock(dataMutex);
            sensorDataMap[sensor->GetSensorName()].push_back(data);
            if (sensorDataMap[sensor->GetSensorName()].size() > 10) {
                sensorDataMap[sensor->GetSensorName()].erase(sensorDataMap[sensor->GetSensorName()].begin());
            }
            });
    }

    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    PrintSensorData();
}