#ifndef ATCCSINSTRUCTIONRESULTPROCESSOR_H
#define ATCCSINSTRUCTIONRESULTPROCESSOR_H
#include "atccsdataprocessor.h"
class ATCCSUpgoingController;
class ATCCSInstructionResultProcessor : public ATCCSDataProcessor
{
public:
    explicit ATCCSInstructionResultProcessor(ATCCSUpgoingController *controller = nullptr);
    void processData(std::shared_ptr<ATCCSData> data);

private:
    ATCCSUpgoingController *_controller = nullptr;
};
#endif // ATCCSINSTRUCTIONRESULTPROCESSOR_H
