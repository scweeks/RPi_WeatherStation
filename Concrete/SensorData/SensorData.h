#ifndef WINDDATA_H
#define WINDDATA_H

#include "../Abstract/SensorDataAC.h"

using namespace std;

class WindData : public SensorDataAC {
public:
    string GetData() const override { return SensorDataAC::GetData(); }
    bool SetData(const string& Data) override { return SensorDataAC::SetData(Data); }
};

#endif // WINDDATA_H