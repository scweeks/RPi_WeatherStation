#ifndef WINDSENSOR_H
#define WINDSENSOR_H

// Include the required headers for all sensor classes
#include "../../Concrete/Sensors/SensorIncludes.h"

using namespace std;

class WindSensor : public SensorAC {
public:
    WindSensor() 
        : SensorAC(std::make_unique<SensorData>(), std::make_unique<Ethernet>(ipAddress, port)) {
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
        // Implementation for opening Connection
        return true;
    }

    bool WriteSensorData(const std::string& Data) override {
        // Implementation for writing sensor Data
        return true;
    }

    bool CloseConnection() override {
        // Implementation for closing Connection
        return true;
    }
};
#endif // WINDSENSOR_H