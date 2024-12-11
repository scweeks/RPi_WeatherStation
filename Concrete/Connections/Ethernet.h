#ifndef ETHERNET_H
#define ETHERNET_H

#include "../../Abstract/ConnectionAC.h"
#include <stdexcept>
#include <iostream>
#include <cstring> // For memset
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
        struct sockaddr_in address;
        memset(&address, 0, sizeof(address));
        address.sin_family = AF_INET;
        address.sin_port = htons(port);

        if (inet_pton(AF_INET, ipAddress.c_str(), &address.sin_addr) <= 0) {
            throw std::invalid_argument("Invalid IP address");
        }

        setServerAddress(address);
        setPort(port);
        return true;
    }

    std::string RetrieveData() override {
        // Implement data retrieval logic here
        struct sockaddr_in serverAddr = this->getServerAddress();
        int sockfd = this->getSocketDescriptor();
        if (connect(this->getSocketDescriptor(), (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
        { 
            this->setConnected(false);
            throw std::runtime_error("ERROR Opening Connection...");
            return false; 
        } 
        this->setConnected(true); 
        // For example, read data from the socket
        char buffer[1024];
        int bytesRead = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytesRead < 0) {
            throw std::runtime_error("ERROR reading from socket");
        }
        return std::string(buffer, bytesRead);
    }
};

#endif // ETHERNET_H