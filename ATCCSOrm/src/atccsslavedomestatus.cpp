#include "atccsslavedomestatus.h"
#include "atccsdata.h"
#include "atccs_dome_define.h"
atccsslavedomestatus::atccsslavedomestatus()
{

}


void atccsslavedomestatus::setStatus(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || !(data->validate()))
        return;
    _AT_SLAVEDOME_STATUS *status = (_AT_SLAVEDOME_STATUS*)(data->data()+sizeof(_ATCCSPHeader));
    if(status)
    {
        _scuttleStatus = status->scuttleStatus;
        _shadeStatus = status->shadeStatus;
        _domePosition = status->domePosition;
        _scuttlePercent = status->scuttlePercent;
        _shadePosition = status->shadePosition;
        _targetDomePosition = status->targetDomePosition;
        _targetScuttlePosition = status->targetScuttlePosition;
        _targetShadePosition = status->targetShadePosition;
    }
}
