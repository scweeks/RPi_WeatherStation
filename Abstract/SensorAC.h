#ifndef SENSORAC_H
#define SENSORAC_H

#include <memory>
#include <string>
#include "../Interfaces/SensorIF.h"
#include "../Interfaces/ConnectionIF.h"

using namespace std;

class SensorAC : public SensorIF {
private:
    shared_ptr<SensorDataIF> data;
    shared_ptr<ConnectionIF> connection;
    string sensorType;

protected:
    // Protected getter and setter for data
    void setData(shared_ptr<SensorDataIF> newData) {
        data = newData;
    }

    shared_ptr<SensorDataIF> getData() const {
        return data;
    }

    // Protected getter and setter for connection
    void setConnection(shared_ptr<ConnectionIF> newConnection) {
        connection = newConnection;
    }

    shared_ptr<ConnectionIF> getConnection() const {
        return connection;
    }

    // Protected getter and setter for sensorType
    void setSensorType(const string& newSensorType) {
        sensorType = newSensorType;
    }

    string getSensorType() const {
        return sensorType;
    }

public:
    virtual shared_ptr<SensorDataIF> GetData() const = 0;
    virtual string GetSensorType() const = 0;
    virtual bool OpenConnection(const std::string& address) = 0;
    virtual bool WriteSensorData(const std::string& data) = 0;
    virtual bool CloseConnection() = 0;
    virtual ~SensorAC() = default;
};

#endif // SENSORAC_H