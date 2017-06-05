#include "atccsdatadispatcher.h"
#include "atccsdataqueue.h"
#include "atccsdataprocessor.h"
#include "atccscontroller.h"
#include "atccs_global.h"
#include "atccsexception.h"
#include "atccsexceptionhandler.h"
ATCCSDataDispatcher::ATCCSDataDispatcher()
{
    try
    {
        _dataQueue = ATCCSDataQueue::instance();
        _controllerManager = std::make_shared<ATCCSMapManager<ATCCSController>>();
    }
    catch(std::exception &e)
    {
#ifdef OUTDEBUGINFO
        std::string debug_info;
        debug_info += e.what();
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::STDEXCEPTION, debug_info));
        ATCCSExceptionHandler::addException(e1);
#endif        
    }
}

ATCCSDataDispatcher::~ATCCSDataDispatcher()
{
#ifdef OUTDEBUGINFO
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
#ifdef OUTDEBUGINFO
                std::string debug_info;
                debug_info += "ATCCSDataProcessor is null, can not process ATCCSData.";
                debug_info += " @";
                debug_info += __func__;
                debug_info += " @";
                debug_info += __FILE__;
                std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::POINTERISNULL, debug_info));
                ATCCSExceptionHandler::addException(e1);
#endif
            }
        }
    }
    catch(std::exception &e)
    {
#ifdef OUTDEBUGINFO
        std::string debug_info;
        debug_info += e.what();
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::STDEXCEPTION, debug_info));
        ATCCSExceptionHandler::addException(e1);
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
#ifdef OUTDEBUGINFO
            std::string debug_info;
            debug_info += "no such ATCCSController.";
            debug_info += " @";
            debug_info += __func__;
            debug_info += " @";
            debug_info += __FILE__;
            std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::CUSTOMEXCEPTION, debug_info));
            ATCCSExceptionHandler::addException(e1);
#endif
        }
    }
    else
    {
#ifdef OUTDEBUGINFO
        std::string debug_info;
        debug_info += "ATCCSMapManager is null, can not dispatch ATCCSData. ";
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::POINTERISNULL, debug_info));
        ATCCSExceptionHandler::addException(e1);
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
#ifdef OUTDEBUGINFO
        std::string debug_info;
        debug_info += "ATCCSDataProcessor is null, set value failed.";
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::CUSTOMEXCEPTION, debug_info));
        ATCCSExceptionHandler::addException(e1);
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
    if(_controllerManager)
        _controllerManager->registerController(id, controller);
    else
    {
#ifdef OUTDEBUGINFO
        std::string debug_info;
        debug_info += "ATCCSMapManager is null, can not register ATCCSController. ";
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::POINTERISNULL, debug_info));
        ATCCSExceptionHandler::addException(e1);
#endif
    }
}