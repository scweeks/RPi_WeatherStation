#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H

#include <memory>
#include <string>
#include "../Interfaces/SensorIF.h"
#include "../Concrete/Sensors/WindSensor.h"
#include "../Concrete/Sensors/TempSensor.h"
#include "../Concrete/Sensors/HumiditySensor.h"
#include "../Concrete/Sensors/BarometricSensor.h"

class SensorFactory {
public:
    static std::unique_ptr<SensorIF> MakeSensor(const std::string& type, const std::string& name, const std::string& ipAddress, int port);
};

#endif // SENSORFACTORY_H