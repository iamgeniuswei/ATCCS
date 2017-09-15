#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H
#include "atccscontroller.h"
#include "atccsthread.h"
#include <memory>
#include <mutex>
#include <stdbool.h>
class ATCCSData;
class atccsinstruction;
class ATCCSDataSender;
class atccspublicstatus;
class ATCCSOnline;
class ATCCSAddress;


/**
 * 望远镜设备控制基类,完成望远镜设备控制的核心功能.
 */
class ATCCSDeviceController : public ATCCSController, public ATCCSThread
{
public:
    explicit ATCCSDeviceController(unsigned short at = 0, unsigned short device = 0);
    virtual ~ATCCSDeviceController();
    void run() override;
    void setDeviceAddress(const std::string &ip, unsigned short port);
    void setDeviceAddress(std::shared_ptr<ATCCSAddress> address = nullptr);
    void updateRealtimeStatus(std::shared_ptr<ATCCSData> data = nullptr);
    void updateRealtimeOnline(bool online, unsigned int time);    
    
    virtual bool isOnline() const;
    virtual bool isStatusOK() const;
    virtual bool isInstructionSuccess(std::shared_ptr<atccsinstruction> instruction = nullptr, std::shared_ptr<ATCCSData> rawData = nullptr);
    
    virtual bool canExecuteInstruction() const;
    virtual bool canExecutePlan();
    unsigned int at() const;
    unsigned int device() const;
    unsigned int timeout();
    int sendInstruction(std::shared_ptr<ATCCSData> data = nullptr);
    bool handlePlanInstruction(std::shared_ptr<ATCCSData> data = nullptr);
    bool queryPlanInstructionResult();
    void persistPlanInstructionResult(bool success = true);
protected:
    void resolveData(std::shared_ptr<ATCCSData> data = nullptr);
    void handleInstructionResult(std::shared_ptr<ATCCSData> data = nullptr);
    void handleIndependentInstrutcion(std::shared_ptr<ATCCSData> data = nullptr);
    unsigned int updateIndependentInstruction(std::shared_ptr<ATCCSData> data = nullptr);
    unsigned int updateInstruction(std::shared_ptr<ATCCSData> data = nullptr, std::shared_ptr<atccsinstruction> instruction = nullptr);
    void updateInstructionResult(std::shared_ptr<ATCCSData> data = nullptr, std::shared_ptr<atccsinstruction> instruction = nullptr);
    void updateIndependentInstructionResult(std::shared_ptr<ATCCSData> data = nullptr);

    virtual std::shared_ptr<atccsinstruction> instructionInstance();
    virtual std::shared_ptr<atccspublicstatus> statusInstance();

    inline bool cmpDouble(double a, double b, double precision)
    {
        return ((a-b)>=(precision*-1)) && ((a-b) <= precision);
    }

    

protected:
    unsigned int _device = 0;
    unsigned int _at = 0;
    mutable std::mutex _statusLock;
    mutable std::mutex _instructionLock;

    std::shared_ptr<ATCCSDataSender>     _instructionSender = nullptr;
    std::shared_ptr<atccspublicstatus>  _realtimeStatus = nullptr;
    std::shared_ptr<ATCCSOnline>    _realtimeOnline = nullptr;
    std::shared_ptr<atccsinstruction> _independentInstruction = nullptr;
    std::shared_ptr<atccsinstruction> _planInstruction = nullptr;
    std::shared_ptr<ATCCSData> _planInstructionRawData = nullptr;
    unsigned int _timeout = 30;
    static unsigned int INSTRUCTION_TIMEOUT;
    static unsigned int INSTRUCTION_RETRANSMISSION;    
};

#endif // DEVICECONTROLLER_H
