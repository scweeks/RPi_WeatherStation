#ifndef CONNECTIONIF_H
#define CONNECTIONIF_H

#include <string>

class ConnectionIF {
public:
    virtual bool UpdateConnection(const std::string& ipAddress, int port) = 0;
    virtual std::string RetrieveData() = 0;
    virtual ~ConnectionIF() = default;
};

#endif // CONNECTIONIF_H