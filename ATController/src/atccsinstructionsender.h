#ifndef ATCCSINSTRUCTIONSENDER_H
#define ATCCSINSTRUCTIONSENDER_H

#include "atccsdatasender.h"
class ATCCSDeviceController;
class ATCCSInstructionSender : public ATCCSDataSender
{
public:
    ATCCSInstructionSender(ATCCSDeviceController *controller);
    int sendData(std::shared_ptr<ATCCSData> data);
    
private:
    bool validateBeforeSend(std::shared_ptr<ATCCSData> data = nullptr);
};

#endif // ATCCSINSTRUCTIONSENDER_H
