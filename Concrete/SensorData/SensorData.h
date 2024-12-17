#ifndef CONCRETE_SENSORDATA_SENSORDATA_H_
#define CONCRETE_SENSORDATA_SENSORDATA_H_

#include "../../Abstract/SensorDataAC.h"

class SensorData : public SensorDataAC {
public:
    SensorData() : SensorDataAC() {}
    SensorData(const std::string& Data) : SensorDataAC(Data) {}
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

#endif /* CONCRETE_SENSORDATA_SENSORDATA_H_ */
