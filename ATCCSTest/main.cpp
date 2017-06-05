/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on May 15, 2017, 4:26 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "atccs_public_define.h"
#include "atccs_gimbal_define.h"
#include "atccs_ccd_define.h"
#include "atccs_focus_define.h"
#include "atccs_filter_define.h"
#include "atccs_dome_define.h"
#include <memory>

class Test{
public:
    ~Test()
    {
        cout << "d" << std::endl;
    }
};
/*
 * 
 */
#include <stdarg.h>
#include <string.h>
int sum(unsigned int n, ...)
{
    std::string temp;
    va_list args;
    va_start(args, n);
    while(n > 0)
    {
        temp += va_arg(args, const char*);
        n--;
    }
    va_end(args);
    std::cout << temp << std::endl;
}

template <class T>
T print(std::string &test, T t)
{
    std::cout << strcmp(typeid(T).name(), typeid(int).name()) << std::endl;
    test += t;
    std::cout << t << std::endl;
    return t;
}
template <typename ... T>
void DummyWrapper(T... t)
{
    
}
template <typename ... T>
void expand(T ... t)
{
    std::string test;
    DummyWrapper(print(test, t)...);

}


template <typename T>
void _write(std::string &test, const T& t)
{
    test += t;
    std::cout << t << std::endl;
}

template <typename T, typename ... Args>
void _write(std::string &test, const T& t, Args ... args)
{
    std::cout << "typeif: " << (typeid(t) == typeid(int)) <<std::endl;
    test += t;
    _write(test, args...);
}

template <typename T, typename ... Args>
inline void write_line(const T& t, const Args& ... data)
{
    
    std::string test;
    _write(test, t, data...);
    std::cout << test << std::endl;
}


int main(int argc, char** argv)
{

//    write_line("dfaf", "dfd", 34, 343, "dfd");
    double d1 = 0.012343;
    double d2 = 0.012344;
    cout << (d1==d2) << endl;
    
    
    cin.get();
    return 0;
}

