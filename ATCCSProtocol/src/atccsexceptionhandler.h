/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSExceptionHandler.h
 * Author: lenovo
 *
 * Created on May 23, 2017, 3:12 PM
 */

#ifndef ATCCSEXCEPTIONHANDLER_H
#define ATCCSEXCEPTIONHANDLER_H
#include "atccsqueue.h"
#include "atccsexception.h"
#include <libintl.h>
class ATCCSException;
class ATCCSExceptionHandler {
private:
    ATCCSExceptionHandler();
    ATCCSExceptionHandler(const ATCCSExceptionHandler& orig) = delete;
    ATCCSExceptionHandler(const ATCCSExceptionHandler&& orig) = delete;
    ATCCSExceptionHandler& operator=(const ATCCSExceptionHandler& orig) = delete;
    ATCCSExceptionHandler& operator=(const ATCCSExceptionHandler&& orig) = delete;
    static ATCCSExceptionHandler *_instance;
    class ATCCSExceptionHandlerGarbo
    {
    public:
        ~ATCCSExceptionHandlerGarbo()
        {
            if(_instance != nullptr)
            {
                delete _instance;
                _instance = nullptr;
            }
        }
    };
    static ATCCSExceptionHandlerGarbo _ehGarbo;
public:
    ~ATCCSExceptionHandler();
    static void setMsg(std::string& msg, const char* format, ...);
    static void addException(unsigned int type, const char* format, ...);
    static void addException(unsigned int type, const char *file, const char *func, unsigned long line, const std::string& msg);
    static void addException(unsigned int type, const char *file, const char *func, unsigned long line, const char *msg);
    static void addException(unsigned int type, const char *file, const char *func, unsigned long line, char msg[]);
    static void addException(unsigned int type, const char *file, const char *func, unsigned long line, unsigned int at, unsigned int device, const char *msg);
//    template <typename ... ARGS>
//    static void addException(unsigned int type, const char *file, const char *func, unsigned long line, ARGS ... args);
    static std::shared_ptr<ATCCSException> lastException();
    
private:
    static ATCCSQueue<std::shared_ptr<ATCCSException>> _exceptions;
};

#endif /* ATCCSEXCEPTIONHANDLER_H */

