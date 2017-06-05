#include "atccsplan.h"
#include <iostream>
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccs_plan_define.h"
atccsplan::atccsplan()
{
//    _id = 0;
//    _sec = 0;
//    _msec = 0;
//    _at = 0;
//    _user = "test";
//    _project = "test";
//    _target = "test";
//    _type = 0;
//    _rightAscension = 0;
//    _declination = 0;
//    _epoch = 0;
//    _exposureTime = 0;
//    _delayTime = 0;
//    _exposureCount = 0;
//    _filter = "test";
//    _gain = 0;
//    _bin = 0;
    //    _readout = 0;
}

atccsplan::atccsplan(const atccsplan &)
{

}

atccsplan &atccsplan::operator =(const atccsplan &)
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
//        _user = std::string(plan->user);
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

unsigned int atccsplan::at() const
{
    return _at;
}

unsigned int atccsplan::exposureCount() const
{
    return _exposureCount;
}

std::string atccsplan::target() const {
    return _target;
}

unsigned int atccsplan::type() const {
    return _type;
}

unsigned int atccsplan::epoch() const {
    return _epoch;
}

double atccsplan::declination() const {
    return _declination;
}

double atccsplan::rightAscension() const {
    return _rightAscension;
}

unsigned int atccsplan::exposureTime() const {
    return _exposureTime;
}

unsigned int atccsplan::gain() const {
    return _gain;
}

unsigned int atccsplan::bin() const {
    return _bin;
}

unsigned int atccsplan::readout() const {
    return _readout;
}

double atccsplan::delayTime() const {
    return _delayTime;
}

std::string atccsplan::filter() const {
    return _filter;
}

unsigned int atccsplan::result() const {
    return _result;
}

void atccsplan::setResult(unsigned int _result) {
    this->_result = _result;
}

