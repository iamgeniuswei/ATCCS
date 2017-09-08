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

ATCCSThread::ATCCSThread() 
{
    
}

/**
 * 设置线程退出条件:
 * true, 退出;
 * false, 继续运转.
 * @param _stop
 */
void ATCCSThread::setStop(bool _stop) 
{
//    std::lock_guard<std::mutex> lk(_stopLock);
    this->_stop = _stop;
}

/**
 * 获取线程退出条件.
 * @return 
 * true: 退出;
 * false: 继续运转.
 */
bool ATCCSThread::stop() const 
{
//    std::lock_guard<std::mutex> lk(_stopLock);
    return _stop;
}

/**
 * 启动线程
 */
void ATCCSThread::start()
{
    thread = std::make_shared<std::thread>(&ATCCSThread::run, this);
}

/**
 * 设置线程退出条件后,等待线程退出.
 */
void ATCCSThread::waitToQuit()
{
    if(thread && thread->joinable())
        thread->join();
}


