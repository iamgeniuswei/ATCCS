#include "atccsdatadispatcherprocessor.h"
#include "atccsdatadispatcher.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccsexceptionhandler.h"
ATCCSDataDispatcherProcessor::ATCCSDataDispatcherProcessor(std::shared_ptr<ATCCSDataDispatcher> dispatcher)
    : _dispatcher(dispatcher.get())
{

}


void ATCCSDataDispatcherProcessor::processData(std::shared_ptr<ATCCSData> data)
{
    if(_dispatcher == nullptr)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                            __FILE__, __func__, __LINE__, 
                                            "ATCCSDataDispatcher instance is null, ATCCSData can not be dispatched.");
#endif
    }
    
    if(data == nullptr)
        return;

    if(!data->validate())
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                            __FILE__, __func__, __LINE__, 
                                            "ATCCSData is error, can not be dispatched.");
#endif
        return;
    }
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(header)
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
