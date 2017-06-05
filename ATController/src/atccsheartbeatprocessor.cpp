#include "atccsheartbeatprocessor.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccsupgoingcontroller.h"
#include <iostream>
#include "atccs_global.h"
ATCCSHeartbeatProcessor::ATCCSHeartbeatProcessor(ATCCSUpgoingController *controller):
    _controller(controller)
{

}

/**
 * @brief this function call ATCCSUpgoingController::setDeviceOnline
 *        to update device's online data.
 * @param data, the raw heartbeat data received from device.
 */
void ATCCSHeartbeatProcessor::processData(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || !(data->validate()))
        return;
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(_controller && header)
    {
        _controller->setDeviceOnline(header->AT.device, true, header->tv_sec);
#ifdef OUTDEBUGINFO
        std::cout << header->AT.device << " is online at " << header->tv_sec << std::endl;
#endif
    }
}
