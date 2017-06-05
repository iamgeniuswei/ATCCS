#ifndef ATCCSPLANCONTROLLER_H
#define ATCCSPLANCONTROLLER_H

#include "atccscontroller.h"
#include "atccsthread.h"
#include <memory>
#include "atccsmapmanager.h"
class atccsplan;
class ATCCSDeviceController;


class ATCCSPlanController : public ATCCSController, public ATCCSThread
{
public:
    ATCCSPlanController();
    void handleControlData();
    
    
    bool nextOK() const;
    bool exposureOK() const;
    bool abortExposureOK() const;
    bool stopExposureOK() const;
    void dispatchControlData(unsigned int id, std::shared_ptr<ATCCSData> data = nullptr);
    void controlPlan(std::shared_ptr<ATCCSData> data = nullptr);
    void registerDeviceController(unsigned int id, std::shared_ptr<ATCCSDeviceController> controller = nullptr);
private:
    void resetDeviceInstruction(unsigned int device = 0);
    void setDeviceInstruction(unsigned int device = 0, unsigned int instruction = 0);
    bool waitInstructionOK(unsigned int device);

    bool isDeviceReady();



private:
    std::shared_ptr<atccsplan> _curPlan = nullptr;
    std::shared_ptr<atccsplan> _lastPlan = nullptr;
    std::shared_ptr<ATCCSMapManager<ATCCSDeviceController>> _controllers;
    mutable volatile bool _nextPlanOK;
};

#endif // ATCCSPLANCONTROLLER_H
