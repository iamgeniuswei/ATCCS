/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ASCGather.h
 * Author: lenovo
 *
 * Created on 2017年6月21日, 上午10:10
 */

#ifndef ASCGATHER_H
#define ASCGATHER_H
#include "atccscontroller.h"
#include "atccsthread.h"
class ASCGather : public ATCCSController, public ATCCSThread
{
public:
    ASCGather();
    ASCGather(const ASCGather& orig) = delete;
    ASCGather(const ASCGather&& orig) = delete;
    ASCGather& operator=(const ASCGather& orig) = delete;
    ASCGather& operator=(const ASCGather&& orig) = delete;
    virtual ~ASCGather();
    void run() override;


protected:

private:

};

#endif /* ASCGATHER_H */

