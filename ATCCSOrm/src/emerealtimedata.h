/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   emerealtimedata.h
 * Author: lenovo
 *
 * Created on 2017年6月21日, 上午10:31
 */

#ifndef EMEREALTIMEDATA_H
#define EMEREALTIMEDATA_H
#include <odb/core.hxx>
#include <memory>
class ATCCSData;

#pragma db object
class emerealtimedata
{
public:
    enum RETCODE
    {
        RAWDATAISNULL,
        RAWDATAERROR,
        SUCCESS
    };
    
public:
    emerealtimedata();
    emerealtimedata(const emerealtimedata& orig) = delete;
    emerealtimedata(const emerealtimedata&& orig) = delete;
    emerealtimedata& operator=(const emerealtimedata& orig) = delete;
    emerealtimedata& operator=(const emerealtimedata&& orig) = delete;
    virtual ~emerealtimedata();
    virtual unsigned long long persistRealtimeData(){}
    virtual unsigned int setRealtimeData(std::shared_ptr<ATCCSData> data = nullptr);
    unsigned long long id() const;
    unsigned int msec() const;
    unsigned int sec() const;

protected:
    friend class odb::access;
#pragma db id auto
    unsigned long long _id = 0;
    unsigned int _sec = 0;
    unsigned int _msec = 0;
};

#endif /* EMEREALTIMEDATA_H */

