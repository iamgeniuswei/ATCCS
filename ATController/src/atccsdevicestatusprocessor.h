#ifndef ATCCSDEVICESTATUSPROCESSOR_H
#define ATCCSDEVICESTATUSPROCESSOR_H

#include "atccsdataprocessor.h"
class ATCCSUpgoingController;
class ATCCSDeviceStatusProcessor : public ATCCSDataProcessor
{
public:
    ATCCSDeviceStatusProcessor(ATCCSUpgoingController *controller = nullptr);
    void processData(std::shared_ptr<ATCCSData> data);

private:
    ATCCSUpgoingController *_controller;
};


#endif // ATCCSDEVICESTATUSPROCESSOR_H
