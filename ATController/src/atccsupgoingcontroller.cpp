#include "atccsupgoingcontroller.h"
#include "atccsdevicecontroller.h"
#include <memory>
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "qpudpsocket.h"
#include "atccs_gimbal_define.h"
#include "atccsdataprocessor.h"
#include "atccsheartbeatprocessor.h"
#include "atccsinstructionresultprocessor.h"
#include <iostream>
#include "atccsmapmanager.h"
#include "atccsdevicestatusprocessor.h"
#include "atccsupgoingdataprocessor.h"
#include "atccs_global.h"
#include "atccsexceptionhandler.h"

ATCCSUpgoingController::ATCCSUpgoingController()
{
    try
    {  
        _dataProcessor = std::make_shared<ATCCSUpgoingDataProcessor>(this);
        std::shared_ptr<ATCCSHeartbeatProcessor> heartbeat = std::make_shared<ATCCSHeartbeatProcessor>(this);
        std::shared_ptr<ATCCSInstructionResultProcessor> instructionResult = std::make_shared<ATCCSInstructionResultProcessor>(this);
        std::shared_ptr<ATCCSDeviceStatusProcessor> status = std::make_shared<ATCCSDeviceStatusProcessor>(this);
        registerDataProcessor(ATHEARTBEAT, heartbeat);
        registerDataProcessor(ATINSTRUCTIONACK, instructionResult);
        registerDataProcessor(ATSTATUSREPORT, status);
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
    }
}

ATCCSUpgoingController::~ATCCSUpgoingController()
{
#ifdef OUTDEBUGINFO
    std::cout << "~ATCCSUpgoingController" << std::endl;
#endif
}

/**
 * @brief This function is executed in a new thread.
 * process the 'data' which is dispatched by ATCCSDataDispatcher.
 * 
 */
void ATCCSUpgoingController::run()
{
    try
    {        
        while (!stop())
        {
            std::shared_ptr<ATCCSData> data = popControlData();
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
                                                    "ATCCSUpgoingDataProcessor instance is null, fails to process up-going ATCCSData.");
#endif            
            }
        }
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                    __FILE__, __func__, __LINE__, e.what());
#endif        
    }
}

/**
 * @brief This function is a callback function which is called in ATCCSUpgoingDataProcessor
 * @param id, The device's id.
 * @param data, The raw data received from device.
 */
void ATCCSUpgoingController::processUpgoingData(unsigned int id, std::shared_ptr<ATCCSData> data)
{
    if (_processors)
    {
        std::shared_ptr<ATCCSDataProcessor> handler = _processors->controller(id);
        if (handler)
        {
            handler->processData(data);
        }
        else
        {
#ifdef OUTERRORINFO
            char msg[256] = {0};
            snprintf(msg, 256, "%s%d%s", "MSG id is: ", id, ", there is no such ATCCSDataProcessor");
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                __FILE__, __func__, __LINE__, msg);
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSMapManager<ATCCSDataProcessor> instance is null, fails to process up-going data.");
#endif
    }

}

/**
 * @brief This function set the device's online state.
 * @param id, The device's id.
 * @param online, The device's online info.
 * @param time, The last online time. (UTC seconds)
 */
void ATCCSUpgoingController::setDeviceOnline(unsigned int id, bool online, unsigned int time)
{
    if (_controllerManager)
    {
        std::shared_ptr<ATCCSDeviceController> controller = _controllerManager->controller(id);
        if (controller)
        {
            controller->setRealtimeOnline(online, time);
        }
        else
        {
#ifdef OUTERRORINFO
            char msg[256] = {0};
            snprintf(msg, 256, "%s%d%s", "Device id is: ", id, ", there is no such ATCCSDeviceController, fails to setDeviceOnline");
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                __FILE__, __func__, __LINE__, msg);
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, 
                                            "ATCCSMapManager<ATCCSDeviceController> instance is null, fails to setDeviceOnline");
#endif
    }
}

/**
 * @brief This function set the device's current instruction result.
 * @param id, The device's id.
 * @param data, The raw data of the current instruction result.
 */
void ATCCSUpgoingController::setInstructionResult(unsigned int id, std::shared_ptr<ATCCSData> data)
{
    if (_controllerManager)
    {
        std::shared_ptr<ATCCSDeviceController> controller = _controllerManager->controller(id);
        if (controller)
        {
            controller->setExecutoryInstructionResult(data);
        }
        else
        {
#ifdef OUTERRORINFO
            char msg[256] = {0};
            snprintf(msg, 256, "%s%d%s", "Device id is: ", id, ", there is no such ATCCSDeviceController, fails to setInstructionResult");
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                __FILE__, __func__, __LINE__, msg);
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, 
                                            "ATCCSMapManager<ATCCSDeviceController> instance is null, fails to setInstructionResult");
#endif
    }
}

/**
 * @brief This function set the device's status.
 * @param id, The device's id.
 * @param data The raw data of the device's status.
 */
void ATCCSUpgoingController::setDeviceStatus(unsigned int id, std::shared_ptr<ATCCSData> data)
{
    if (_controllerManager)
    {
        std::shared_ptr<ATCCSDeviceController> controller = _controllerManager->controller(id);
        if (controller)
        {
            controller->setRealtimeStatus(data);
        }
        else
        {
#ifdef OUTERRORINFO
            char msg[256] = {0};
            snprintf(msg, 256, "%s%d%s", "Device id is: ", id, ", there is no such ATCCSDeviceController, fails to setDeviceStatus");
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                __FILE__, __func__, __LINE__, msg);
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, 
                                            "ATCCSMapManager<ATCCSDeviceController> instance is null, fails to setDeviceStatus");
#endif
    }
}

/**
 * @brief This function registers the subsequent data processors.
 * @param id, The data processor's id (according to ENUM_AT_MSG_TYPE)
 * @param processor, The data processor.
 */
void ATCCSUpgoingController::registerDataProcessor(unsigned int id, std::shared_ptr<ATCCSDataProcessor> processor)
{
    if(_processors == nullptr)
    {
        try
        {
            _processors = std::make_shared<ATCCSMapManager < ATCCSDataProcessor >> ();
        }
        catch(std::exception &e)
        {
#ifdef OUTDEBUGINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif
        }
    }
    
    if (_processors)
    {
        _processors->registerController(id, processor);
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSMapManager<ATCCSDataProcessor> instance is null, can not register ATCCSDataProcessor.");
#endif        
    }
}

/**
 * @brief This function registers the variable device controllers
 * @param id, The device controller's id (according to ENUM_AT_AT_TYPE)
 * @param controller, The device controller.
 */
void ATCCSUpgoingController::registerDeviceController(unsigned int id, std::shared_ptr<ATCCSDeviceController> controller)
{
    if (_controllerManager == nullptr)
    {
        try
        {
            _controllerManager = std::make_shared<ATCCSMapManager < ATCCSDeviceController >> ();
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif
            return;
        }
        
    }
    
    if (_controllerManager)
    {
        _controllerManager->registerController(id, controller);
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSMapManager<ATCCSDeviceController> instance is null, can not register ATCCSDeviceController.");
#endif        
    }
}


