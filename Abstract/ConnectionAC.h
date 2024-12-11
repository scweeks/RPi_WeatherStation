#ifndef CONNECTIONAC_H
#define CONNECTIONAC_H

#include "ConnectionIF.h"

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <netinet/in.h> // For sockaddr_in
#include <unistd.h>     // For close
#endif

class ConnectionAC : public ConnectionIF {
private:
    int sockfd;
    struct sockaddr_in serverAddress;
    int port;
    bool connected;

protected:
    void setSocketDescriptor(int fd) { sockfd = fd; }
    int getSocketDescriptor() const { return sockfd; }

    void setServerAddress(const struct sockaddr_in& address) { serverAddress = address; }
    struct sockaddr_in& getServerAddress() { return serverAddress; }
    const struct sockaddr_in& getServerAddress() const { return serverAddress; }

    void setPort(int p) { port = p; }
    int getPort() const { return port; }

    void setConnected(bool conn) { connected = conn; }
    bool getConnected() const { return connected; }

public:
    ConnectionAC() : sockfd(-1), port(0), connected(false) {}
    virtual ~ConnectionAC() {
        if (connected) {
            Disconnect();
        }
    }

    virtual bool UpdateConnection(const std::string& ipAddress, int port) = 0;
    virtual std::string RetrieveData() = 0;
};

#endif // CONNECTIONAC_H