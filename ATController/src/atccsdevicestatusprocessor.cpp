#include "atccsdevicestatusprocessor.h"
#include "atccsdata.h"
#include <iostream>
#include "atccs_public_define.h"
#include "atccsupgoingcontroller.h"
#include "atccs_gimbal_define.h"
#include "atccs_ccd_define.h"
#include "atccs_filter_define.h"
#include "atccs_dome_define.h"
#include "atccs_focus_define.h"
#include "atccs_guidescope_define.h"
#include "atccs_dpm_define.h"

ATCCSDeviceStatusProcessor::ATCCSDeviceStatusProcessor(ATCCSUpgoingController *controller):
    _controller(controller)
{
}

void ATCCSDeviceStatusProcessor::processData(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || !(data->validate()))
    {
        std::cout << "ATCCSDeviceStatusProcessor::processData: data error\n";
        return;
    }
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(_controller && header)
    {
        _controller->setDeviceStatus(header->AT.device, data);
        //FIXME:
//        std::cout << header->AT.device << "'s status is up-to-date!\n";
    }
}
