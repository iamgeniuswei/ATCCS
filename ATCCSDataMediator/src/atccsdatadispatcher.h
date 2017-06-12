#ifndef ATCONTROLLER_H
#define ATCONTROLLER_H

#include <map>
#include "atccsthread.h"
#include <memory>
#include <mutex>
#include "atccsmapmanager.h"
class ATCCSDataQueue;
class ATCCSData;
class ATCCSController;
class ATCCSDataProcessor;

/*
 * -----------------------------------------------------------------------------
 * ATCCSDataDispatcher is a sub-class of ATCCSThread, and executes in a new 
 * thread. Its function is to dispatch "ATCCSData" received by ATCCSDataReceiver
 * to the according device controller. 
 * -----------------------------------------------------------------------------
 * @author: Geniuswei
 * @date:   2017-05-24
 * -----------------------------------------------------------------------------
 */
class ATCCSDataDispatcher : public ATCCSThread
{
public:
    explicit ATCCSDataDispatcher();    
    ~ATCCSDataDispatcher();
    void run() override;
    void dispatchControlData(unsigned int id, std::shared_ptr<ATCCSData> data);
    void registerDeviceController(unsigned int id, std::shared_ptr<ATCCSController> controller = nullptr);
    void setDataProcessor(std::shared_ptr<ATCCSDataProcessor> processor = nullptr);

private:
    ATCCSDataQueue *_dataQueue = nullptr;
    std::shared_ptr<ATCCSMapManager<ATCCSController>> _controllerManager = nullptr;
    std::shared_ptr<ATCCSDataProcessor> _dataProcessor = nullptr;
};

#endif // ATCONTROLLER_H
