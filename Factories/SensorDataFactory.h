#ifndef SENSORDATAFACTORY_H
#define SENSORDATAFACTORY_H

#include <memory>
#include <string>
#include "../Interfaces/SensorDataIF.h"
#include "../Concrete/SensorData/WindData.h"
#include "../Concrete/SensorData/TempData.h"
// Include other SensorDataAC derived classes as needed

class SensorDataFactory {
public:
    static std::shared_ptr<SensorDataIF> createSensorData(const std::string& type) {
        if (type == "Wind") { return std::make_shared<WindData>(); }
        if (type == "Temp") { return std::make_shared<TempData>(); }
        return nullptr;
    }
};

#endif // SENSORDATAFACTORY_H