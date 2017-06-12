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
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSData is error, can not resolve device instruction result.");
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
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSUpgoingController instance is null, fails to process Instruction Result ATCCSData.");
#endif        
    }
}
