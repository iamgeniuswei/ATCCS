#include "qpudpsocket.h"
#include <memory>
#include <iostream>
using namespace std;
#include <string.h>

#ifdef WIN32

#else
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif
QPUdpSocket::QPUdpSocket()
{
#ifdef WIN32
    if(WSAStartup(MAKEWORD(2,2), &ws) != 0)
        cerr << "init WSA failed";
    send_socket_descriptor = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(send_socket_descriptor == INVALID_SOCKET)
        cerr<< "udp send socket created failed!"<<endl;
    recv_socket_descriptor = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(recv_socket_descriptor == INVALID_SOCKET)
        cerr<<"udp recv socket created failed!"<<endl;
#else
    send_socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
    if(send_socket_descriptor < 0)
        cerr<< "udp send socket created failed!"<<endl;
    recv_socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
    if(recv_socket_descriptor < 0)
        cerr<<"udp recv socket created failed!"<<endl;
#endif
}

QPUdpSocket::~QPUdpSocket()
{
#ifdef WIN32
    if(send_socket_descriptor != INVALID_SOCKET)
        closesocket(send_socket_descriptor);
    if(recv_socket_descriptor != INVALID_SOCKET)
        closesocket(recv_socket_descriptor);;
#else
    if(send_socket_descriptor != -1)
        close(send_socket_descriptor);
    if(recv_socket_descriptor != -1)
        close(recv_socket_descriptor);
#endif
}

void QPUdpSocket::setTargetAddress(const string &ip, unsigned short port)
{
    _targetIP = ip;
    _targetPort = port;
    memset(&_targetAddr, 0, sizeof(sockaddr_in));
    _targetAddr.sin_family = AF_INET;
    _targetAddr.sin_addr.s_addr = inet_addr(_targetIP.data());
    _targetAddr.sin_port = htons(_targetPort);
}

int QPUdpSocket::setHostAddress(const string &ip, unsigned short port)
{
    int ret = FAIL;
    _hostIP = ip;
    _hostPort = port;
    memset(&_hostAddr, 0, sizeof(sockaddr_in));
    _hostAddr.sin_family = AF_INET;
    if(ip.empty())
        _hostAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    else
    {
        _hostAddr.sin_addr.s_addr = inet_addr(_hostIP.data());
    }
    _hostAddr.sin_port = htons(_hostPort);
    if(recv_socket_descriptor != -1)
    {
        ret = bind(recv_socket_descriptor, (sockaddr*)&_hostAddr, sizeof(sockaddr));
        if(ret == FAIL)
        {
            cerr << "ERROR: fails to bind IP and PORT, can not receive any data!" << endl;
        }
    }
    return ret;
}

void QPUdpSocket::setRecvTimeout(unsigned int duration) 
{
    if(recv_socket_descriptor < 0)
        return;
    timeval tv = {duration, 0};
    setsockopt(recv_socket_descriptor, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(timeval));
}



ssize_t QPUdpSocket::sendData(const char *data, ssize_t size)
{
    if(send_socket_descriptor < 0)
        return QPUDP_SOCKET_ERROR;
    ssize_t ret = sendto(send_socket_descriptor,\
                         data, \
                         size,\
                         0,\
                         (struct sockaddr*)&_targetAddr,\
                         sizeof(sockaddr));
    return ret;
}

ssize_t QPUdpSocket::recvData(char *data, unsigned int MAXSIZE)
{
    ssize_t ret = -1;
    sockaddr_in client_addr;
    socklen_t client_addr_length = sizeof(sockaddr_in);
    memset(&client_addr, 0, sizeof(sockaddr_in));
    if(data == nullptr)
        return ret;

    ret = recvfrom(recv_socket_descriptor,\
                   data,\
                   MAXSIZE,\
                   0, \
                   (sockaddr*)&client_addr,\
                   &client_addr_length);
    return ret;
}
