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
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s",
                                            gettext("Fails to initialize the upgoing data processors."));
#endif 
    }
}

ATCCSUpgoingController::~ATCCSUpgoingController()
{

}

/**
 * @brief This function is executed in a new thread.
 * process the 'data' which is dispatched by ATCCSDataDispatcher.
 * 
 */
void ATCCSUpgoingController::run()
{

    while (!stop())
    {
        try
        {
            std::shared_ptr<ATCCSData> data = popControlData();
            if (data == nullptr)
                continue;
            if(!data->validate())
                continue;
            
            _ATCCSPHeader *header = (_ATCCSPHeader*) (data->data());
            processUpgoingData(header->msg, data);

        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%s",
                                                gettext("Fails to process upgoing data."), e.what());
#endif
        }
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
        try
        {
            std::shared_ptr<ATCCSDataProcessor> handler = _processors->controller(id);
            if (handler)
            {
                handler->processData(data);
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d",
                                                    gettext("Fails to find upgoing data processor. upgoing data: "), id);
#endif
            }
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d",
                                                gettext("Fails to process upgoing data. upgoing data: "), id);
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d",
                                           gettext("The upgoing data processors' manager is fail to be created, fails to process upgoing data. upgoing data: "), id);
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
        try
        {
            std::shared_ptr<ATCCSDeviceController> controller = _controllerManager->controller(id);
            if (controller)
            {
                controller->updateRealtimeOnline(online, time);
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d",
                                                    gettext("Fails to find AT Controller and set device online status. Device: "), id);
#endif
            }
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d",
                                                    gettext("Fails to set device online status. Device: "), id);
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d",
                                           gettext("The AT Controllers' manager is fail to be created, fails to set device online status. Device: "), id);
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
//    if (_controllerManager)
//    {
//        try
//        {
//            std::shared_ptr<ATCCSDeviceController> controller = _controllerManager->controller(id);
//            if (controller)
//            {
//                controller->setExecutoryInstructionResult(data);
//            }
//            else
//            {
//#ifdef OUTERRORINFO
//                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d",
//                                                    gettext("Fails to find AT Controller and set device's instruction result. Device: "), id);
//#endif
//            }
//        }
//        catch(std::exception &e)
//        {
//#ifdef OUTERRORINFO
//            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d",
//                                                    gettext("Fails to set device's instruction result. Device: "), id);
//#endif            
//        }
//    }
//    else
//    {
//#ifdef OUTERRORINFO
//        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d",
//                                           gettext("The AT Controllers' manager is fail to be created, fails to set device's instruction result. Device: "), id);
//#endif
//    }
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
        try
        {
            std::shared_ptr<ATCCSDeviceController> controller = _controllerManager->controller(id);
            if (controller)
            {
                controller->updateRealtimeStatus(data);
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d",
                                                    gettext("Fails to find AT Controller and set device's status. Device: "), id);
#endif
            }
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d",
                                                    gettext("Fails to set device's status. Device: "), id);
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d",
                                           gettext("The AT Controllers' manager is fail to be created, fails to set device's status. Device: "), id);
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s",
                                                gettext("The upgoing data processors' manager is fail to be created, fails to register upgoing data processor. upgoing data: "), id,
                                                e.what());
#endif
            return;
        }
    }
    try
    {
        _processors->registerController(id, processor);
    }
    catch(std::exception &e)
    {
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s",
                                            gettext("Fails to register upgoing data processor. upgoing data: "), id,
                                            e.what());
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
#ifdef OUTDEBUGINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s",
                                                gettext("The AT Controllers' manager is fail to be created, fails to register AT Controller. Device: "), id,
                                                e.what());
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
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s",
                                            gettext("Fails to register AT Controller. Device: "), id,
                                            e.what());
#endif        
    }
}


