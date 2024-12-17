#ifndef MANAGERS_SENSORMANAGER_H_
#define MANAGERS_SENSORMANAGER_H_

#include <memory>
#include <string>
#include <mutex>
#include <atomic>
#include <thread>
#include <chrono>
#include <iostream>
#include "../Interfaces/SensorIF.h"
#include "../Concrete/WeatherData.h"
#include "../Factories/SensorFactory.h"

class SensorManager {
private:
    SensorFactory Factory;
    WeatherData Data;
    std::atomic<bool> CollectingData;
    std::thread CollectionThread;
    bool Metric = false;
    mutable std::mutex dataMutex;
    mutable std::mutex printMutex;
public:
    SensorManager() : CollectingData(false) {}
    bool AddSensor(const std::string& type,
        const std::string& name, const std::string& connType,
        const std::string& dataType, const std::string& ipAddress, int port);
    bool DelSensor(const std::string& name);
    std::unique_ptr<SensorIF> GetSensor(const std::string& name);
    bool PrintSensors();
    bool PrintSensorData();
    void RetrieveAndPrintData();
    // Start collecting data from sensors and printing to the console
    bool StartCollection() {
        try {
            CollectingData = true;
            CollectionThread = std::thread([this]() {
                while (CollectingData) {
                    auto start = std::chrono::steady_clock::now();
                    RetrieveAndPrintData();
                    auto end = std::chrono::steady_clock::now();
                    std::chrono::duration<double> elapsed = end - start;
                    if (elapsed.count() < 6.0) {
                        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>((6.0 - elapsed.count()) * 1000)));
                    }
                }
                });
            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception in StartCollection: " << e.what() << std::endl;
            return false;
        }
        catch (...) {
            std::cerr << "Unknown exception in StartCollection" << std::endl;
            return false;
        }
    }

    void StopCollection() {
        CollectingData = false;
        if (CollectionThread.joinable()) {
            CollectionThread.join();
        }
    }
    // Change measurement units to unit or imperial
    //True = Metric, False = Imperial
    bool SetUnit(bool unit)
    {
        if (unit != Metric)
        {
            Metric = unit;
            return true;
        }
        if (unit == Metric)
        {
            return true;
        }
        return false;
    };
};

#endif /* MANAGERS_SENSORMANAGER_H_ */
