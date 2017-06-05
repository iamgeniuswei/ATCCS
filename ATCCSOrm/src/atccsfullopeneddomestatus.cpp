#include "atccsfullopeneddomestatus.h"
#include "atccsdata.h"
#include "atccs_dome_define.h"
ATCCSFullOpenedDomeStatus::ATCCSFullOpenedDomeStatus()
{

}


void ATCCSFullOpenedDomeStatus::setStatus(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr ||!(data->validate()))
        return;
    _AT_FULLOPENEDDOME_STATUS *status = (_AT_FULLOPENEDDOME_STATUS*)(data->data() + sizeof(_ATCCSPHeader));
    if(status)
    {
        _domePosition = status->domePosition;
    }
}
