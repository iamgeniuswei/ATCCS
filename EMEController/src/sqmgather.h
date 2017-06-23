/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SQMGather.h
 * Author: lenovo
 *
 * Created on 2017年6月21日, 上午10:17
 */

#ifndef SQMGATHER_H
#define SQMGATHER_H
class SQMGather
{
public:
    SQMGather();
    SQMGather(const SQMGather& orig) = delete;
    SQMGather(const SQMGather&& orig) = delete;
    SQMGather& operator=(const SQMGather& orig) = delete;
    SQMGather& operator=(const SQMGather&& orig) = delete;
    virtual ~SQMGather();

protected:

private:

};

#endif /* SQMGATHER_H */

