#ifndef SENSORIF_H
#define SENSORIF_H

#include <memory>
#include <string>
#include "../Interfaces/ConnectionIF.h"

class SensorIF {
public:
    virtual std::string GetSensorData() const = 0;
    virtual std::string GetSensorName() const = 0;
    virtual std::string GetSensorType() const = 0;
    virtual bool SetSensorName(const std::string& SensorName) = 0;
    virtual bool UpdateConnection(const std::string& address, int port) = 0;
    virtual ConnectionIF* GetConnection() const = 0;
    virtual ~SensorIF() = default;
};

#endif // SENSORIF_H
