# RPi_WeatherStation
 PSU SWENG 452w Final Proejct

## How to run
I used Visual Studio Enterprise 2022 for my development. Due to this, you have to use cmake to compile and then transfer the program to the raspberry pi to run the program. It is not designed to run on anything that is not a Raspberry Pi. 

### Steps required to compile and transfer to your raspberry pi. 
For Ubuntu or Debian-based Linux:
1. sudo apt-get install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf
For RHEL-based Linux
2. sudo yum install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf
3.  Then update the toolchain-rpi.cmake file following the instructions below
4. # toolchain-rpi.cmake
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_VERSION 1)
SET(CMAKE_C_COMPILER /path/to/arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER /path/to/arm-linux-gnueabihf-g++)
SET(CMAKE_FIND_ROOT_PATH /path/to/arm-linux-gnueabihf)
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

4. from the directory the project is in:
5. mkdir build
6. cd build
7. cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain-rpi.cmake ..
8. make
This will make the program WeatherStation
9. Then you can run the program using ./WeatherStation from the directory you put it in on your Raspberry Pi.

## What Doesn't work:
Presently, the application runs but is not able to properly retrieve data over a standard network connection.
The conversion from metric to imperial units is not implemented. 
The Delete sensor feature is not working.

## What does work:
The program runs.
The add sensor feature works.
The start and stop collection features work, minus actually pulling the data from the sensors.
The exit program function works. 