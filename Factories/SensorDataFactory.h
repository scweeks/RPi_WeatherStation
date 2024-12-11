#ifndef SENSORDATAFACTORY_H
#define SENSORDATAFACTORY_H

#include <memory>
#include <string>
#include "../Interfaces/SensorDataIF.h"
#include "../Concrete/SensorData/WindData.h"
#include "../Concrete/SensorData/TempData.h"
#include "../Concrete/SensorData/HumidityData.h"
#include "../Concrete/SensorData/BarometricData.h"

class SensorDataFactory {
public:
    static std::shared_ptr<SensorDataIF> createSensorData(const std::string& type) {
        if (type == "Barometric") { return std::make_shared<BarometricData>(); }
        if (type == "Humidity") { return std::make_shared<HumidityData>(); }
        if (type == "Wind") { return std::make_shared<WindData>(); }
        if (type == "Temp") { return std::make_shared<TempData>(); }
        return nullptr;
    }
};

#endif // SENSORDATAFACTORY_H