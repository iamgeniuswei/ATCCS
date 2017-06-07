#include "atccsplan.h"
#include <iostream>
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccs_plan_define.h"
atccsplan::atccsplan()
{

}


atccsplan::~atccsplan()
{
    std::cout << "~ATCCSPlan()\n";
}

unsigned int atccsplan::setPlan(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || !(data->validate()))
        return RESULT_PLANERROR;
    if(data->size() != (sizeof(_ATCCSPHeader) + sizeof(_AT_PLAN)))
        return RESULT_PLANERROR;
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(header)
    {
        _sec = header->tv_sec;
        _msec = header->tv_usec;
        _result = RESULT_EXECUTED;
    }
    _AT_PLAN *plan = (_AT_PLAN*)(data->data()+sizeof(_ATCCSPHeader));
    if(plan)
    {
        _at = plan->at;
        _user = plan->user;
        _project = std::string(plan->project);
        _target = std::string(plan->target);
        _type = plan->type;
        _rightAscension = plan->rightAscension;
        _declination = plan->declination;
        _epoch = plan->epoch;
        _exposureTime = plan->exposureTime;
        _delayTime = plan->delayTime;
        _exposureCount = plan->exposureCount;
        _filter = std::string(plan->filter);
        _gain = plan->gain;
        _bin = plan->bin;
        _readout = plan->readout;
    }
    return RESULT_EXECUTED;
}

double atccsplan::delayTime() const
{
    return _delayTime;
}

double atccsplan::reclination() const
{
    return _declination;
}

double atccsplan::rightAscension() const
{
    return _rightAscension;
}

double atccsplan::exposureTime() const
{
    return _exposureTime;
}

unsigned int atccsplan::readout() const
{
    return _readout;
}

unsigned int atccsplan::bin() const
{
    return _bin;
}

unsigned int atccsplan::gain() const
{
    return _gain;
}

unsigned int atccsplan::exposureCount() const
{
    return _exposureCount;
}

unsigned int atccsplan::epoch() const
{
    return _epoch;
}

unsigned int atccsplan::type() const
{
    return _type;
}

unsigned int atccsplan::at() const
{
    return _at;
}

unsigned int atccsplan::percent() const
{
    return _percent;
}

unsigned int atccsplan::result() const
{
    return _result;
}

unsigned int atccsplan::msec() const
{
    return _msec;
}

unsigned int atccsplan::sec() const
{
    return _sec;
}

std::string atccsplan::filter() const
{
    return _filter;
}

std::string atccsplan::target() const
{
    return _target;
}

std::string atccsplan::project() const
{
    return _project;
}

unsigned int atccsplan::user() const
{
    return _user;
}


