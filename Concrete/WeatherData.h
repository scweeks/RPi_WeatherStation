#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include "../Interfaces/SensorIF.h"

class WeatherData {
private:
    std::unordered_map<std::string, std::unique_ptr<SensorIF>> sensors;
public:
    bool AddSensor(std::unique_ptr<SensorIF> sensor);
    bool RemoveSensor(const std::string& name);
    SensorIF* GetSensor(const std::string& name) const;
    std::vector<SensorIF*> GetAllSensors() const;
};

#endif // WEATHERDATA_H