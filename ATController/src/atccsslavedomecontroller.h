/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60SlaveDomeController.h
 * Author: lenovo
 *
 * Created on May 16, 2017, 7:13 PM
 */

#ifndef ATCCSSLAVEDOMECONTROLLER_H
#define ATCCSSLAVEDOMECONTROLLER_H

#include "atccsdevicecontroller.h"
class ATCCSSlaveDomeController : public ATCCSDeviceController
{
public:
    ATCCSSlaveDomeController(unsigned short at = 0, unsigned short device = 0);
    virtual ~ATCCSSlaveDomeController();
    
    bool isStatusOK() const override;
    bool isInstructionSuccess(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) override;

    bool canExecutePlan() override;

protected:
    virtual bool checkResult_Connect(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_ScuttleAction(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetDomePosition(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetRotatePosition(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetShadePosition(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_ShadeAction(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_Stop(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
};

#endif /* ATCCSSLAVEDOMECONTROLLER_H */

