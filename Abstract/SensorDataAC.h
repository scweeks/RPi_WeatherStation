#ifndef SensorDataAC_H
#define SensorDataAC_H

#include <string>
#include "../Interfaces/SensorDataIF.h"

using namespace std;

class SensorDataAC : public SensorDataIF {
private:
    string data;
protected:
    // Protected getter and setter for data
    bool SetData(const string& data) override { this->data = data; return true; }
    string GetData() const override { return this->data; }
public:
    virtual string GetData() const = 0;
    virtual bool SetData(const string& data) = 0;
    virtual ~SensorDataIF() = default;
};


#endif // SensorDataAC_H