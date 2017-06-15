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
    bool isExecutoryInstructionOK() override;
    bool canExecutePlan() override;


protected:
    virtual bool checkResult_Connect();
    virtual bool checkResult_FindHome();
    virtual bool checkResult_SetFilterPosition();




};

#endif /* ATCCSFILTERCONTROLLER_H */

