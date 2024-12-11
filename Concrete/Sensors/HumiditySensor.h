#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

// Include the required headers for all sensor classes
#include "../Sensors/Sensors.h"

using namespace std;

class HumiditySensor : public SensorAC {
public:
    HumiditySensor()
        : SensorAC(std::make_unique<SensorData>(), std::make_unique<Ethernet>(ipAddress, port)) {
        // Initialize unique attributes for HumiditySensor
        setSensorType("Humidity");
        setData(make_shared<SensorData>());
        setConnection(make_shared<Connection>());
    }

    shared_ptr<SensorDataIF> GetData() const override {
        return getData();
    }

    string GetSensorType() const override {
        return getSensorType();
    }

    bool OpenConnection(const std::string& address) override {
        return getConnection()->open(address);
    }

    bool WriteSensorData(const std::string& Data) override {
        return getConnection()->write(Data);
    }

    bool CloseConnection() override {
        return getConnection()->close();
    }
};

#endif // HUMIDITYSENSOR_H
