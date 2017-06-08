#include "atccsinstructionresultprocessor.h"
#include "atccsdata.h"
#include <iostream>
#include "atccsupgoingcontroller.h"
#include "atccs_public_define.h"
#include "atccsinstruction.h"
#include "atccs_global.h"
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
    if(data == nullptr || !(data->validate()))
        return;

    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(_controller && header)
    {
        _controller->setInstructionResult(header->AT.device, data);
#ifdef OUTERRORINFO
        std::cout << header->AT.device << " ' instruction result is up-to-date!\n";
#endif
    }
}
