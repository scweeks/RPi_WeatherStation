#ifndef FACTORIES_CONNECTIONFACTORY_H_
#define FACTORIES_CONNECTIONFACTORY_H_

#include <memory>
#include <string>
#include "../Concrete/Connections/Ethernet.h"
#include "../Interfaces/SensorDataIF.h"
#include "../Concrete/SensorData/SensorData.h"
#include "../Interfaces/ConnectionIF.h"

class ConnectionFactory {
public:
    //Create a new sensor data object for the new sensor
    static std::unique_ptr<ConnectionIF> createConnection(const std::string& type, 
        const std::string& address, const int port) {
        if (type == "Ethernet") { return std::make_unique<Ethernet>(address, port); }
        return nullptr;
    }
};

#endif /* FACTORIES_CONNECTIONFACTORY_H_ */
