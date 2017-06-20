#ifndef ATCCSADDRESS_H
#define ATCCSADDRESS_H
#include <string>

class ATCCSAddress
{
public:
    ATCCSAddress();
    ATCCSAddress(const std::string &ip, unsigned short port);
    void setAddress(const std::string &ip, unsigned short port);

    std::string ip() const;
    unsigned short port() const;

protected:
    std::string _ip;
    unsigned short _port = 0;
};

#endif // ATCCSADDRESS_H
