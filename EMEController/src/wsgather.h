/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WSGather.h
 * Author: lenovo
 *
 * Created on 2017年6月21日, 上午10:13
 */

#ifndef WSGATHER_H
#define WSGATHER_H
#include "atccscontroller.h"
#include "atccsthread.h"

class WSGather : public ATCCSController, public ATCCSThread
{
public:
    WSGather();
    WSGather(const WSGather& orig) = delete;
    WSGather(const WSGather&& orig) = delete;
    WSGather& operator=(const WSGather& orig) = delete;
    WSGather& operator=(const WSGather&& orig) = delete;
    virtual ~WSGather();

protected:

private:

};

#endif /* WSGATHER_H */

