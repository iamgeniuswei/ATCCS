#ifndef QPUDPSOCKET_H
#define QPUDPSOCKET_H
#include <string>
using namespace std;


#ifdef WIN32
typedef unsigned long ssize_t;
typedef int socklen_t;
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#endif


enum ERRORCODE{
    QPUDP_SOCKET_ERROR = -1
};


class QPUdpSocket
{
public:
    enum RETCODE
    {
        FAIL = -1,
        SUCCESS = 0
    };
public:
    explicit QPUdpSocket();
    ~QPUdpSocket();
    void setTargetAddress(const string &ip, unsigned short port);
    int setHostAddress(const string &ip, unsigned short port);
    void setRecvTimeout(unsigned int duration);
    ssize_t sendData(const char *data, ssize_t size);
    ssize_t recvData(char *data, unsigned int MAXSIZE);
private:
    string _targetIP;
    unsigned short _targetPort;
    sockaddr_in _targetAddr;
    string _hostIP;
    unsigned short _hostPort;
    sockaddr_in _hostAddr;
#ifdef WIN32
    SOCKET   send_socket_descriptor = -1;
    SOCKET recv_socket_descriptor = -1;
    WSADATA ws;
#else
    int send_socket_descriptor = -1;
    int recv_socket_descriptor = -1;
#endif
};

#endif // QPUDPSOCKET_H
