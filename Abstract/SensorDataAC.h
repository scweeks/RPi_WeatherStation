#ifndef SENSORDATAAC_H
#define SENSORDATAAC_H

#include <string>
#include "../Interfaces/SensorDataIF.h"

using namespace std;

class SensorDataAC : public SensorDataIF {
private:
    string Data;
protected:
    // Protected getter and setter for Data
    bool SetData(const string& Data) { this->Data = Data; return true; }
    string GetData() const { return this->Data; }
};

#endif // SENSORDATAAC_H