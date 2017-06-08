#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H
#include "atccscontroller.h"
#include "atccsthread.h"
#include <memory>
#include <mutex>
class ATCCSData;
class atccsinstruction;
class ATCCSDataSender;
class atccspublicstatus;
class ATCCSOnline;
class ATCCSAddress;
class ATCCSDeviceController : public ATCCSController, public ATCCSThread
{
public:
    explicit ATCCSDeviceController(unsigned short id);
    virtual ~ATCCSDeviceController();
    void run() override;
    void setDeviceAddress(const std::string &ip, unsigned short port);
    void setDeviceAddress(std::shared_ptr<ATCCSAddress> address = nullptr);
    void setRealtimeStatus(std::shared_ptr<ATCCSData> data = nullptr);
    void setRealtimeOnline(bool online, unsigned int time);
    unsigned int setExecutoryInstruction(std::shared_ptr<ATCCSData> data = nullptr);
    void setExecutoryInstructionResult(std::shared_ptr<ATCCSData> data = nullptr);
    

    
    virtual bool isOnline() const;
    virtual bool isStatusOK() const;
    virtual bool isExecutoryInstructionOK();
    virtual bool isExecutoryInstructionOK(unsigned int instruction);
    virtual bool canExecuteInstruction() const;
    virtual bool canExecutePlan();
    unsigned int id() const;
    unsigned int timeout();
    
    
protected:    
    virtual std::shared_ptr<atccsinstruction> instructionInstance();
    virtual std::shared_ptr<atccspublicstatus> statusInstance();
    int sendInstruction(std::shared_ptr<ATCCSData> data = nullptr);
    void waitInstructionResult();
    inline bool cmpDouble(double a, double b, double precision)
    {
        return ((a-b)>=(precision*-1)) && ((a-b) <= precision);
    }

    

protected:
    unsigned int _id = 0;
    mutable bool _currentStatusOK;
    mutable bool _nextInstructionOK;
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
