#ifndef TEMPDATA_H
#define TEMPDATA_H

#include "../../Abstract/SensorDataAC.h"

using namespace std;

class TempData : public SensorDataAC {
public:
    string GetData() const override { return SensorDataAC::GetData(); }
    bool SetData(const string& data) override { return SensorDataAC::SetData(data); }
};

#endif // TEMPDATA_H
