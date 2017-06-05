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
class ATCCSThread {
protected:
    ATCCSThread();
    ATCCSThread(const ATCCSThread& orig) = delete;
    ATCCSThread(const ATCCSThread&& orig) = delete;
    ATCCSThread& operator=(const ATCCSThread& orig) = delete;  
    ATCCSThread& operator =(const ATCCSThread&& orig) = delete;
public:
    virtual ~ATCCSThread(){};
    virtual void run() = 0;
    void setStop(bool _stop);
    bool stop() const;
private:
    mutable std::mutex _stopLock;
    mutable bool _stop = false;
};

#endif /* ATCCSTHREAD_H */

