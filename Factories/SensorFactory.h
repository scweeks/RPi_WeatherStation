#ifndef FACTORIES_SENSORFACTORY_H_
#define FACTORIES_SENSORFACTORY_H_

#include <memory>
#include <string>
#include "../Interfaces/SensorIF.h"
#include "../Concrete/Sensors/WindSensor.h"
#include "../Concrete/Sensors/TempSensor.h"
#include "../Concrete/Sensors/HumiditySensor.h"
#include "../Concrete/Sensors/BarometricSensor.h"
#include "../Concrete/Sensors/RainSensor.h"

using namespace std;

class SensorFactory {
public:
    // Create a new sensor object for the new sensor and set the connection details
    static unique_ptr<SensorIF> MakeSensor(const std::string& type, const string& name, const string& ipAddress, int port) {
        if (type == "Wind") return make_unique<WindSensor>(name, ipAddress, port);
        if (type == "Temp") return make_unique<TempSensor>(name, ipAddress, port);
        if (type == "Humidity") return make_unique<HumiditySensor>(name, ipAddress, port);
        if (type == "Barometric") return make_unique<BarometricSensor>(name, ipAddress, port);
        if (type == "Rain") return make_unique<RainSensor>(name, ipAddress, port);
        return nullptr;
    }
};

#endif /* FACTORIES_SENSORFACTORY_H_ */
