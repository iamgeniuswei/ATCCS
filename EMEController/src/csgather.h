/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CSGather.h
 * Author: lenovo
 *
 * Created on 2017年6月21日, 上午10:15
 */

#ifndef CSGATHER_H
#define CSGATHER_H
#include "atccscontroller.h"
#include "atccsthread.h"
class CSGather : public ATCCSController, public ATCCSThread
{
public:
    CSGather();
    CSGather(const CSGather& orig) = delete;
    CSGather(const CSGather&& orig) = delete;
    CSGather& operator=(const CSGather& orig) = delete;
    CSGather& operator=(const CSGather&& orig) = delete;
    virtual ~CSGather();

protected:

private:

};

#endif /* CSGATHER_H */

