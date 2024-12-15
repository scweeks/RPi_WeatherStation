#include "WeatherData.h"

bool WeatherData::AddSensor(std::unique_ptr<SensorIF> sensor) {
    if (sensor) {
        std::string name = sensor->GetSensorName();
        auto result = sensors.emplace(name, std::move(sensor));
        return result.second; // Returns true if the sensor was successfully added
    }
    return false; // Returns false if the sensor was null
}

bool WeatherData::RemoveSensor(const std::string& name) {
    return sensors.erase(name) > 0;
}

std::unique_ptr<SensorIF> WeatherData::GetSensor(const std::string& name) const {
    auto it = sensors.find(name);
    if (it != sensors.end()) {
        return it->second.get();
    }
    return nullptr;
}

std::vector<SensorIF*> WeatherData::GetAllSensors() const {
    std::vector<SensorIF*> sensorList;
    for (const auto& pair : sensors) {
        sensorList.push_back(pair.second.get());
    }
    return sensorList;
}