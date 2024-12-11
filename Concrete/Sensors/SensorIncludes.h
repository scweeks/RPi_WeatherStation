#ifndef SENSORSINCLUDES_H
#define SENSORSINCLUDES_H

// Include the abstract base class for sensors
#include "../../Abstract/SensorAC.h"

// Include the interface for sensor data
#include "../../Interfaces/SensorDataIF.h"

// Include the interface for connections
#include "../../Interfaces/ConnectionIF.h"

// Include concrete implementations of sensor data
#include "../../Concrete/SensorData/SensorData.h"

// Include concrete implementations of connections
#include "../../Concrete/Connections/Ethernet.h"

#endif // SENSORSINCLUDES_H