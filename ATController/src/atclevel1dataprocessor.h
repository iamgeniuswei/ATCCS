#ifndef ATCCSLEVEL1DATAPROCESSOR_H
#define ATCCSLEVEL1DATAPROCESSOR_H

#include "atccsdataprocessor.h"
#include <iostream>
class ATCCSDataDispatcher;
class ATCLevel1DataProcessor : public ATCCSDataProcessor
{
public:
    ATCLevel1DataProcessor(std::shared_ptr<ATCCSDataDispatcher> dispatcher = nullptr);
    ~ATCLevel1DataProcessor()
    {
        std::cout << "~ATCLevel1DataProcessor\n";
    }
public:
    void processData(std::shared_ptr<ATCCSData> data) override;
private:
    ATCCSDataDispatcher *_dispatcher = nullptr;
};

#endif // ATCCSLEVEL1DATAPROCESSOR_H
