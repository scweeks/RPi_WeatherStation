#ifndef SENSORIF_H
#define SENSORIF_H

#include <memory>
#include <string>
#include "../Concrete/SensorData.h"

class SensorIF {
public:
    virtual string GetSensorData() const = 0;
    virtual string GetSensorName() const = 0;
    virtual string GetSensorType() const = 0;
    virtual bool SetSensorName(const std::string& SensorName) = 0;
    virtual bool UpdateConnection(const std::string& address, int port) = 0;
    virtual ~SensorIF() = default;
};

#endif // SENSORIF_H
