/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60ExceptionDisplayer.h
 * Author: lenovo
 *
 * Created on May 24, 2017, 9:16 AM
 */

#ifndef AT60EXCEPTIONDISPLAYER_H
#define AT60EXCEPTIONDISPLAYER_H
#include "atccsthread.h"
class AT60ExceptionDisplayer : public ATCCSThread
{
public:
    AT60ExceptionDisplayer();
    AT60ExceptionDisplayer(const AT60ExceptionDisplayer& orig);
    virtual ~AT60ExceptionDisplayer();
    void run() override;

private:

};

#endif /* AT60EXCEPTIONDISPLAYER_H */

