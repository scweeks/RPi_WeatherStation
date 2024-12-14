#ifndef ETHERNET_H
#define ETHERNET_H

#include "../../Abstract/ConnectionAC.h"
#include <stdexcept>
#include <iostream>
#include <arpa/inet.h> // For inet_pton
#include <sys/socket.h> // For socket functions

class Ethernet : public ConnectionAC {
public:
    Ethernet(const std::string& ipAddress, int port) {
        if (!UpdateConnection(ipAddress, port)) {
            throw std::runtime_error("Failed to update connection");
        }
    }

    bool UpdateConnection(const std::string& ipAddress, int port) override {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            return false;
        }
        if (!setServerAddress(ipAddress) || !setPort(port) || !setSocketDescriptor(sock)) {
            return false;
        }
        return true;
    }

    std::string RetrieveData() override {
        // Implement data retrieval logic here
        struct sockaddr_in temp;
        temp.sin_family = AF_INET;
        temp.sin_port = htons(getPort());
        if (inet_pton(AF_INET, getServerAddress().c_str(), &temp.sin_addr) <= 0) {
            throw std::runtime_error("Failed to make sockaddr");
        }
        int sockfd = getSocketDescriptor();
        if (sockfd < 0) {
            if (!setSocketDescriptor(socket(AF_INET, SOCK_STREAM, 0)))
            {
            	throw std::runtime_error("ERROR Opening Socket...");			
            }
            sockfd = getSocketDescriptor();
		}
        if (connect(sockfd, reinterpret_cast<struct sockaddr*>(&temp), sizeof(temp)) < 0)
        { 
            this->setConnected(false);
            throw std::runtime_error("ERROR Opening Connection...");
        } 
        this->setConnected(true); 
        // read data from the socket
        char buffer[1024];
        int bytesRead = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytesRead < 0) {
            throw std::runtime_error("ERROR reading from socket");
        }
        return std::string(buffer, bytesRead);
    }

    virtual std::string GetIpAddress()
    {
        return getServerAddress();
    }
    virtual int GetPort()
    {
    	return getPort();
    }
};

#endif // ETHERNET_H