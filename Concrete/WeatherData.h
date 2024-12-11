#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <vector>
#include "../Interfaces/SensorIF.h"

class WeatherData {
private:
    std::vector<SensorIF> Sensors;
public:
    bool AddSensor(SensorIF sensor);
    bool DelSensor(SensorIF sensor);
    SensorIF GetSensor(const int index) const;
};

#endif // WEATHERDATA_H