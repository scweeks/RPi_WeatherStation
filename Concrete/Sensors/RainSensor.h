#ifndef RAINSENSOR_H
#define RAINSENSOR_H

// Include the required headers for all sensor classes
#include "../../Concrete/Sensors/SensorIncludes.h"

using namespace std;

class RainSensor : public SensorAC {
public:
    RainSensor(const std::string& ipAddress, int port)
        : SensorAC(nullptr, nullptr) {
        // Initialize unique attributes for HumiditySensor
        setData(std::make_shared<SensorDataIF>());
        setConnection(std::make_shared<Ethernet>(ipAddress, port));
        setType("Rain");
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

#endif // RAINSENSOR_H
