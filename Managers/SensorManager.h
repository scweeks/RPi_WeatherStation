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
    //SensorFactory factory;
    WeatherData data;
    std::atomic<bool> collectingData{ false };
    std::thread collectionThread;
    bool metric = false;
    mutable std::mutex dataMutex;  // Protect shared data
public:
    SensorManager() = default;

    ~SensorManager() {
        StopCollection();
    }

    bool AddSensor(const std::string& type,
        const std::string& name,
        const std::string& connType,
        const std::string& dataType,
        const std::string& ipAddress,
        int port);

    bool DelSensor(const std::string& name);

    std::unique_ptr<SensorIF> GetSensor(const std::string& name);

    bool PrintSensors();

    bool PrintSensorData();

    void RetrieveAndPrintData();

    // Start collecting data from sensors and printing to the console
    bool StartCollection() {
        try {
            if (collectingData) return false;

            collectingData = true;
            collectionThread = std::thread([this]() {
                while (collectingData) {
                    auto start = std::chrono::steady_clock::now();
                    RetrieveAndPrintData();

                    auto end = std::chrono::steady_clock::now();
                    std::chrono::duration<double> elapsed = end - start;
                    double sleepTime = 6.0 - elapsed.count();
                    if (sleepTime > 0.0) {
                        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(sleepTime * 1000)));
                    }
                }
                });
            return true;
        }
        catch (const std::system_error& e) {
            std::cerr << "Thread creation failed: " << e.what() << std::endl;
            return false;
        }
    }

    void StopCollection() {
        collectingData = false;
        if (collectionThread.joinable()) {
            collectionThread.join();
        }
    }

    // Change measurement units to unit or imperial
    //True = metric, False = Imperial
    bool SetUnit(bool unit)
    {
        if (unit != metric)
        {
            metric = unit;
            return true;
        }
        if (unit == metric)
        {
            return true;
        }
        return false;
    };
};

#endif /* MANAGERS_SENSORMANAGER_H_ */
