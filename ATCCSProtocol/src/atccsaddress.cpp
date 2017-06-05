#include "atccsaddress.h"
#include <iostream>
ATCCSAddress::ATCCSAddress()
{

}

ATCCSAddress::ATCCSAddress(const std::string& ip, unsigned short port) 
    :_ip(ip),_port(port)
{

}


ATCCSAddress::~ATCCSAddress()
{
    std::cout << "~ATCCSAddress\n";
}

void ATCCSAddress::setAddress(const std::string &ip, unsigned short port)
{
    _ip = ip;
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
