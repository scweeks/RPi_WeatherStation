#ifndef SENSORIF_H
#define SENSORIF_H

#include <memory>
#include <string>
#include "SensorDataIF.h"

using namespace std;

class SensorIF {
public:
    virtual shared_ptr<SensorDataIF> GetData() const = 0;
    virtual string GetSensorType() const = 0;
    virtual bool OpenConnection(const std::string& address) = 0;
    virtual bool CloseConnection() = 0;
    virtual bool WriteSensorData(const std::string& data) = 0;
    virtual ~SensorIF() = default;
};

#endif // SENSORIF_H
