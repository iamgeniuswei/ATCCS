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
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s",
                                            gettext("The status' raw data is error and is neglected."));
#endif 
        return;
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
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                            gettext("The upgoing controller is fail to be created, fails to process device status."));
#endif
    }
}
