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
    void registerDeviceController(unsigned int id, std::shared_ptr<ATCCSDeviceController> controller = nullptr);
    unsigned short at() const;
    
protected:
    bool canExecutePlan() const;
    void executePlan(std::shared_ptr<ATCCSData> data = nullptr);   
    
private:
    void resetDeviceInstruction(unsigned int device = 0);    
    bool setDeviceInstruction(unsigned int device = 0, unsigned int instruction = 0);
    bool setGimbalInstruction(unsigned int instruction = 0);
    bool setCCDInstruction(unsigned int instruction = 0);
    bool waitInstructionFinish(unsigned int device, unsigned int instruction = 0);

    

protected:
    virtual std::shared_ptr<atccsplan> executoryPlanInstance();
    virtual bool isRelatedDevicesReady();
    

protected:
    std::shared_ptr<atccsplan> _executoryPlan = nullptr;    
    std::shared_ptr<atccsplan> _lastPlan = nullptr;
    std::shared_ptr<ATCCSMapManager<ATCCSDeviceController>> _controllers;
    mutable volatile bool _nextPlanOK;
    unsigned short _at = 0;
};

#endif // ATCCSPLANCONTROLLER_H
