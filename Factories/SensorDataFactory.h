#ifndef SENSORDATAFACTORY_H
#define SENSORDATAFACTORY_H

#include <memory>
#include <string>
#include "../../Interfaces/SensorDataIF.h"
#include "../../Concrete/SensorData/SensorData.h"

class SensorDataFactory {
public:
    //Create a new sensor data object for the new sensor
    static std::unique_ptr<SensorDataIF> createSensorData(const std::string& type) {
        if (type == "Sensor") { return std::make_unique<SensorData>(); }
        return nullptr;
    }
};

#endif // SENSORDATAFACTORY_H