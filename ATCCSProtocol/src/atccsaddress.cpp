#include "atccsaddress.h"
#include <iostream>
ATCCSAddress::ATCCSAddress()
{

}

ATCCSAddress::ATCCSAddress(const std::string& ip, unsigned short port) 
    :_ip(ip),_port(port)
{

}


void ATCCSAddress::setAddress(const std::string &ip, unsigned short port)
{
    _ip = ip;
    _port = port;
}

void ATCCSAddress::setIP(const std::string& ip)
{
    _ip = ip;
}

void ATCCSAddress::setPort(unsigned short port)
{
    _port = port;
}


std::string ATCCSAddress::ip() const
{
    return _ip;
}

unsigned short ATCCSAddress::port() const
{
    return _port;
}
