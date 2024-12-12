#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <unordered_map>
#include <memory>
#include <string>
#include "../Interfaces/SensorIF.h"
#include "../Concrete/WeatherData.h"
#include "../Factories/SensorFactory.h"

class SensorManager {
private:
    WeatherData Data;
    SensorFactory Factory;
public:
    bool AddSensor(const std::string& name, const std::string& type);
    bool DelSensor(const std::string& name);
    std::shared_ptr<SensorIF> GetSensor(const std::string& name) const;
};

#endif // SENSORMANAGER_H