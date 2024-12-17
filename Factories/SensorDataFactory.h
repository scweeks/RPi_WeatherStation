#ifndef FACTORIES_SENSORDATAFACTORY_H_
#define FACTORIES_SENSORDATAFACTORY_H_

#include <memory>
#include <string>
#include "../Concrete/SensorData/SensorData.h"

class SensorDataFactory {
public:
    //Create a new sensor data object for the new sensor
    static std::unique_ptr<SensorDataIF> createSensorData(const std::string& type) {
        if (type == "Sensor") { return std::make_unique<SensorData>(); }
        return nullptr;
    }
};

#endif /* FACTORIES_SENSORDATAFACTORY_H_ */
