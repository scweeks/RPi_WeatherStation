// WEATHERSTATION_H : Include file for standard system include files,
// or project specific include files.

#pragma once
// File:  WEATHERSTATION_H
#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H

#include <iostream>
#include "Interfaces/SensorIF.h"
#include "Interfaces/SensorDataIF.h"
#include "Interfaces/ConnectionIF.h"
#include "Concrete/Sensors/WindSensor.h"
#include "Concrete/SensorData/SensorData.h"
#include "Abstract/SensorDataAC.h"
#include "Factories/SensorFactory.h"
#include "Concrete/WeatherData.h"
#include "Managers/ConnectionServer.h"
#include "Concrete/Connections/Ethernet.h"
#include "Concrete/Sensors/SensorIncludes.h"
#include "Concrete/Sensors/RainSensor.h"
#include "Managers/SensorManager.h"
#include "Factories/ConnectionFactory.h"


#endif // WEATHERSTATION_H
