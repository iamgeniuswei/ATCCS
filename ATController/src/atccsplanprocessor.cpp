#include "atccsplanprocessor.h"
#include "atccs_public_define.h"
#include "atccsdata.h"
ATCCSPlanProcessor::ATCCSPlanProcessor(ATCCSPlanController *controller)
    :_controller(controller)
{

}

void ATCCSPlanProcessor::processData(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || !(data->validate()))
        return;

}
