#ifndef REPORTCONTROLLER_H
#define REPORTCONTROLLER_H

#include "atccscontroller.h"
#include "atccsthread.h"
#include <memory>
#include <map>
#include "atccsqueue.h"
#include "atccsmapmanager.h"
class ATCCSDeviceController;
class ATCCSDataProcessor;
class ATCCSUpgoingDataProcessor;
class ATCCSUpgoingController : public ATCCSController, public ATCCSThread
{
public:
    explicit ATCCSUpgoingController();
    ~ATCCSUpgoingController();
    void run() override;


    void processUpgoingData(unsigned int id, std::shared_ptr<ATCCSData> data);
    void setDeviceOnline(unsigned int id, bool online, unsigned int time);
    void setInstructionResult(unsigned int id, std::shared_ptr<ATCCSData> data = nullptr);
    void setDeviceStatus(unsigned int id, std::shared_ptr<ATCCSData> data = nullptr);

    void registerDataProcessor(unsigned int id, std::shared_ptr<ATCCSDataProcessor> processor = nullptr);
    void registerDeviceController(unsigned int id, std::shared_ptr<ATCCSDeviceController> controller = nullptr);


private:    
    std::shared_ptr<ATCCSMapManager<ATCCSDeviceController>> _controllerManager = nullptr;
    std::shared_ptr<ATCCSMapManager<ATCCSDataProcessor>> _processors = nullptr;
    std::shared_ptr<ATCCSUpgoingDataProcessor> _dataProcessor = nullptr;
};

#endif // REPORTCONTROLLER_H
