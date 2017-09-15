/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60GimbalController.h
 * Author: lenovo
 *
 * Created on May 9, 2017, 11:00 AM
 */

#ifndef ATCCSGIMBALCONTROLLER_H
#define ATCCSGIMBALCONTROLLER_H
#include "atccsdevicecontroller.h"
#include "atccs_global.h"
class ATCCSData;
class ATCCSGimbalController : public ATCCSDeviceController
{
public:
    ATCCSGimbalController(unsigned short at = 0, unsigned short device = 0);
    virtual ~ATCCSGimbalController();    

    bool isStatusOK() const override;
    bool canExecutePlan() override;
    bool isInstructionSuccess(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) override;


protected:
    virtual bool checkResult_Connect(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_FindHome(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_TrackStar(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetObjectName(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SlewAzEl(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SlewDerotator(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_ConfigDerotator(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_Stop(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SpeedCorrect(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_Park(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_FixedMove(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_PositionCorrect(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_CoverAction(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_FocusAction(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_Emergence(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_ConfigProperty(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SaveSyncData(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
};

#endif /* AT60GIMBALCONTROLLER_H */

