#ifndef WINDDATA_H
#define WINDDATA_H

#include "../../Abstract/SensorDataAC.h"

using namespace std;

class WindData : public SensorDataAC {
public:
    string GetData() const override { return SensorDataAC::GetData(); }
    bool SetData(const string& data) override { return SensorDataAC::SetData(data); }
};

#endif // WINDDATA_H