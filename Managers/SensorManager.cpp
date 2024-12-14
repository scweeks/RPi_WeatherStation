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

bool SensorManager::AddSensor(const std::string& name, const std::string& type, const std::string ipAddress, int port) {
    std::lock_guard<std::mutex> lock(dataMutex);
    auto sensor = Factory.MakeSensor(type, name, ipAddress, port);
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

std::unique_ptr<SensorIF> SensorManager::GetSensor(const std::string& name) const {
    std::lock_guard<std::mutex> lock(dataMutex);
    return Data.GetSensor(name);
}

bool SensorManager::PrintSensors() const {
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

bool SensorManager::PrintSensorData() const {
    std::lock_guard<std::mutex> lock(printMutex);
    auto sensors = Data.GetAllSensors();
    if (sensors.empty()) {
        return false;
    }
    std::unordered_map<std::string, std::vector<std::unique_ptr<SensorIF>>> sensorMap;
    for (const auto& sensor : sensors) {
        sensorMap[sensor->GetSensorType()].push_back(unique_ptr<SensorIF>(sensor));
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

bool SensorManager::StartCollection() {
    try {
        std::thread([this]() {
            while (true) {
                auto start = std::chrono::steady_clock::now();
                RetrieveAndPrintData();
                auto end = std::chrono::steady_clock::now();
                std::chrono::duration<double> elapsed = end - start;
                if (elapsed.count() < 6.0) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>((6.0 - elapsed.count()) * 1000)));
                }
            }
            }).detach();
        return true;
    }
    catch (...) {
        return false;
    }
}

bool SensorManager::StopCollection() {
    // Implementation to stop the collection
    return true;
}