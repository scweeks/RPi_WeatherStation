#ifndef CONNECTIONAC_H
#define CONNECTIONAC_H

#include "../Interfaces/ConnectionIF.h"

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
    unsigned long long sockfd;
    struct sockaddr_in serverAddress;
    std::string ipAddress;
    int port;
    bool connected;

protected:
    bool setSocketDescriptor(unsigned long long fd)
    {
        int temp = sockfd;
	    sockfd = fd;
        return sockfd != temp;
    }
    int getSocketDescriptor() const { return sockfd; }

    bool setServerAddress(const std::string ipAddress)
    {
    	struct sockaddr_in temp;
		temp.sin_family = AF_INET;
		temp.sin_port = htons(port);
		if (inet_pton(AF_INET, ipAddress.c_str(), &temp.sin_addr) <= 0) {
			return false;
		}
        this->ipAddress = ipAddress;
		serverAddress = temp;
		return true;
    }
    std::string getServerAddress() { return ipAddress; }

    bool setPort(int port)
    {
        int temp = port;
        this->port = port;
        return this->port != temp;
    }

    int getPort() const { return port; }

    bool setConnected(bool conn)
    {
        
		bool temp = connected;
		connected = conn;
		return connected != temp;
    }
    bool getConnected() const { return connected; }

    void Disconnect()  {
        if (sockfd != -1) {
#ifdef _WIN32
            closesocket(sockfd);
#else
            close(sockfd);
#endif
            sockfd = -1;
            connected = false;
        }
    }

public:
    ConnectionAC() : sockfd(-1), port(0), connected(false) {}

    ~ConnectionAC() override
    {
        if (connected) {
            Disconnect();
        }
    }

    virtual bool UpdateConnection(const std::string& ipAddress, int port) override = 0;
    virtual std::string GetIpAddress() const override = 0;
    virtual int GetPort() const override = 0;
    virtual std::string RetrieveData() override = 0;
};

#endif // CONNECTIONAC_H