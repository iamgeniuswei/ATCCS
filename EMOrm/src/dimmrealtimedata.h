/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dimmrealtimedata.h
 * Author: lenovo
 *
 * Created on 2017年6月23日, 上午10:51
 */

#ifndef DIMMREALTIMEDATA_H
#define DIMMREALTIMEDATA_H
#include "emerealtimedata.h"

/**
 * @brief dimmrealtimedata is a persistence class which encapsulates the 
 * dimm real-time data.
 * @modified 2017-07-26
 * @description 
 * 1) recompile the header file by odb complier with the --schema-name dimmrealtimedata
 * 
 */
#pragma db object
class dimmrealtimedata : public emerealtimedata
{
public:
    dimmrealtimedata();
    dimmrealtimedata(const dimmrealtimedata& orig) = delete;
    dimmrealtimedata(const dimmrealtimedata&& orig) = delete;
    dimmrealtimedata& operator=(const dimmrealtimedata& orig) = delete;
    dimmrealtimedata& operator=(const dimmrealtimedata&& orig) = delete;
    virtual ~dimmrealtimedata();
    unsigned long long persistRealtimeData() override;
    unsigned int setRealtimeData(std::shared_ptr<ATCCSData> data) override;



protected:

public:
    friend class odb::access;
    double _dimmdata = 0;

};

#endif /* DIMMREALTIMEDATA_H */
