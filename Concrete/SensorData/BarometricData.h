// BarometricData.h
#ifndef BAROMETRICDATA_H
#define BAROMETRICDATA_H

#include "../../Abstract/SensorDataAC.h"

using namespace std;

class BarometricData : public SensorDataAC {
public:
    string GetData() const override { return SensorDataAC::GetData(); }
    bool SetData(const string& data) override { return SensorDataAC::SetData(data); }
};

#endif // BAROMETRICDATA_H
