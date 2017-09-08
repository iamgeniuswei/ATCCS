/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSThread.h
 * Author: lenovo
 *
 * Created on May 22, 2017, 4:14 PM
 */

#ifndef ATCCSTHREAD_H
#define ATCCSTHREAD_H

#include <mutex>
#include <thread>
#include <memory>


/**
 * 线程管理基类,封装了C++11线程管理的基本功能
 */
class ATCCSThread 
{
protected:
    ATCCSThread();
    ATCCSThread(const ATCCSThread& orig) = delete;
    ATCCSThread(const ATCCSThread&& orig) = delete;
    ATCCSThread& operator=(const ATCCSThread& orig) = delete;  
    ATCCSThread& operator =(const ATCCSThread&& orig) = delete;
    /**
     * 纯虚函数,须由子类实现具体的线程功能.
     */
    virtual void run() = 0;
public:
    virtual ~ATCCSThread(){};    
    virtual void start();
    virtual void waitToQuit();
    void setStop(bool _stop);
    bool stop() const;
private:
    mutable std::mutex _stopLock;
    mutable bool _stop = false;
    std::shared_ptr<std::thread> thread = nullptr;
};

#endif /* ATCCSTHREAD_H */

