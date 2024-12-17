#ifndef INTERFACES_SENSORDATAIF_H_
#define INTERFACES_SENSORDATAIF_H_

#include <string>

class SensorDataIF {
public:
    virtual ~SensorDataIF() = default;
    // Get the data from the sensor
    virtual std::string GetData() const = 0;
    // Set the data for the sensor
    virtual bool SetData(const std::string& data) = 0;
};

#endif /* INTERFACES_SENSORDATAIF_H_ */
