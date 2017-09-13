/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSPlanController.h
 * Author: lenovo
 *
 * Created on September 12, 2017, 4:07 PM
 */

#ifndef ATCCSPLANCONTROLLER_H
#define ATCCSPLANCONTROLLER_H
#include "atccscontroller.h"
#include "atccsthread.h"
#include "atccsplaninstruction.h"
#include "atccsplanperformer.h"
class atccsplaninstruction;
class ATCCSPlanController : public ATCCSController, public ATCCSThread
{
public:
    ATCCSPlanController();
    ATCCSPlanController(const ATCCSPlanController& orig) = delete;
    ATCCSPlanController(const ATCCSPlanController&& orig) = delete;
    ATCCSPlanController& operator=(const ATCCSPlanController& orig) = delete;
    ATCCSPlanController& operator=(const ATCCSPlanController&& orig) = delete;
    virtual ~ATCCSPlanController();
    
    void run() override;
    void setPlanPerformer(std::shared_ptr<ATCCSPlanPerformer> _planPerformer);


protected:
    void updateInstruction(std::shared_ptr<ATCCSData> data = nullptr);

private:
    std::shared_ptr<ATCCSPlanPerformer> _planPerformer = nullptr;
};

#endif /* ATCCSPLANCONTROLLER_H */

