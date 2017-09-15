#ifndef ATCCSPLANPERFORMER_H
#define ATCCSPLANPERFORMER_H

#include "atccscontroller.h"
#include "atccsthread.h"
#include <memory>
#include "atccsmapmanager.h"
#include "atccsdevicecontroller.h"
#include "atccsplaninstruction.h"
class atccsplan;
class ATCCSDeviceController;


class ATCCSPlanPerformer : public ATCCSController, public ATCCSThread
{

    enum ENUM_AT_PLAN_STRATEGY
    {
        SINGLE = 0x01,
        SINGLELOOP,
        SEQUENCE,
        SEQUENCELOOP
    };

    enum ENUM_AT_PLAN_INSTRUCTION
    {
        START = 0x01,
        STOP,
        NEXT
    };
    
public:
    ATCCSPlanPerformer(unsigned short at = 0);
    ~ATCCSPlanPerformer();
    void run() override;    
    void registerDeviceController(unsigned int id, std::shared_ptr<ATCCSDeviceController> controller = nullptr);
    unsigned short at() const;
    void updateInstruction(std::shared_ptr<ATCCSData> data = nullptr);
    
protected:
    bool canExecutePlan() const;
    void executeSinglePlan();
    void executeSingleLoopPlan();
    void executeSequencePlan();
    void executeSequenceLoopPlan();
    bool updatePlanData(std::shared_ptr<ATCCSData> data = nullptr);
    void executePlanInSequence();
    void executeAPlanWithDebug();
    void executePlanInParallel();
    
private:
    void persistPlan();    
    bool setDeviceInstruction(unsigned int device = 0, unsigned int instruction = 0);
    bool setGimbalInstruction(unsigned int instruction = 0);
    bool setCCDInstruction(unsigned int instruction = 0);
    bool setFilterInstruction(unsigned int instruction = 0);
    bool waitInstructionFinish(unsigned int device, unsigned int instruction = 0);

    

protected:
    virtual std::shared_ptr<atccsplan> executoryPlanInstance();
    virtual bool isRelatedDevicesReady();
    

protected:
    std::shared_ptr<atccsplan> _executoryPlan = nullptr;    
    std::shared_ptr<atccsplan> _lastPlan = nullptr;
    std::shared_ptr<ATCCSMapManager<ATCCSDeviceController>> _controllers;
    std::shared_ptr<atccsplaninstruction> _instruction = nullptr;    
    unsigned short _at = 0;
};

#endif // ATCCSPLANPERFORMER_H
