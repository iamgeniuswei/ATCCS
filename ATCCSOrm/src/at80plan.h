/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at80plan.h
 * Author: lenovo
 *
 * Created on September 12, 2017, 1:36 PM
 */

#ifndef AT80PLAN_H
#define AT80PLAN_H
#include "atccsplan.h"


/**
 * 80cm望远镜计划数据表
 */
#pragma db object
class at80plan : public atccsplan
{
public:
    at80plan();
    at80plan(const at80plan& orig) = delete;
    at80plan(const at80plan&& orig) = delete;
    at80plan& operator=(const at80plan& orig) = delete;
    at80plan& operator=(const at80plan&& orig) = delete;
    virtual ~at80plan();
    unsigned int persistPlan() override;
    void persistPlanResult() override;



protected:

private:

};

#endif /* AT80PLAN_H */

