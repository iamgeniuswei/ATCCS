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
    bool isExecutoryInstructionOK() override;
    bool isExecutoryInstructionOK(unsigned int instruction) override;

    bool isStatusOK() const override;
    bool canExecutePlan() override;

protected:
    virtual bool checkResult_Connect();
    virtual bool checkResult_FindHome();
    virtual bool checkResult_TrackStar();
    virtual bool checkResult_SetObjectName();
    virtual bool checkResult_SlewAzEl();
    virtual bool checkResult_SlewDerotator();
    virtual bool checkResult_ConfigDerotator();
    virtual bool checkResult_Stop();
    virtual bool checkResult_SpeedCorrect();
    virtual bool checkResult_Park();
    virtual bool checkResult_FixedMove();
    virtual bool checkResult_PositionCorrect();
    virtual bool checkResult_CoverAction();
    virtual bool checkResult_FocusAction();
    virtual bool checkResult_Emergence();
    virtual bool checkResult_ConfigProperty();
    virtual bool checkResult_SaveSyncData();
};

#endif /* AT60GIMBALCONTROLLER_H */

