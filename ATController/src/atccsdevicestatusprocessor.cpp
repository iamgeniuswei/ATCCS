#include "atccsdevicestatusprocessor.h"
#include "atccsupgoingcontroller.h"
#include "atccs_public_define.h"
#include "atccsdata.h"
#include "atccsexceptionhandler.h"

ATCCSDeviceStatusProcessor::ATCCSDeviceStatusProcessor(ATCCSUpgoingController *controller):
    _controller(controller)
{
}

void ATCCSDeviceStatusProcessor::processData(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr)
    {
        return;
    }
    if(!data->validate())
    {
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSData is error, can not resolve device status information.");
        return;
#endif 
    }
    if (_controller)
    {
        _ATCCSPHeader *header = (_ATCCSPHeader*) (data->data());
        if (header)
        {
            _controller->setDeviceStatus(header->AT.device, data);
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSUpgoingController instance is null, can not process device status ATCCSData.");
#endif
    }
}
