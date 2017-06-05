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
    ATCCSSlaveDomeController();
    virtual ~ATCCSSlaveDomeController();
    
    bool isStatusOK() const override;
    bool isExecutoryInstructionOK() override;
    bool canExecutePlan() override;

protected:
    virtual bool checkResult_Connect();
    virtual bool checkResult_ScuttleAction();
    virtual bool checkResult_SetDomePosition();
    virtual bool checkResult_SetRotatePosition();
    virtual bool checkResult_SetShadePosition();
    virtual bool checkResult_ShadeAction();
    virtual bool checkResult_Stop();
};

#endif /* ATCCSSLAVEDOMECONTROLLER_H */

