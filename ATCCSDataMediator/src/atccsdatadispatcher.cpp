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
#ifdef OUTERRORINFO
    std::cout << "~ATCCSDataDispatcher" << std::endl;
#endif
}

/**
 * -----------------------------------------------------------------------------
 * @brief       Thread function, This function will be executed in a new thread.
 * -----------------------------------------------------------------------------
 * @access      public
 * -----------------------------------------------------------------------------
 */
void ATCCSDataDispatcher::run()
{
    _dataQueue = ATCCSDataQueue::instance();
    if (_dataQueue)
    {
        try
        {
            while (!stop())
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
                    ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                        __FILE__, __func__, __LINE__,
                                                        "ATCCSDataProcessor instance is null, can not process and dispatch data.");
#endif
                }
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSDataQueue instance is null, can not dispatch data, thread ATCCSDataDispatcher is canceled.");
#endif        
    }
}

/**
 * -----------------------------------------------------------------------------
 * @brief       dispatch data to ATCCSController according to id
 * -----------------------------------------------------------------------------
 * @access      public
 * -----------------------------------------------------------------------------
 * @param id    The ATCCSController's id
 * @param data  The pending data
 * -----------------------------------------------------------------------------
 */
void ATCCSDataDispatcher::dispatchControlData(unsigned int id, std::shared_ptr<ATCCSData> data)
{
    if(_controllerManager)
    {
        std::shared_ptr<ATCCSController> temp = _controllerManager->controller(id);
        if(temp)
        {
            temp->pushControlData(data);
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "There is no such ATCCSController, ATCCSData can not be dispatched.");
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSMapManager is null, can not find ATCCSController.");
#endif
    }
}

/**
 * -----------------------------------------------------------------------------
 * @brief       set The ATCCSDataDispatcher's ATCCSDataProcessor
 * -----------------------------------------------------------------------------
 * @access      public
 * -----------------------------------------------------------------------------
 * @param processor The ATCCSDataProcessor's instance that process the ATCCSData and decide
 *  how to dispatch the ATCCSData.
 * -----------------------------------------------------------------------------
 */
void ATCCSDataDispatcher::setDataProcessor(std::shared_ptr<ATCCSDataProcessor> processor) 
{
    if(processor)
        _dataProcessor = processor;
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSDataProcessor is null, set value failed.");
#endif
    }
}

/**
 * -----------------------------------------------------------------------------
 * @brief       register ATCCSController to ATCCSDataDispatcher
 * -----------------------------------------------------------------------------
 * @access      public
 * -----------------------------------------------------------------------------
 * @param id    The ATCCSController's id
 * @param controller    The ATCCSController's instance
 */
void ATCCSDataDispatcher::registerDeviceController(unsigned int id, std::shared_ptr<ATCCSController> controller)
{
    if(_controllerManager == nullptr)
        _controllerManager = controllerManagerInstance();    
    if(_controllerManager)
        _controllerManager->registerController(id, controller);
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSMapManager is null, can not register ATCCSController.");
#endif
    }
}

std::shared_ptr<ATCCSMapManager<ATCCSController> > ATCCSDataDispatcher::controllerManagerInstance()
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif
        }
    }
    return _controllerManager;
}
