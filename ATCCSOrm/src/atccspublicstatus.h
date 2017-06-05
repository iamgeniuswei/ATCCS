#ifndef ATCCSPUBLICSTATUS_H
#define ATCCSPUBLICSTATUS_H
#include <cstddef>
#include "atccs_global.h"
#include <odb/core.hxx>
#include <memory>
#include <string>
#include <iostream>

class ATCCSData;
#pragma db object
class atccspublicstatus
{
public:
    atccspublicstatus();
    virtual ~atccspublicstatus()
    {
        std::cout << "~atccspublicstatus\n";
    }
    void set_errorString(std::string _errorString);
    std::string errorString() const;
    void set_error(unsigned long long _error);
    unsigned long long error() const;
    void set_warning(unsigned long long _warning);
    unsigned long long warning() const;
    void set_laststatus(unsigned int _lastStatus);
    unsigned int laststatus() const;
    void set_curstatus(unsigned int _curstatus);
    unsigned int curstatus() const;
    void set_msec(unsigned int _msec);
    unsigned int msec() const;
    void set_sec(unsigned int _sec);
    unsigned int sec() const;
    virtual void setStatus(std::shared_ptr<ATCCSData> data);
    virtual unsigned long long persistStatus() = 0;


protected:
    friend class odb::access;
#pragma db id auto
    unsigned long long _id = 0;
    unsigned int _sec = 0;
    unsigned int _msec = 0;
    unsigned int _curstatus = INIT_VALUE;
    unsigned int _lastStatus = INIT_VALUE;
    unsigned long long _warning = INIT_VALUE;
    unsigned long long _error = INIT_VALUE;
    std::string _errorString;
};

#endif // ATCCSPUBLICSTATUS_H
