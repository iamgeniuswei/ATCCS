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
ATCCSUpgoingController::ATCCSUpgoingController()
{
    try
    {        
        _controllerManager = std::make_shared<ATCCSMapManager<ATCCSDeviceController>>();
        _processors = std::make_shared<ATCCSMapManager<ATCCSDataProcessor>>();
        _dataProcessor = std::make_shared<ATCCSUpgoingDataProcessor>(this);
        std::shared_ptr<ATCCSHeartbeatProcessor> heartbeat (new ATCCSHeartbeatProcessor(this)) ;
        std::shared_ptr<ATCCSInstructionResultProcessor> instructionResult(new ATCCSInstructionResultProcessor(this));
        std::shared_ptr<ATCCSDeviceStatusProcessor> status ( new ATCCSDeviceStatusProcessor(this));
        registerDataProcessor(ATHEARTBEAT, heartbeat);
        registerDataProcessor(ATINSTRUCTIONACK, instructionResult);
        registerDataProcessor(ATSTATUSREPORT, status);
    }
    catch(std::exception &e)
    {
#ifdef OUTDEBUGINFO
        std::cerr << "error#1: " << e.what()
                << " @" << __func__
                << " @" << __FILE__
                << " @" << __LINE__ << std::endl;
#endif
    }
}

ATCCSUpgoingController::~ATCCSUpgoingController()
{
#ifdef OUTDEBUGINFO
    std::cerr << "~ATCCSUpgoingController()" << std::endl;
#endif
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
        std::shared_ptr<ATCCSData> data = _fifoQueue.wait_and_pop();
        if(data == nullptr)
            continue;
        if(_dataProcessor)
        {
            _dataProcessor->processData(data);
        }
        else
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error: ATCCSUpgoingDataProcessor is null; " 
                    << " @" << __func__ 
                    << " @" << __FILE__ 
                    << " @" << __LINE__ << std::endl;
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
    if(_processors)
    {
        std::shared_ptr<ATCCSDataProcessor> handler = _processors->controller(id);
        if(handler)
        {
            handler->processData(data);
        }
        else
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error: no such ATCCSDataProcessor; " << " @" <<__func__ << " @" << __FILE__ << " @" << __LINE__ << std::endl;
#endif
        }        
    }
    else
    {
#ifdef OUTDEBUGINFO
        std::cerr << "error: ATCCSControllerManager is null; " << " @" <<__func__ << " @" << __FILE__ << " @" << __LINE__ << std::endl;
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
    if(_controllerManager)
    {
        std::shared_ptr<ATCCSDeviceController> controller = _controllerManager->controller(id);
        if(controller)
            controller->setRealtimeOnline(online, time);
        else
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error: no such ATCCSDeviceController; " << " @" <<__func__ << " @" << __FILE__ << " @" << __LINE__ << std::endl;
#endif
        }
    }
    else
    {
#ifdef OUTDEBUGINFO
        std::cerr << "error: ATCCSControllerManager is null; " << " @" <<__func__ << " @" << __FILE__ << " @" << __LINE__ << std::endl;
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
    if(_controllerManager)
    {
        std::shared_ptr<ATCCSDeviceController> controller = _controllerManager->controller(id);
        if(controller)
            controller->setExecutoryInstructionResult(data);
        else
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error: no such ATCCSDeviceController; " << " @" <<__func__ << " @" << __FILE__ << " @" << __LINE__ << std::endl;
#endif
        }
    }
    else
    {
#ifdef OUTDEBUGINFO
        std::cerr << "error: ATCCSControllerManager is null; " << " @" <<__func__ << " @" << __FILE__ << " @" << __LINE__ << std::endl;
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
    if(_controllerManager)
    {
        std::shared_ptr<ATCCSDeviceController> controller = _controllerManager->controller(id);
        if(controller)
            controller->setRealtimeStatus(data);
        else
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error: no such ATCCSDeviceController; " << " @" <<__func__ << " @" << __FILE__ << " @" << __LINE__ << std::endl;
#endif
        }
    }
    else
    {
#ifdef OUTDEBUGINFO
        std::cerr << "error: ATCCSControllerManager is null; " << " @" <<__func__ << " @" << __FILE__ << " @" << __LINE__ << std::endl;
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
    if(_processors)
        _processors->registerController(id, processor);
}



/**
 * @brief This function registers the variable device controllers
 * @param id, The device controller's id (according to ENUM_AT_AT_TYPE)
 * @param controller, The device controller.
 */
void ATCCSUpgoingController::registerDeviceController(unsigned int id, std::shared_ptr<ATCCSDeviceController> controller)
{
    if(_controllerManager)
        _controllerManager->registerController(id, controller);
}


