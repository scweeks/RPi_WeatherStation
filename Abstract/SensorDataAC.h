#ifndef ABSTRACT_SENSORDATAAC_H
#define ABSTRACT_SENSORDATAAC_H

#include "../Interfaces/SensorDataIF.h"

class SensorDataAC : public SensorDataIF {
protected:
    std::string data;

public:
    SensorDataAC() : data("") {}
    SensorDataAC(std::string data) : data(data) {}
    virtual ~SensorDataAC() = default;

    // Inherited via SensorDataIF
    std::string GetData() const override {
        return data;
    }
    // Inherited via SensorDataIF
    bool SetData(const std::string& newData) override {
        std::string oldData = data;
        data = newData;
        if (data != oldData) {
            return true;
        }
        return false;
    }
};

#endif // ABSTRACT_SENSORDATAAC_H
