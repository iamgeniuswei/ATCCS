/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60FocusController.h
 * Author: lenovo
 *
 * Created on May 16, 2017, 7:08 PM
 */

#ifndef ATCCSFOCUSCONTROLLER_H
#define ATCCSFOCUSCONTROLLER_H
#include "atccsdevicecontroller.h"

class ATCCSFocusController : public ATCCSDeviceController
{
public:
    ATCCSFocusController(unsigned short at = 0, unsigned short device = 0);
    virtual ~ATCCSFocusController();

    bool isStatusOK() const override;
    bool canExecutePlan() override;
    bool isInstructionSuccess(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) override;


protected:
    virtual bool checkResult_Connect(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_EnableTCompensate(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_FindHome(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetFixedSpeed(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetPostion(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetTCompensateCoefficiency(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_Stop(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);

};

#endif /* ATCCSFOCUSCONTROLLER_H */

