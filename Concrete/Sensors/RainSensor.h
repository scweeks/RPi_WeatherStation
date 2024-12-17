#ifndef CONCRETE_SENSORS_RAINSENSOR_H_
#define CONCRETE_SENSORS_RAINSENSOR_H_

// Include the required headers for all sensor classes
#include "../../Concrete/Sensors/SensorIncludes.h"

class RainSensor : public SensorAC {
public:
    RainSensor(const std::string& name, const std::string& connType,
        const std::string& dataType, const std::string& ipAddress, int port)
        : SensorAC(name, connType, dataType, ipAddress, port) {
        // Initialize unique attributes for WindSensor
        setType("Rain");
    }

    std::string GetSensorData() override {
        return getData()->GetData();
    }

    std::string GetSensorType() override {
        return getType();
    }

    bool SetSensorName(const std::string& sensorName) override {
        setName(sensorName);
        return true;
    }

    std::string GetSensorName() override {
        return getName();
    }

    bool UpdateSensorConnection(const std::string& address, int port) override {
        return getConnection()->UpdateConnection(address, port);
    }
};

#endif /* CONCRETE_SENSORS_RAINSENSOR_H_ */
