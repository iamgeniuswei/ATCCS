#include "atccsinstructionresultprocessor.h"
#include "atccsdata.h"
#include <iostream>
#include "atccsupgoingcontroller.h"
#include "atccs_public_define.h"
#include "atccsinstruction.h"
#include "atccs_global.h"
#include "atccsexceptionhandler.h"
ATCCSInstructionResultProcessor::ATCCSInstructionResultProcessor(ATCCSUpgoingController *controller):
    _controller(controller)
{

}

/**
 * @brief This function call ATCCSUpgoingController::setInstructionResult
 *        to update device's current instruction's result.
 * @param data, raw AT instruction result data received from device.
 */
void ATCCSInstructionResultProcessor::processData(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr)
        return;
    if(!data->validate())
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s",
                                            gettext("The instruction result's raw data is error and is neglected."));
#endif
        return;
    }

    if (_controller)
    {
        _ATCCSPHeader *header = (_ATCCSPHeader*) (data->data());
        if (header)
        {
            _controller->setInstructionResult(header->AT.device, data);
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                            gettext("The upgoing controller is fail to be created, fails to process instruction result."));
#endif        
    }
}
