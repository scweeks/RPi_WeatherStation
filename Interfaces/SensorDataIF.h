#ifndef SENSORDATAIF_H
#define SENSORDATAIF_H

#include <string>

class SensorDataIF {
public:
    virtual ~SensorDataIF() = default;
    virtual std::string GetData() const = 0;
    virtual void SetData(const std::string& data) = 0;
};

#endif // SENSORDATAIF_H