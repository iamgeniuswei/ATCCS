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
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSData is error, can not resolve heartbeat information.");
        return;
#endif        
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
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSUpgoingController instance is null, fails to process Heartbeat ATCCSData.");
        return;
#endif
    }
}
