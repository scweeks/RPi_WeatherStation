#ifndef BAROMETRICSENSOR_H
#define BAROMETRICSENSOR_H

// Include the required headers for all sensor classes
#include "../Sensors/Sensors.h"

using namespace std;

class BarometricSensor : public SensorAC {
public:
    BarometricSensor() 
        : SensorAC(std::make_unique<SensorData>(), std::make_unique<Ethernet>(ipAddress, port)) {
        // Initialize unique attributes for BarometricSensor
        setSensorType("Barometric");
        setData(make_shared<SensorDataIF>());
        setConnection(make_shared<ConnectionIF>());
    }

    string GetSensorData() const override {
        this->getData()->SetData( this->getConnection()->RetrieveData() );
        return this->getData()->GetData();
    }

    string GetSensorType() const override {
        return getSensorType();
    }

    bool SetSensorName(const std::string& SensorName) override {
        if (setSensorName(SensorName))
            return true;
		return false;
	}

    string GetSensorName() const override {
		return this->GetSensorName();
	}

    virtual bool UpdateConnection(const std::string& address, int port) override {
		return this->getConnection()->UpdateConnection(address, port);
	}
};

#endif // BAROMETRICSENSOR_H
