// HumidityData.h
#ifndef HUMIDITYDATA_H
#define HUMIDITYDATA_H

#include "../../Abstract/SensorDataAC.h"

using namespace std;

class HumidityData : public SensorDataAC {
public:
    string GetData() const override { return SensorDataAC::GetData(); }
    bool SetData(const string& data) override { return SensorDataAC::SetData(data); }
};

#endif // HUMIDITYDATA_H
