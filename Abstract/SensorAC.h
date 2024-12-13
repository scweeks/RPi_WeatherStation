#ifndef SENSORAC_H
#define SENSORAC_H

#include <memory>
#include <string>
#include "../Interfaces/SensorIF.h"
#include "../Interfaces/ConnectionIF.h"
#include "../Interfaces/SensorDataIF.h"

using namespace std;

class SensorAC : public SensorIF {
private:
    unique_ptr<SensorDataIF> Data;
    unique_ptr<ConnectionIF> Connection;
    string SensorType;
    string SensorName;

protected:
    // Protected setter for Data
    bool setData(std::unique_ptr<SensorDataIF> newData) {
        if (newData) {
            Data = std::move(newData);
            return true;
        }
        return false;
    }
    // Protected getter for Data
    SensorDataIF* getData() const {
        return Data.get();
    }

    // Protected setter for Connection
    bool setConnection(std::unique_ptr<ConnectionIF> newConnection) {
        if (newConnection) {
            Connection = std::move(newConnection);
            return true;
        }
        return false;
    }
    // Protected getter for Connection
    ConnectionIF* getConnection() const {
        return Connection.get();
    }

    // Protected setter for SensorType
    bool setType(const std::string& newSensorType) {
        SensorType = newSensorType;
        return true;
    }
    // Protected getter for SensorType
    std::string getType() const {
        return SensorType;
    }

    // Protected setter for SensorName
    bool setName(const std::string& newSensorName) {
        string originalSensorName = SensorName;
        SensorName = newSensorName;
        return SensorName != originalSensorName;
    }
    // Protected getter for SensorName
    std::string getName() const {
        return SensorName;
    }

public:
    SensorAC(std::string name) {
        setName(name);
    }

    SensorAC(std::string name, std::unique_ptr<SensorDataIF> data, std::unique_ptr<ConnectionIF> connection)
        : Data(std::move(data)), Connection(std::move(connection)) {
        setName(name);
    }

    virtual string GetSensorData() const = 0;
    virtual string GetSensorName() const = 0;
    virtual string GetSensorType() const = 0;
    virtual bool SetSensorName(const std::string& SensorName) = 0;
    virtual bool UpdateConnection(const std::string& address, int port) = 0;
    virtual ConnectionIF* GetConnection() const = 0; 
    virtual ~SensorAC() = default;
};

#endif // SENSORAC_H