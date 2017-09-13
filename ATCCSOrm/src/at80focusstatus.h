/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at80focusstatus.h
 * Author: lenovo
 *
 * Created on September 12, 2017, 1:52 PM
 */

#ifndef AT80FOCUSSTATUS_H
#define AT80FOCUSSTATUS_H

class at80focusstatus
{
public:
    at80focusstatus();
    at80focusstatus(const at80focusstatus& orig) = delete;
    at80focusstatus(const at80focusstatus&& orig) = delete;
    at80focusstatus& operator=(const at80focusstatus& orig) = delete;
    at80focusstatus& operator=(const at80focusstatus&& orig) = delete;
    virtual ~at80focusstatus();

protected:

private:

};

#endif /* AT80FOCUSSTATUS_H */

