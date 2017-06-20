#include "atccsheartbeatprocessor.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccsupgoingcontroller.h"
#include <iostream>
#include "atccs_global.h"
#include "atccsexceptionhandler.h"
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
    if(data == nullptr)
        return;
    if (!data->validate())
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s",
                                            gettext("The heartbeat's raw data is error and is neglected."));
#endif
        return;      
    }
    
    if (_controller)
    {
        _ATCCSPHeader *header = (_ATCCSPHeader*) (data->data());
        if (header)
        {
            _controller->setDeviceOnline(header->AT.device, true, header->tv_sec);
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                            gettext("The upgoing controller is fail to be created, fails to process heartbeat."));
#endif
    }
}
