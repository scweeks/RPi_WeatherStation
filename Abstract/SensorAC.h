#ifndef ABSTRACT_SENSORAC_H
#define ABSTRACT_SENSORAC_H

#include <memory>
#include <string>
#include "../Concrete/Connections/Ethernet.h"
#include "../Factories/ConnectionFactory.h"
#include "../Interfaces/SensorIF.h"
#include "../Interfaces/ConnectionIF.h"
#include "../Interfaces/SensorDataIF.h"
#include "../Factories/SensorDataFactory.h"

class SensorAC : public SensorIF {
private:
    std::unique_ptr<SensorDataIF> Data;
    std::unique_ptr<ConnectionIF> Connection;
    std::string SensorType;
    std::string SensorName;

protected:
    bool setData(std::unique_ptr<SensorDataIF> newData) {
        if (newData) {
            Data = std::move(newData);
            return true;
        }
        return false;
    }

    SensorDataIF* getData() const {
        return Data.get();
    }

    bool setConnection(std::unique_ptr<ConnectionIF> newConnection) {
        if (newConnection) {
            Connection = std::move(newConnection);
            return true;
        }
        return false;
    }

    ConnectionIF* getConnection() const {
        return Connection.get();
    }

    bool setType(const std::string& newSensorType) {
        SensorType = newSensorType;
        return true;
    }

    std::string getType() const {
        return SensorType;
    }

    bool setName(const std::string& newSensorName) {
        SensorName = newSensorName;
        return true;
    }

    std::string getName() const {
        return SensorName;
    }

public:
    SensorAC(std::string& name)
        : SensorName(std::move(name)) {
        setData(SensorDataFactory::createSensorData("Sensor"));
        this->setConnection(ConnectionFactory::createConnection("Ethernet", "127.0.0.1", 0));
    }

    SensorAC(const std::string& name, const std::string& connType, const std::string& dataType)
        : SensorName(std::move(name))
    {
    	setData(SensorDataFactory::createSensorData(dataType));
		setConnection(ConnectionFactory::createConnection(connType, "127.0.0.1", 0));
    }

    SensorAC(const std::string& name, const std::string& connType, const std::string& dataType,
        const std::string& address, const int port)
        : SensorName(std::move(name))
    {
        setData(SensorDataFactory::createSensorData(dataType));
        setConnection(ConnectionFactory::createConnection(connType, address, port));
    }

    virtual std::string GetSensorData() const = 0;
    virtual std::string GetSensorName() const = 0;
    virtual std::string GetSensorType() const = 0;
    virtual bool SetSensorName(const std::string& SensorName) = 0;
    virtual bool UpdateConnection(const std::string& address, int port) = 0;
    virtual ConnectionIF* GetConnection() const = 0;
    virtual ~SensorAC() = default;
};

#endif // ABSTRACT_SENSORAC_H
