#ifndef ATCCSHEARTBEATPROCESSOR_H
#define ATCCSHEARTBEATPROCESSOR_H
#include "atccsdataprocessor.h"
class ATCCSUpgoingController;
class ATCCSHeartbeatProcessor : public ATCCSDataProcessor
{
public:
    explicit ATCCSHeartbeatProcessor(ATCCSUpgoingController *controller = nullptr);
    void processData(std::shared_ptr<ATCCSData> data);

private:
    ATCCSUpgoingController *_controller = nullptr;
};
#endif // ATCCSHEARTBEATPROCESSOR_H
