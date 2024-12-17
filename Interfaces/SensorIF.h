#ifndef INTERFACES_SENSORIF_H_
#define INTERFACES_SENSORIF_H_

#include <memory>
#include <string>
#include "../Interfaces/ConnectionIF.h"

class SensorIF {
public:
    virtual std::string GetSensorData() = 0;
    virtual std::string GetSensorName() = 0;
    virtual std::string GetSensorType() = 0;
    virtual bool SetSensorName(const std::string& SensorName) = 0;
    virtual bool UpdateSensorConnection(const std::string& address, int port) = 0;
    virtual ConnectionIF* GetConnection() = 0;
    virtual ~SensorIF() = default;
};

#endif /* INTERFACES_SENSORIF_H_ */
