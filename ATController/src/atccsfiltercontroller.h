/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60FilterController.h
 * Author: lenovo
 *
 * Created on May 16, 2017, 7:06 PM
 */

#ifndef ATCCSFILTERCONTROLLER_H
#define ATCCSFILTERCONTROLLER_H
#include "atccsdevicecontroller.h"

class ATCCSFilterController : public ATCCSDeviceController
{
public:
    ATCCSFilterController(unsigned short at = 0, unsigned short device = 0);
    virtual ~ATCCSFilterController();    
    bool isStatusOK() const override;
    bool canExecutePlan() override;
    bool isInstructionSuccess(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) override;



protected:
    virtual bool checkResult_Connect(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_FindHome(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
    virtual bool checkResult_SetFilterPosition(std::shared_ptr<atccsinstruction> instruction = nullptr,
                                     std::shared_ptr<ATCCSData> rawData = nullptr);
};

#endif /* ATCCSFILTERCONTROLLER_H */

