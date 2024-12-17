# CMakeList.txt : CMake project for WeatherStation, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("WeatherStation")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/Abstract)
include_directories(${PROJECT_SOURCE_DIR}/Interfaces)
include_directories(${PROJECT_SOURCE_DIR}/Concrete)
include_directories(${PROJECT_SOURCE_DIR}/Managers)
include_directories(${PROJECT_SOURCE_DIR}/Factories)

# Add source to this project's executable.
add_executable (WeatherStation 
  "WeatherStation.cpp" 
  "WeatherStation.h" 
  "Interfaces/SensorIF.h" 
  "Interfaces/SensorDataIF.h" 
  "Interfaces/ConnectionIF.h" 
  "Concrete/Sensors/WindSensor.h" 
  "Concrete/SensorData/SensorData.h"  
  "Abstract/SensorDataAC.h" 
  "Factories/SensorFactory.h" 
  "Concrete/WeatherData.cpp"  # Ensure this file is included
  "Concrete/WeatherData.h" 
  "Managers/ConnectionServer.h"  
  "Concrete/Connections/Ethernet.h" 
  "Concrete/Sensors/SensorIncludes.h" 
  "Concrete/Sensors/RainSensor.h" 
  "Managers/SensorManager.cpp" 
  "Factories/SensorFactory.h" 
  "Factories/ConnectionFactory.h"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET WeatherStation PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.