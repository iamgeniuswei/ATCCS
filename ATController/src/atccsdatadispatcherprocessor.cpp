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
    if(data == nullptr)
        return;
    if(_dispatcher == nullptr)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                            gettext("The data dispatcher is fail to be created, fails to process ATCCSData."));
#endif
    }
    if(!data->validate())
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s",
                                            gettext("The ATCCSData is error and is neglected."));
#endif
        return;
    }
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(header)
    {
        if(header->msg == ATINSTRUCTION || header->msg == ATINSTRUCTIONACK || header->msg == ATSTATUSREPORT)
        {
            _dispatcher->dispatchControlData(header->AT.device, data);
        }        
        else
        {
            _dispatcher->dispatchControlData(header->msg, data);
        }
    }
}
