#ifndef ABSTRACT_CONNECTIONAC_H
#define ABSTRACT_CONNECTIONAC_H

#include "../Interfaces/ConnectionIF.h"
#include <netinet/in.h> // For sockaddr_in
#include <unistd.h>     // For close
#include <arpa/inet.h>  // For inet_pton
#include <string>
#include <cstring>      // For memset
#include <mutex>

class ConnectionAC : public ConnectionIF {
private:
    int sockfd; // Use int for socket descriptor
    struct sockaddr_in serverAddress;
    std::string ipAddress;
    int port;
    bool connected;
    mutable std::mutex connMutex; // Mutex for thread safety

protected:
    bool setSocketDescriptor(int fd) {
        std::lock_guard<std::mutex> lock(connMutex);
        if (sockfd != -1) {
            close(sockfd); // Close the previous socket descriptor
        }
        sockfd = fd;
        return sockfd != -1;
    }

    int getSocketDescriptor() const {
        std::lock_guard<std::mutex> lock(connMutex);
        return sockfd;
    }

    bool setServerAddress(const std::string& address) {
        std::lock_guard<std::mutex> lock(connMutex);
        struct sockaddr_in temp;
        memset(&temp, 0, sizeof(temp));
        temp.sin_family = AF_INET;

        if (inet_pton(AF_INET, address.c_str(), &temp.sin_addr) <= 0) {
            return false; // Address conversion failed
        }

        ipAddress = address;
        serverAddress = temp;
        return true;
    }

    std::string getServerAddress() const {
        std::lock_guard<std::mutex> lock(connMutex);
        return ipAddress;
    }

    bool setPort(int newPort) {
        std::lock_guard<std::mutex> lock(connMutex);
        port = newPort;
        serverAddress.sin_port = htons(port);
        return true;
    }

    int getPort() const {
        std::lock_guard<std::mutex> lock(connMutex);
        return port;
    }

    bool setConnected(bool conn) {
        std::lock_guard<std::mutex> lock(connMutex);
        connected = conn;
        return true;
    }

    bool getConnected() const {
        std::lock_guard<std::mutex> lock(connMutex);
        return connected;
    }

    void Disconnect() {
        std::lock_guard<std::mutex> lock(connMutex);
        if (sockfd != -1) {
            close(sockfd);
            sockfd = -1;
            connected = false;
        }
    }

public:
    ConnectionAC() : sockfd(-1), serverAddress(), port(0), connected(false) {
        memset(&serverAddress, 0, sizeof(serverAddress)); // Zero-initialize
    }

    ~ConnectionAC() override {
        Disconnect();
    }

    virtual bool UpdateConnection(const std::string& ipAddress, int port) override = 0;
    virtual std::string GetIpAddress() override = 0;
    virtual int GetPort() override = 0;
    virtual std::string RetrieveData() override = 0;
    virtual ConnectionIF* Get() override = 0;
};

#endif // ABSTRACT_CONNECTIONAC_H
