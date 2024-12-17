#ifndef FACTORIES_SENSORFACTORY_H_
#define FACTORIES_SENSORFACTORY_H_


#include <memory>
#include <string>
#include "../Interfaces/SensorIF.h"
#include "../Concrete/Sensors/WindSensor.h"
#include "../Concrete/Sensors/TempSensor.h"
#include "../Concrete/Sensors/HumiditySensor.h"
#include "../Concrete/Sensors/BarometricSensor.h"
#include "../Concrete/Sensors/RainSensor.h"

class SensorFactory {
public:
	// Create a new sensor object for the new sensor and set the connection details
	static std::unique_ptr<SensorIF> MakeSensor(const std::string& type,
		const std::string& name, const std::string& connType,
		const std::string& dataType, const std::string& ipAddress, int port) {
		if (type == "Wind") return std::make_unique<WindSensor>(name, connType, dataType, ipAddress, port);
		if (type == "Temp") return std::make_unique<TempSensor>(name, connType, dataType, ipAddress, port);
		if (type == "Humidity") return std::make_unique<HumiditySensor>(name, connType, dataType, ipAddress, port);
		if (type == "Barometric") return std::make_unique<BarometricSensor>(name, connType, dataType, ipAddress, port);
		if (type == "Rain") return std::make_unique<RainSensor>(name, connType, dataType, ipAddress, port);
		return nullptr;
	}
};

#endif /* FACTORIES_SENSORFACTORY_H_ */
