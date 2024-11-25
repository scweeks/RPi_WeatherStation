#ifndef WINDDATA_H
#define WINDDATA_H

#include "../../Abstract/SensorDataAC.h"

using namespace std;

class WindData : public SensorDataAC {
public:
    // 
    string GetData() const override { return this->GetData(); }
    bool SetData(const string& data) override { return this->SetData(data); }
};

#endif // WINDDATA_H
