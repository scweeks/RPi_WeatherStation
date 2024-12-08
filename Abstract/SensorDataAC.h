#ifndef SENSORDATAAC_H
#define SENSORDATAAC_H

#include <string>
#include "../Interfaces/SensorDataIF.h"

using namespace std;

class SensorDataAC : public SensorDataIF {
private:
    string data;
protected:
    // Protected getter and setter for data
    bool SetData(const string& data) { this->data = data; return true; }
    string GetData() const { return this->data; }
public:
    virtual string GetData() const = 0;
    virtual bool SetData(const string& data) = 0;
    virtual ~SensorDataAC() = default;
};

#endif // SENSORDATAAC_H