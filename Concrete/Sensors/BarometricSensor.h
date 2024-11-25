#ifndef BAROMETRICSENSOR_H
#define BAROMETRICSENSOR_H

#include "../../Abstract/SensorAC.h"
#include "../../Interfaces/SensorDataIF.h"
#include "../../Interfaces/ConnectionIF.h"

using namespace std;

class BarometricSensor : public SensorAC {
public:
    BarometricSensor() {
        // Initialize unique attributes for BarometricSensor
        setSensorType("Barometric");
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

    bool WriteSensorData(const std::string& data) override {
        return getConnection()->write(data);
    }

    bool CloseConnection() override {
        return getConnection()->close();
    }
};

#endif // BAROMETRICSENSOR_H
