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
    static std::shared_ptr<SensorIF> MakeSensor(const std::string& type, string ipAddress, int port) {
        if (type == "Wind") return make_shared<WindSensor>(ipAddress, port);
        if (type == "Temp") return make_shared<TempSensor>(ipAddress, port);
        if (type == "Humidity") return make_shared<HumiditySensor>(ipAddress, port);
        if (type == "Barometric") return make_shared<BarometricSensor>(ipAddress, port);
        if (type == "Rain") return make_shared<BarometricSensor>(ipAddress, port);
        return nullptr;
    }

    // Overloaded method to create a sensor with only a name
    static std::shared_ptr<SensorIF> MakeSensor(const std::string& type) {
        if (type == "Wind") return make_shared<WindSensor>();
        if (type == "Temp") return make_shared<TempSensor>();
        if (type == "Humidity") return make_shared<HumiditySensor>();
        if (type == "Barometric") return make_shared<BarometricSensor>();
        if (type == "Rain") return make_shared<BarometricSensor>();
        return nullptr;
    }
};

#endif // SENSORFACTORY_H
