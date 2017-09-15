/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60CCDController.h
 * Author: lenovo
 *
 * Created on May 14, 2017, 11:05 AM
 */

#ifndef ATCCSCCDCONTROLLER_H
#define ATCCSCCDCONTROLLER_H

#include "atccsdevicecontroller.h"

class ATCCSCCDController : public ATCCSDeviceController
{
public:
    ATCCSCCDController(unsigned short at = 0, unsigned short device = 0);
    virtual ~ATCCSCCDController();
    
    bool isStatusOK() const override;
    bool isInstructionSuccess(std::shared_ptr<atccsinstruction> instruction = nullptr, std::shared_ptr<ATCCSData> rawData = nullptr) override;

    bool canExecutePlan() override;

protected:
    virtual bool checkResult_Connect(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetCoolerT(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetExposureTactics(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_StartExposure(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_StopExposure(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_AbortExposure(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetGain(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetReadSpeedMode(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetTransferSpeed(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetBIN(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetROI(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetShutter(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetFullFrame(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetEM(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetCMOSNF(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetBaseline(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetOverScan(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
private:

};

#endif /* AT60CCDCONTROLLER_H */

