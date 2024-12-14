#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <memory>
#include <string>
#include <mutex>
#include "../Interfaces/SensorIF.h"
#include "../Concrete/WeatherData.h"
#include "../Factories/SensorFactory.h"

class SensorManager {
private:
    SensorFactory Factory;
    WeatherData Data;
    mutable std::mutex dataMutex;
    mutable std::mutex printMutex;
public:
    bool AddSensor(const std::string& name, const std::string& type, const std::string ipAddress, int port);
    bool DelSensor(const std::string& name);
    std::unique_ptr<SensorIF> GetSensor(const std::string& name) const;
    bool PrintSensors() const;
    bool PrintSensorData() const;
    void RetrieveAndPrintData();
    bool StartCollection();
    bool StopCollection();
};

#endif // SENSORMANAGER_H