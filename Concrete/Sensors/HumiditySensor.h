#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include "../../Abstract/SensorAC.h"
#include "../../Interfaces/SensorDataIF.h"
#include "../../Interfaces/ConnectionIF.h"

using namespace std;

class HumiditySensor : public SensorAC {
public:
    HumiditySensor() {
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
