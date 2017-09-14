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
    unsigned int updateExecutoryInstruction(std::shared_ptr<ATCCSData> data = nullptr);
    void setExecutoryInstructionResult(std::shared_ptr<ATCCSData> data = nullptr);
    
    void setPlanning(bool planning)
    {
        _isPlanning = planning;
    }
    
    virtual bool isOnline() const;
    virtual bool isStatusOK() const;
    virtual bool isExecutoryInstructionOK();
    virtual bool isExecutoryInstructionOK(unsigned int instruction);
    virtual bool canExecuteInstruction() const;
    virtual bool canExecutePlan();
    unsigned int at() const;
    unsigned int device() const;
    unsigned int timeout();
    bool isExecutoryInstructionSuccess(unsigned int instruction) const;
    bool isExecutoryInstructionFinished(unsigned int instructon) const;
    
    
protected:
    void executeInstruction(std::shared_ptr<ATCCSData> data = nullptr);
    void executeIndependentInstruction(std::shared_ptr<ATCCSData> data = nullptr);
    virtual std::shared_ptr<atccsinstruction> instructionInstance();
    virtual std::shared_ptr<atccspublicstatus> statusInstance();
    int sendInstruction(std::shared_ptr<ATCCSData> data = nullptr);
    void waitInstructionResult();
    inline bool cmpDouble(double a, double b, double precision)
    {
        return ((a-b)>=(precision*-1)) && ((a-b) <= precision);
    }

    

protected:
    unsigned int _device = 0;
    unsigned int _at = 0;
    mutable bool _currentStatusOK = false;
    mutable bool _isExecutoryInstructionSuccess = false;
    mutable bool _isExecutoryInstructionDone = false;
    volatile bool _isPlanning = false;
    mutable std::mutex _statusLock;
    mutable std::mutex _instructionLock;

    std::shared_ptr<ATCCSDataSender>     _instructionSender = nullptr;
    std::shared_ptr<atccsinstruction>   _executoryInstruction = nullptr;
    std::shared_ptr<ATCCSData>      _executoryInstructionRawData = nullptr;
    std::shared_ptr<atccspublicstatus>  _realtimeStatus = nullptr;
    std::shared_ptr<ATCCSOnline>    _realtimeOnline = nullptr;
    unsigned int _timeout = 30;
    static unsigned int INSTRUCTION_TIMEOUT;
    static unsigned int INSTRUCTION_RETRANSMISSION;    
};

#endif // DEVICECONTROLLER_H
