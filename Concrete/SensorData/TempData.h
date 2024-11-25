#ifndef TEMPDATA_H
#define TEMPDATA_H

#include "../../Interfaces/SensorDataIF.h"

using namespace std;

class TempData : public SensorDataAC {
public:
    string GetData() const override { return data; }
    bool SetData(const std::string& data) override { this->data = data; return true; }
};

#endif // TEMPDATA_H
