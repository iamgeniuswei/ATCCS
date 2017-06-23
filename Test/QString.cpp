/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QString.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月23日, 上午9:35
 */

#include "QString.h"
#include <iostream>
#include <cstring>
using namespace std;
QString::QString()
{
    cout << "QString(const char *src)" << endl;
//    if(src == nullptr)
//    {
//        _data = new char [1];
//        *_data = '\0';
//    }
//    else
//    {
        _data = new char[10];
        strcpy(_data, "123123");
    
}

QString::QString(const QString& orig)
{
    cout << "QString(const QString& orig)" << endl;
    _data = new char [strlen(orig._data) + 1];
    strcpy(_data, orig._data);
}


QString& QString::operator=(const QString& orig)
{
    cout << "QString::operator=(const QString& orig)" << endl;
    if(this != &orig)
    {
        delete [] _data;
        _data = new char [strlen(orig._data)+1];
        strcpy(_data, orig._data);
    }
    return *this;
}

QString::QString(QString&& orig)
{
    cout << "QString(const QString&& orig)" << endl;
    _data = orig._data;
    orig._data = nullptr;
}

QString& QString::operator =(QString&& orig)
{
    cout << "QString::operator =(QString&& orig)" << endl;
    if(this != &orig)
    {
        delete [] _data;
        _data = orig._data;
        orig._data = nullptr;
    }
    return *this;
}

QString::~QString()
{
    delete [] _data;
}

