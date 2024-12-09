#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

// Include the required headers for all sensor classes
#include "../../Concrete/Sensors/SensorIncludes.h"

using namespace std;

class HumiditySensor : public SensorAC {
public:
    HumiditySensor(const std::string& name)
        : SensorAC(name) {
        // Initialize unique attributes for BarometricSensor
        setData(std::make_shared<SensorDataIF>());
        setConnection(std::make_shared<Ethernet>());
        setType("Humidity");
        setName(name);
    }


    HumiditySensor(const std::string name, const std::string& ipAddress, int port)
        : SensorAC(name, nullptr, nullptr) {
        // Initialize unique attributes for BarometricSensor
        setData(std::make_shared<SensorDataIF>());
        setConnection(std::make_shared<Ethernet>(ipAddress, port));
        setType("Humidity");
        setName(name);
    }

    std::string GetSensorData() const override {
        return getData()->GetData();
    }

    std::string GetSensorType() const override {
        return getType();
    }

    bool SetSensorName(const std::string& sensorName) override {
        setName(sensorName);
        return true;
    }

    std::string GetSensorName() const override {
        return getName();
    }

    bool UpdateConnection(const std::string& address, int port) override {
        return getConnection()->UpdateConnection(address, port);
    }
};

#endif // HUMIDITYSENSOR_H
