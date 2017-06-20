/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSThread.cpp
 * Author: lenovo
 * 
 * Created on May 22, 2017, 4:14 PM
 */

#include "atccsthread.h"

ATCCSThread::ATCCSThread() {
}

void ATCCSThread::setStop(bool _stop) 
{
//    std::lock_guard<std::mutex> lk(_stopLock);
    this->_stop = _stop;
}

bool ATCCSThread::stop() const 
{
//    std::lock_guard<std::mutex> lk(_stopLock);
    return _stop;
}


