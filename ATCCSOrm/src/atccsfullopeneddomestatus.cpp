#include "atccsfullopeneddomestatus.h"
#include "atccsdata.h"
#include "atccs_dome_define.h"
atccsfullopeneddomestatus::atccsfullopeneddomestatus()
{

}


void atccsfullopeneddomestatus::setStatus(std::shared_ptr<ATCCSData> data)
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
    _AT_FULLOPENEDDOME_STATUS *status = (_AT_FULLOPENEDDOME_STATUS*)(data->data() + sizeof(_ATCCSPHeader));
    if(status)
    {
        _domePosition = status->domePosition;
    }
}
