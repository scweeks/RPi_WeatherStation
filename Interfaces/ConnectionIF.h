#ifndef INTERFACES_CONNECTIONIF_H_
#define INTERFACES_CONNECTIONIF_H_

#include <string>

class ConnectionIF {
public:
    virtual bool UpdateConnection(const std::string& ipAddress, int port) = 0;
    virtual std::string GetIpAddress() = 0;
    virtual int GetPort() = 0;
    virtual std::string RetrieveData() = 0;
    virtual ~ConnectionIF() = default;
    virtual ConnectionIF* Get() = 0;
};

#endif /* INTERFACES_CONNECTIONIF_H_ */
