/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at80filterstatus.h
 * Author: lenovo
 *
 * Created on September 12, 2017, 1:51 PM
 */

#ifndef AT80FILTERSTATUS_H
#define AT80FILTERSTATUS_H

class at80filterstatus
{
public:
    at80filterstatus();
    at80filterstatus(const at80filterstatus& orig) = delete;
    at80filterstatus(const at80filterstatus&& orig) = delete;
    at80filterstatus& operator=(const at80filterstatus& orig) = delete;
    at80filterstatus& operator=(const at80filterstatus&& orig) = delete;
    virtual ~at80filterstatus();

protected:

private:

};

#endif /* AT80FILTERSTATUS_H */

