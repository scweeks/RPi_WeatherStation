#ifndef SENSORDATAIF_H
#define SENSORDATAIF_H

#include <string>

using namespace std;

class SensorDataIF {
public:
    virtual std::string GetData() const = 0;
    virtual bool SetData(const std::string& Data) = 0;
    virtual ~SensorDataIF() = default;
};

#endif // SENSORDATAIF_H
