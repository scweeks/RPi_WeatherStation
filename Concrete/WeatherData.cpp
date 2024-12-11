#include "WeatherData.h"
#include "SensorDataFactory.h" // Assuming this is the factory for creating sensors

bool WeatherData::AddSensor(SensorIF sensor) {
    if (sensors.push_back(sensor)) {
        return true;
    }
    return false;
}

bool WeatherData::DelSensor(int id) {
    auto it = std::remove_if(sensors.begin(), sensors.end(),
        [&name](const std::shared_ptr<SensorIF>& sensor) {
            return sensor->GetName() == name;
        });
    if (it != sensors.end()) {
        sensors.erase(it, sensors.end());
        return true;
    }
    return false;
}

std::shared_ptr<SensorIF> WeatherData::GetSensor(const std::string& name) const {
    for (const auto& sensor : sensors) {
        if (sensor->GetName() == name) {
            return sensor;
        }
    }
    return nullptr;
}