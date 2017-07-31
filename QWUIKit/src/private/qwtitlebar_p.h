/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   qwtitlebar_p.h
 * Author: lenovo
 *
 * Created on June 29, 2017, 10:24 AM
 */

#ifndef QWTITLEBAR_P_H
#define QWTITLEBAR_P_H
#include <QObject>
#include <QPointer>
class QGridLayout;
class QHBoxLayout;
class QWTitleBar;
class QWTitleBarPrivate
{
public:
    QWTitleBarPrivate(QWTitleBar *parent = 0)
            :q_ptr(parent)
            {
            }
    void init();
public:
    QPointer<QGridLayout> _mainLayout;
    QPointer<QHBoxLayout> _sysBtnLayout;
private:
    QWTitleBar *const q_ptr;
};


#endif /* QWTITLEBAR_P_H */

