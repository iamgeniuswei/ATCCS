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
    bool isExecutoryInstructionOK() override;
    bool canExecutePlan() override;

protected:
    virtual bool checkResult_Connect();
    virtual bool checkResult_EnableTCompensate();
    virtual bool checkResult_FindHome();
    virtual bool checkResult_SetFixedSpeed();
    virtual bool checkResult_SetPostion();
    virtual bool checkResult_SetTCompensateCoefficiency();
    virtual bool checkResult_Stop();

};

#endif /* ATCCSFOCUSCONTROLLER_H */

