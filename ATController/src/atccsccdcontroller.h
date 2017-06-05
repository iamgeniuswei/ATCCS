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
    ATCCSCCDController();
    virtual ~ATCCSCCDController();
    
    bool isStatusOK() const override;
    bool isExecutoryInstructionOK() override;
    bool canExecutePlan() override;

protected:
    virtual bool checkResult_Connect();
    virtual bool checkResult_SetCoolerT();
    virtual bool checkResult_SetExposureTactics();
    virtual bool checkResult_StartExposure();
    virtual bool checkResult_StopExposure();
    virtual bool checkResult_AbortExposure();
    virtual bool checkResult_SetGain();
    virtual bool checkResult_SetReadSpeedMode();
    virtual bool checkResult_SetTransferSpeed();
    virtual bool checkResult_SetBIN();
    virtual bool checkResult_SetROI();
    virtual bool checkResult_SetShutter();
    virtual bool checkResult_SetFullFrame();
    virtual bool checkResult_SetEM();
    virtual bool checkResult_SetCMOSNF();
    virtual bool checkResult_SetBaseline();
    virtual bool checkResult_SetOverScan();
private:

};

#endif /* AT60CCDCONTROLLER_H */

