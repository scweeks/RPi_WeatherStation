#ifndef SENSORDATA_H
#define SENSORDATA_H

#include "../../Abstract/SensorDataAC.h"

class SensorData : public SensorDataAC {
public:
    SensorData() : SensorDataAC() {}
    SensorData(const std::string& Data) : SensorDataAC(Data) {}
    // Return the data stored in the sensor
    std::string GetData() const override 
    { 
        return SensorDataAC::GetData(); 
    }
    // Set the data stored in the sensor
    bool SetData(const std::string& Data) override 
    { 
        return SensorDataAC::SetData(Data); 
    }
};

#endif // SENSORDATA_H