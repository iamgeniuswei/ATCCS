#ifndef ATCCSPLANCONTROLLER_H
#define ATCCSPLANCONTROLLER_H

#include "atccscontroller.h"
#include "atccsthread.h"
#include <memory>
#include "atccsmapmanager.h"
#include "atccsdevicecontroller.h"
class atccsplan;
class ATCCSDeviceController;


class ATCCSPlanController : public ATCCSController, public ATCCSThread
{
public:
    ATCCSPlanController(unsigned short at = 0);
    ~ATCCSPlanController();
    void run() override;    
    
    bool canExecutePlan() const;
    bool exposureOK() const;
    bool abortExposureOK() const;
    bool stopExposureOK() const;
    void dispatchControlData(unsigned int id, std::shared_ptr<ATCCSData> data = nullptr);
    void controlPlan(std::shared_ptr<ATCCSData> data = nullptr);
    void registerDeviceController(unsigned int id, std::shared_ptr<ATCCSDeviceController> controller = nullptr);
    unsigned short at() const;
private:
    void resetDeviceInstruction(unsigned int device = 0);    
    void setDeviceInstruction(unsigned int device = 0, unsigned int instruction = 0);
    bool waitInstructionOK(unsigned int device, unsigned int instruction = 0);

    

protected:
    virtual std::shared_ptr<atccsplan> executoryPlanInstance();
    virtual bool isRelatedDevicesReady();
    std::shared_ptr<ATCCSMapManager<ATCCSDeviceController>> controllersInstance();
    

protected:
    std::shared_ptr<atccsplan> _executoryPlan = nullptr;    
    std::shared_ptr<atccsplan> _lastPlan = nullptr;
    std::shared_ptr<ATCCSMapManager<ATCCSDeviceController>> _controllers;
    mutable volatile bool _nextPlanOK;
    unsigned short _at = 0;
};

#endif // ATCCSPLANCONTROLLER_H
