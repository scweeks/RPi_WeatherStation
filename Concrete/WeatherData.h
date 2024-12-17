#ifndef CONCRETE_WEATHERDATA_H_
#define CONCRETE_WEATHERDATA_H_

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
    std::unique_ptr<SensorIF> GetSensor(const std::string& name);
    std::vector<SensorIF*> GetAllSensors() const;
};

#endif /* CONCRETE_WEATHERDATA_H_ */
