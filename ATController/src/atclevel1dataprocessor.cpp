#include "atclevel1dataprocessor.h"
#include "atccsdatadispatcher.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
ATCLevel1DataProcessor::ATCLevel1DataProcessor(std::shared_ptr<ATCCSDataDispatcher> dispatcher)
    : _dispatcher(dispatcher.get())
{

}


void ATCLevel1DataProcessor::processData(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || !(data->validate()))
        return;
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(header && _dispatcher)
    {
        if(header->msg == ATINSTRUCTION)
        {
            _dispatcher->dispatchControlData(header->AT.device, data);
        }
        else
        {
            _dispatcher->dispatchControlData(header->msg, data);
        }
    }
}
