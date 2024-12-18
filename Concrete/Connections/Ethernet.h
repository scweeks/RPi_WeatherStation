#ifndef CONCRETE_CONNECTIONS_ETHERNET_H_
#define CONCRETE_CONNECTIONS_ETHERNET_H_

#include "../../Abstract/ConnectionAC.h"
#include <stdexcept>
#include <iostream>
#include <arpa/inet.h> // For inet_pton
#include <sys/socket.h> // For socket functions
#include <unistd.h>     // For close()
#include <cstring>      // For memset

class Ethernet : public ConnectionAC {
public:
    Ethernet(const std::string& ipAddress, int port) {
        if (!Ethernet::UpdateConnection(ipAddress, port)) {
            throw std::runtime_error("Failed to update connection");
        }
    }

    bool UpdateConnection(const std::string& ipAddress, int port) override {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Socket creation failed");
            return false;
        }

        if (!setServerAddress(ipAddress) || !setPort(port) || !setSocketDescriptor(sock)) {
            close(sock);
            return false;
        }

        return true;
    }

    std::string RetrieveData() override {
        struct sockaddr_in serverAddr;
        memset(&serverAddr, 0, sizeof(serverAddr));
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(getPort());

        if (inet_pton(AF_INET, getServerAddress().c_str(), &serverAddr.sin_addr) <= 0) {
            perror("inet_pton failed");
            throw std::runtime_error("Invalid server address");
        }

        int sockfd = getSocketDescriptor();
        if (sockfd < 0) {
            perror("Invalid socket descriptor");
            throw std::runtime_error("Socket error");
        }

        if (connect(sockfd, reinterpret_cast<struct sockaddr*>(&serverAddr), sizeof(serverAddr)) < 0) {
            perror("Connection failed");
            close(sockfd);
            throw std::runtime_error("Connection error");
        }

        int data;
        int bytesRead = recv(sockfd, &data, sizeof(data), 0);
        if (bytesRead != sizeof(data)) {
            perror("Data reception error");
            throw std::runtime_error("Incomplete data received");
        }

        printf("Data retrieved: %d\n", data);
        return std::to_string(data);
    }

    std::string GetIpAddress() override {
        return getServerAddress();
    }

    int GetPort() override {
        return getPort();
    }

    virtual ConnectionIF* Get() override {
        return this;
    }

    ~Ethernet() override
    {
        // Close the socket on destruction
        int sockfd = getSocketDescriptor();
        if (sockfd >= 0) {
            close(sockfd);
        }
    }
};

#endif /* CONCRETE_CONNECTIONS_ETHERNET_H_ */
