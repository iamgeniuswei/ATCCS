#ifndef ATCCSPLANPROCESSOR_H
#define ATCCSPLANPROCESSOR_H

#include "atccsdataprocessor.h"
class ATCCSPlanController;
class ATCCSPlanProcessor : public ATCCSDataProcessor
{
public:
    explicit ATCCSPlanProcessor(ATCCSPlanController *controller);
    void processData(std::shared_ptr<ATCCSData> data);
private:
    ATCCSPlanController *_controller = nullptr;
};

#endif // ATCCSPLANPROCESSOR_H
