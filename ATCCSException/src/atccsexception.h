/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSException.h
 * Author: lenovo
 *
 * Created on June 15, 2017, 9:20 AM
 */

#ifndef ATCCSEXCEPTION_H
#define ATCCSEXCEPTION_H
#include <exception>
#include <string>
class ATCCSException : std::exception
{
public:
    ATCCSException(const std::string& msg) noexcept;
    ATCCSException(const char *file, const char *func, unsigned int line, const std::string& msg) noexcept;            
    ATCCSException(const ATCCSException& orig) = delete;
    ATCCSException(const ATCCSException&& orig) = delete;
    ATCCSException& operator=(const ATCCSException& orig) = delete;
    ATCCSException& operator=(const ATCCSException&& orig) = delete;
    virtual ~ATCCSException() noexcept;
    const char* what() const noexcept override;
    void init(const char* file, const char* func, unsigned int line);


protected:
    std::string _msg;
    const char *_file;
    const char *_func;
    unsigned int _line;
private:

};

#endif /* ATCCSEXCEPTION_H */

