#include "atccspublicstatus.h"
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/pgsql/database.hxx>
#include "atccsdata.h"
#include "atccs_public_define.h"
#include <cstddef>
atccspublicstatus::atccspublicstatus()
{

}

void atccspublicstatus::setStatus(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || !(data->validate())) 
       return;
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(header)
    {
        _sec = header->tv_sec;
        _msec = header->tv_usec;
    }
    _AT_PUBLIC_STATUS *pub = (_AT_PUBLIC_STATUS*)(data->data()+sizeof(_ATCCSPHeader));
    if(pub)
    {
        _curstatus = pub->status;
        _lastStatus = pub->lastStatus;
        _warning = pub->warning;
        _error = pub->error;
        _errorString.assign(pub->errorString);
    }

}

void atccspublicstatus::set_errorString(std::string _errorString) {
    this->_errorString = _errorString;
}

std::string atccspublicstatus::errorString() const {
    return _errorString;
}

void atccspublicstatus::set_error(unsigned long long _error) {
    this->_error = _error;
}

unsigned long long atccspublicstatus::error() const {
    return _error;
}

void atccspublicstatus::set_warning(unsigned long long _warning) {
    this->_warning = _warning;
}

unsigned long long atccspublicstatus::warning() const {
    return _warning;
}

void atccspublicstatus::set_laststatus(unsigned int _lastStatus) {
    this->_lastStatus = _lastStatus;
}

unsigned int atccspublicstatus::laststatus() const {
    return _lastStatus;
}

void atccspublicstatus::set_curstatus(unsigned int _curstatus) {
    this->_curstatus = _curstatus;
}

unsigned int atccspublicstatus::curstatus() const {
    return _curstatus;
}

void atccspublicstatus::set_msec(unsigned int _msec) {
    this->_msec = _msec;
}

unsigned int atccspublicstatus::msec() const {
    return _msec;
}

void atccspublicstatus::set_sec(unsigned int _sec) {
    this->_sec = _sec;
}

unsigned int atccspublicstatus::sec() const {
    return _sec;
}
