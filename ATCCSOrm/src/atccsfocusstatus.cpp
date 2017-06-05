#include "atccsfocusstatus.h"
#include "atccsdata.h"
#include "atccs_focus_define.h"
atccsfocusstatus::atccsfocusstatus()
{

}

void atccsfocusstatus::setStatus(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || !(data->validate()))
        return;
    atccspublicstatus::setStatus(data);
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
