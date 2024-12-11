#ifndef SENSORDATA_H
#define SENSORDATA_H

#include "../../Abstract/SensorDataAC.h"

class SensorData : public SensorDataAC {
public:
    SensorData(std::string Data) : SensorDataAC(Data) {}
    // Inherited via SensorDataAC
    std::string GetData() const override 
    { 
        return SensorDataAC::GetData(); 
    }

    // Inherited via SensorDataAC
    bool SetData(const std::string& Data) override 
    { 
        return SensorDataAC::SetData(Data); 
    }
};

#endif // SENSORDATA_H