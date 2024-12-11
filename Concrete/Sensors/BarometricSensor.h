#ifndef BAROMETRICSENSOR_H
#define BAROMETRICSENSOR_H

// Include the required headers for all sensor classes
#include "../../Concrete/Sensors/SensorIncludes.h"

class BarometricSensor : public SensorAC {
public:
    BarometricSensor(const std::string& ipAddress, int port)
        : SensorAC(std::make_shared<SensorData>(), std::make_shared<Ethernet>(ipAddress, port)) {
        // Initialize unique attributes for BarometricSensor
        setSensorType("Barometric");
    }

    std::string GetSensorData() const override {
        return getSensorData()->GetData();
    }

    std::string GetSensorType() const override {
        return getSensorType();
    }

    bool SetSensorName(const std::string& sensorName) override {
        setSensorName(sensorName);
        return true;
    }

    std::string GetSensorName() const override {
        return getSensorName();
    }

    bool UpdateConnection(const std::string& address, int port) override {
        return getConnection()->UpdateConnection(address, port);
    }
};

#endif // BAROMETRICSENSOR_H