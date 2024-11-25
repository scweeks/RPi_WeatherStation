#ifndef CONNECTIONIF_H
#define CONNECTIONIF_H

using namespace std;

class ConnectionIF {
public:
    virtual bool Open(struct socketaddr_in sockfd, int port) = 0;
    virtual bool Close() = 0;
    virtual ~ConnectionIF() = default;
};

#endif // CONNECTIONIF_H
