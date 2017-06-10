#include "atccsfilterstatus.h"
#include "atccsdata.h"
#include "atccs_filter_define.h"
atccsfilterstatus::atccsfilterstatus()
{

}


void atccsfilterstatus::setStatus(std::shared_ptr<ATCCSData> data)
{
    atccspublicstatus::setStatus(data);
    if(data == nullptr || !(data->validate()))
        return;
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(header)
    {
        _sec = header->tv_sec;
        _msec = header->tv_usec;
    }
    _AT_FILTER_STATUS *status = (_AT_FILTER_STATUS*)(data->data() + sizeof(_ATCCSPHeader));
    if(status)
    {
        _filterPosition = status->filterPosition;
        _targetFilterPosition = status->targetFilterPosition;
        _isHomed = status->isHomed;
    }
}

unsigned short atccsfilterstatus::isHomed() const
{
    return _isHomed;
}

unsigned short atccsfilterstatus::targetFilterPosition() const
{
    return _targetFilterPosition;
}

unsigned short atccsfilterstatus::filterPosition() const
{
    return _filterPosition;
}
