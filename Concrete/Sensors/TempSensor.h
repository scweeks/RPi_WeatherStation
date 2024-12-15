#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

// Include the required headers for all sensor classes
#include "../../Concrete/Sensors/SensorIncludes.h"

using namespace std;

class TempSensor : public SensorAC {
public:
    TempSensor(const std::string name, const std::string connType,
        const std::string& ipAddress, int port)
        : SensorAC(name, connType) {
        // Initialize unique attributes for WindSensor
        setData(std::make_unique<SensorData>());
        setConnection(ConnectionFactory::createConnection(connType, ipAddress, port));
        setType("Temp");
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

#endif // TEMPSENSOR_H
