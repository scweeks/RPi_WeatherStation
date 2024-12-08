#ifndef CONNECTIONIF_H
#define CONNECTIONIF_H

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

class ConnectionIF {
public:
    virtual bool Open(struct sockaddr_in sockfd, int port) = 0;
    virtual bool Close() = 0;
    virtual ~ConnectionIF() = default;
};

#endif // CONNECTIONIF_H