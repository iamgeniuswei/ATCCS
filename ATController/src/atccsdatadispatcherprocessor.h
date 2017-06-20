#ifndef ATCCSDATADISPATCHERPROCESSOR_H
#define ATCCSDATADISPATCHERPROCESSOR_H

#include "atccsdataprocessor.h"
#include <iostream>
class ATCCSDataDispatcher;
class ATCCSDataDispatcherProcessor : public ATCCSDataProcessor
{
public:
    ATCCSDataDispatcherProcessor(std::shared_ptr<ATCCSDataDispatcher> dispatcher = nullptr);
public:
    void processData(std::shared_ptr<ATCCSData> data) override;
private:
    ATCCSDataDispatcher *_dispatcher = nullptr;
};

#endif // ATCCSDATADISPATCHERPROCESSOR_H
