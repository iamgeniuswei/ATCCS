#include <locale>

#include "atccsdatadispatcher.h"
#include "atccsdataqueue.h"
#include "atccsdataprocessor.h"
#include "atccscontroller.h"
#include "atccs_global.h"
#include "atccsexception.h"
#include "atccsexceptionhandler.h"
ATCCSDataDispatcher::ATCCSDataDispatcher()
{
    
}

ATCCSDataDispatcher::~ATCCSDataDispatcher()
{

}

/**
 * Thread function, This function will be executed in a new thread.
 * run() will dispatch the ATCCSData in MSG Queue to the according 
 * device's fifo queue.
 * @access public
 */
void ATCCSDataDispatcher::run()
{
    _dataQueue = ATCCSDataQueue::instance();
    if (_dataQueue)
    {
        while(!stop())
        {
            try
            {
                std::shared_ptr<ATCCSData> data = _dataQueue->wait_and_pop();
                if (data == nullptr)
                    continue;
                if (_dataProcessor)
                {
                    _dataProcessor->processData(data);
                }
                else
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,"%s",
                                                        "The data processor is fail to create, fails to dispatch data.");
#endif
                }
            }
            catch(std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%s",
                                                    gettext("Fails to fetch data from MSG Queue."), e.what());
#endif                
            }
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                           gettext("The MSG Queue is fail to create, fails to execute data dispatcher thread."));
#endif        
    }
}

/**
 * dispatch data to ATCCSController according to id
 * @param id    The ATCCSController's id
 * @param data  The pending data
 * @access public
 */
void ATCCSDataDispatcher::dispatchControlData(unsigned int id, std::shared_ptr<ATCCSData> data)
{
    if(_controllerManager)
    {
        try
        {
            std::shared_ptr<ATCCSController> temp = _controllerManager->controller(id);
            if (temp)
            {
                temp->pushControlData(data);
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,"%s%d",
                                                    gettext("There is no such AT Controller, fails to dispatch data. The id is: "), id);
#endif
            }            
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s",
                                                gettext("Fails to find AT Controller and dispatch data. The id is: "), id, e.what());
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                            gettext("The AT Controllers' manager is null, fails to dispatch data."));
#endif
    }
}

/**
 * set the data processor
 * @param processor
 * @access public
 */
void ATCCSDataDispatcher::setDataProcessor(std::shared_ptr<ATCCSDataProcessor> processor) 
{
    if(processor)
    {
        _dataProcessor = processor;
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,"%s",
                                            gettext("The data processor is null, fails to set data processor."));                                            
#endif
    }
}

/**
 * register the AT Controller by the id
 * @param id    The AT Controller's id
 * @param controller    The AT Controller
 * @access public
 */
void ATCCSDataDispatcher::registerDeviceController(unsigned int id, std::shared_ptr<ATCCSController> controller)
{
    if(_controllerManager == nullptr)
    {
        try
        {
            _controllerManager = std::make_shared<ATCCSMapManager<ATCCSController>>();
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s",
                                                gettext("The AT Controllers' manager is fail to be created, fails to register AT Controller. The id is: "), id, e.what());
#endif
            return;
        }
        
    }
        
    try
    {
        _controllerManager->registerController(id, controller);
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s",
                                                gettext("Fails to register AT Controller. The id is: "), id, e.what());
#endif        
    }

}