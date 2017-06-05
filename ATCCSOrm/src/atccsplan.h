#ifndef ATCCSPLAN_H
#define ATCCSPLAN_H
#include <cstddef>
#include "atccs_global.h"
#include <string>
#include <memory>
#include <odb/core.hxx>

class ATCCSData;
#pragma db object
class atccsplan
{
public:
    enum RESULT_PLAN
    {
        RESULT_PLANERROR,
        RESULT_EXECUTED,
        RESULT_ABORTED,
        RESULT_SUCCESS
    };
    explicit atccsplan();
    atccsplan(const atccsplan&);
    atccsplan& operator =(const atccsplan&);
    ~atccsplan();
    unsigned int setPlan(std::shared_ptr<ATCCSData> data = nullptr);
    unsigned int at() const;

    unsigned int exposureCount() const;
    std::string target() const;
    unsigned int type() const;
    unsigned int epoch() const;
    double declination() const;
    double rightAscension() const;
    unsigned int exposureTime() const;
    unsigned int gain() const;
    unsigned int bin() const;
    unsigned int readout() const;
    double delayTime() const;
    std::string filter() const;
    unsigned int result() const;
    void setResult(unsigned int _result);

private:
    friend class odb::access;
#pragma db id auto
    unsigned int _id = 0;
    unsigned int _user = 0;
    std::string _project;
    std::string _target;
    std::string _filter;
    unsigned int _sec = 0;
    unsigned int _msec = 0;
    unsigned int _result = 0;
    unsigned int _percent = 0;
    unsigned int _at = 0;
    unsigned int _type = 0;
    unsigned int _epoch = 0;    
    unsigned int _exposureCount = 0;
    unsigned int _gain = 0;
    unsigned int _bin = 0;
    unsigned int _readout = 0;
    double _exposureTime = 0;
    double _rightAscension = 0;
    double _declination = 0;
    double _delayTime = 0;
};

#endif // ATCCSPLAN_H
