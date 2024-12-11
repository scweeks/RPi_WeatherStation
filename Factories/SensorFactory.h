#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H

#include <memory>
#include <string>
#include "../Interfaces/SensorIF.h"
#include "../Concrete/Sensors/WindSensor.h"
#include "../Concrete/Sensors/TempSensor.h"
#include "../Concrete/Sensors/HumiditySensor.h"
#include "../Concrete/Sensors/BarometricSensor.h"

using namespace std;

class SensorFactory {
public:
    // Create a new sensor object for the new sensor and set the connection details
    static std::shared_ptr<SensorIF> MakeSensor(const std::string& type, string name, string ipAddress, int port) {
        if (type == "Wind") return make_shared<WindSensor>(name, ipAddress, port);
        if (type == "Temp") return make_shared<TempSensor>(name, ipAddress, port);
        if (type == "Humidity") return make_shared<HumiditySensor>(name, ipAddress, port);
        if (type == "Barometric") return make_shared<BarometricSensor>(name, ipAddress, port);
        if (type == "Rain") return make_shared<BarometricSensor>(name, ipAddress, port);
        return nullptr;
    }

    // Overloaded method to create a sensor with only a name
    static std::shared_ptr<SensorIF> MakeSensor(const std::string& type, string name) {
        if (type == "Wind") return make_shared<WindSensor>(name);
        if (type == "Temp") return make_shared<TempSensor>(name);
        if (type == "Humidity") return make_shared<HumiditySensor>(name);
        if (type == "Barometric") return make_shared<BarometricSensor>(name);
        if (type == "Rain") return make_shared<BarometricSensor>(name);
        return nullptr;
    }
};

#endif // SENSORFACTORY_H
