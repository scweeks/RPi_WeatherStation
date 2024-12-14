#ifndef BAROMETRICSENSOR_H
#define BAROMETRICSENSOR_H

// Include the required headers for all sensor classes
#include "../../Concrete/Sensors/SensorIncludes.h"

class BarometricSensor : public SensorAC {
public:
    BarometricSensor(const std::string name, const std::string& ipAddress, int port)
        : SensorAC(name, nullptr, nullptr) {
        // Initialize unique attributes for BarometricSensor
        setData(std::make_unique<SensorDataIF>());
        setConnection(std::make_unique<Ethernet>(ipAddress, port));
        setType("Barometric");
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

    virtual ConnectionIF* GetConnection() const override {
        return getConnection();
    }
};

#endif // BAROMETRICSENSOR_H