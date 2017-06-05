#include "atccsfilterstatus.h"
#include "atccsdata.h"
#include "atccs_filter_define.h"
atccsfilterstatus::atccsfilterstatus()
{

}


void atccsfilterstatus::setStatus(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || !(data->validate()))
        return;
    _AT_FILTER_STATUS *status = (_AT_FILTER_STATUS*)(data->data() + sizeof(_ATCCSPHeader));
    if(status)
    {
        _filterPosition = status->filterPosition;
        _targetFilterPosition = status->targetFilterPosition;
        _isHomed = status->isHomed;
    }
}
