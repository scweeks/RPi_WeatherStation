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
    shared_ptr<SensorDataIF> Data;
    shared_ptr<ConnectionIF> Connection;
    string SensorType;
    string SensorName;

protected:
    // Protected setter for Data
    bool setData(std::shared_ptr<SensorDataIF> newData) {
        //Data = newData;
        if (Data = newData)
            return true;
        return false;
    }
    // Protected getter for Data
    std::shared_ptr<SensorDataIF> getData() const {
        return Data;
    }

    // Protected setter for Connection
    bool setConnection(std::shared_ptr<ConnectionIF> newConnection) {
        if (Connection = newConnection)
            return true;
        return false;
    }
    // Protected getter for Connection
    std::shared_ptr<ConnectionIF> getConnection() const {
        return Connection;
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
        if (SensorName == originalSensorName)
			return false;
        return true;
    }
    // Protected getter for SensorName
    std::string getName() const {
        return SensorName;
    }

public:
    SensorAC(std::shared_ptr<SensorDataIF> data, std::shared_ptr<ConnectionIF> connection)
        : Data(data), Connection(connection) {}
    virtual string GetSensorData() const = 0;
    virtual string GetSensorName() const = 0;
    virtual string GetSensorType() const = 0;
    virtual bool SetSensorName(const std::string& SensorName) = 0;
    virtual bool UpdateConnection(const std::string& address, int port) = 0;
    virtual ~SensorAC() = default;
};

#endif // SENSORAC_H