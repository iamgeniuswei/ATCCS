#ifndef ATCCSINSTRUCTION_H
#define ATCCSINSTRUCTION_H

#include <odb/core.hxx>
#include <string>
#include <memory>
#include "atccs_public_define.h"

#include <iostream>

class ATCCSData;
#pragma db object
class atccsinstruction
{
public:
    enum ENUM_AT_INSTRUCTION_RESULT
    {
        RESULT_WAITINGTOEXECUTE = 0,     // =0
        RESULT_EXECUTING,         // =1
        RESULT_PARAMOUTOFRANGE, // =2
        RESULT_CANNTEXECUTE,    // =3
        RESULT_SENDERROR,       // =4    
        RESULT_SIZEERROR,       // =5
        RESULT_SUCCESS,         // =6
        RESULT_TIMEOUT          // =7
    };
    enum ENUM_AT_INSTRUCTION_VALIDATION
    {
        INSTRUCTION_UNKOWNN = 0,  // =0
        INSTRUCTION_PASS = 1,     // =1
        INSTRUCTION_PARAMOUTOFRANGE,   // =2
        INSTRUCTION_SIZEERROR     // =3
    };
    explicit atccsinstruction();
    virtual ~atccsinstruction();
    unsigned int setInstructionValue(std::shared_ptr<ATCCSData> data = nullptr);
    unsigned int setInstructionResult(std::shared_ptr<ATCCSData> data = nullptr);
    virtual unsigned long long persistInstruction() = 0;
    virtual void persistInstructionResult() = 0;
    void out()
    {
        std::cout <<"id:"<< _id << "- sec:" << _sec << "- msec:" << _msec << "- user:" << _user << "- at:" << _at << "- device:"
                << _device << "- sequence:" << _sequence << "- plan:" << _plan << "- instruction:" << _instruction
                << "- param:" << _param << "- result: "<<_result << std::endl;
    }


    unsigned int sec() const;
    void setSec(const unsigned int sec);

    unsigned int msec() const;
    void setMsec(const unsigned int msec);

    unsigned int user() const;
    void setUser(const unsigned int user);

    unsigned short device() const;
    void setDevice(const unsigned short device);

    unsigned int sequence() const;
    void setSequence(const unsigned int sequence);

    unsigned int plan() const;
    void setPlan(const unsigned int plan);

    unsigned int instruction() const;

    std::string param() const;
    void setParam(const std::string &param);

    unsigned int result() const;
    void setResult(const unsigned int result);
    void setAT(unsigned short _at);
    unsigned short at() const;
    unsigned int timeout() const;
    
private:
    unsigned int validateParam(unsigned int  device = 0, unsigned int  instruction = 0, std::shared_ptr<ATCCSData> data = nullptr);
    unsigned int  validateGimbalParam(unsigned int  instruction = 0, std::shared_ptr<ATCCSData> data = nullptr);
    unsigned int  validateCCDParam(unsigned int  instruction = 0, std::shared_ptr<ATCCSData> data = nullptr);
    unsigned int validateFilterParam(unsigned int  instruction = 0, std::shared_ptr<ATCCSData> data = nullptr);
    unsigned int validateFocusParam(unsigned int  instruction = 0, std::shared_ptr<ATCCSData> data = nullptr);
    unsigned int validateSlaveDomeParam(unsigned int  instruction = 0, std::shared_ptr<ATCCSData> data = nullptr);
    unsigned int validateFullOpenedDomeParam(unsigned int  instruction = 0, std::shared_ptr<ATCCSData> data = nullptr);
    
private:
    friend class odb::access;
#pragma db id auto
    unsigned long long _id = 0;
    unsigned int _sec = 0;
    unsigned int _msec = 0;
    unsigned int _user = 0;
    unsigned short _at = 0;
    unsigned short _device = 0;
    unsigned int _sequence = 0;
    unsigned int _timeout = 30;
    unsigned int _plan = 0;
    unsigned int _instruction = 0;
    std::string _param;
    unsigned int _result = 0;
};

#endif // ATCCSINSTRUCTION_H
