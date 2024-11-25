#ifndef WINDSENSOR_H
#define WINDSENSOR_H

#include "../../Abstract/SensorAC.h"
#include "../../Interfaces/SensorDataIF.h"
#include "../../Interfaces/ConnectionIF.h"

using namespace std;

class WindSensor : public SensorAC {
public:
    WindSensor() {
        // Initialize unique attributes for WindSensor
        setSensorType("Wind");
        setData(make_shared<SensorDataIF>());
        setConnection(make_shared<ConnectionIF>());
    }

    shared_ptr<SensorDataIF> GetData() const override {
        return getData();
    }

    string GetSensorType() const override {
        return getSensorType();
    }

    bool OpenConnection(const std::string& address) override {
        // Implementation for opening connection
        return true;
    }

    bool WriteSensorData(const std::string& data) override {
        // Implementation for writing sensor data
        return true;
    }

    bool CloseConnection() override {
        // Implementation for closing connection
        return true;
    }
};
#endif // WINDSENSOR_H