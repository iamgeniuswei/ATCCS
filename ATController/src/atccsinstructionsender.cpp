#include "atccsinstructionsender.h"
#include "atccs_public_define.h"
#include "atccs_gimbal_define.h"
#include "atccsdata.h"
#include <iostream>
ATCCSInstructionSender::ATCCSInstructionSender(ATCCSDeviceController *controller)
{

}

int ATCCSInstructionSender::sendData(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || !(data->validate()))
        return 0;
    return ATCCSDataSender::sendData(data);
}
