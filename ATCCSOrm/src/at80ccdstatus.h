/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at80ccdstatus.h
 * Author: lenovo
 *
 * Created on September 12, 2017, 1:51 PM
 */

#ifndef AT80CCDSTATUS_H
#define AT80CCDSTATUS_H

class at80ccdstatus
{
public:
    at80ccdstatus();
    at80ccdstatus(const at80ccdstatus& orig) = delete;
    at80ccdstatus(const at80ccdstatus&& orig) = delete;
    at80ccdstatus& operator=(const at80ccdstatus& orig) = delete;
    at80ccdstatus& operator=(const at80ccdstatus&& orig) = delete;
    virtual ~at80ccdstatus();

protected:

private:

};

#endif /* AT80CCDSTATUS_H */

