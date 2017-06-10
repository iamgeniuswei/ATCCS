#include "atccsfocusstatus.h"
#include "atccsdata.h"
#include "atccs_focus_define.h"
atccsfocusstatus::atccsfocusstatus()
{

}

void atccsfocusstatus::setStatus(std::shared_ptr<ATCCSData> data)
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
    _AT_FOCUS_STATUS *status = (_AT_FOCUS_STATUS*)(data->data()+sizeof(_ATCCSPHeader));
    if(status)
    {
        _position = status->position;
        _targetPosition = status->targetPosition;
        _isHomed = status->isHomed;
        _temperature = status->temperature;
        _isTCompensation = status->isTCompensation;
        _TCompenensation = status->TCompenensation;
    }

}
