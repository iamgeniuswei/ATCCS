#ifndef ATCCSPLANPROCESSOR_H
#define ATCCSPLANPROCESSOR_H

#include "atccsdataprocessor.h"
class ATCCSPlanPerformer;
class ATCCSPlanProcessor : public ATCCSDataProcessor
{
public:
    explicit ATCCSPlanProcessor(ATCCSPlanPerformer *controller);
    void processData(std::shared_ptr<ATCCSData> data);
private:
    ATCCSPlanPerformer *_controller = nullptr;
};

#endif // ATCCSPLANPROCESSOR_H
