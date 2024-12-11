#ifndef SENSORS_H
#define SENSORS_H

// Include the abstract base class for sensors
#include "../../Abstract/SensorAC.h"

// Include the interface for sensor data
#include "../../Interfaces/SensorDataIF.h"

// Include the interface for connections
#include "../../Interfaces/ConnectionIF.h"

// Include concrete implementations of sensor data
#include "../../Concrete/SensorData.h"

// Include concrete implementations of connections
#include "../../Concrete/Connections/Ethernet.h"

// Add other concrete sensor includes as needed
#include "../../Concrete/Sensors/BarometricSensor.h"
#include "../../Concrete/Sensors/HumiditySensor.h"
#include "../../Concrete/Sensors/TempSensor.h"
#include "../../Concrete/Sensors/WindSensor.h"

#endif // SENSORS_H