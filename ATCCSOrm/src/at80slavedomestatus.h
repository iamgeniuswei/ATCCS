/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at80slavedomestatus.h
 * Author: lenovo
 *
 * Created on September 12, 2017, 1:52 PM
 */

#ifndef AT80SLAVEDOMESTATUS_H
#define AT80SLAVEDOMESTATUS_H

class at80slavedomestatus
{
public:
    at80slavedomestatus();
    at80slavedomestatus(const at80slavedomestatus& orig) = delete;
    at80slavedomestatus(const at80slavedomestatus&& orig) = delete;
    at80slavedomestatus& operator=(const at80slavedomestatus& orig) = delete;
    at80slavedomestatus& operator=(const at80slavedomestatus&& orig) = delete;
    virtual ~at80slavedomestatus();

protected:

private:

};

#endif /* AT80SLAVEDOMESTATUS_H */

