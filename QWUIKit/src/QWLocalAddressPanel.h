/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMLocalAddressPanel.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 9:48 AM
 */

#ifndef _EMLOCALADDRESSPANEL_H
#define _EMLOCALADDRESSPANEL_H

#include "ui_QWLocalAddressPanel.h"

class QWLocalAddressPanel : public QWidget
{
    Q_OBJECT
public:
    QWLocalAddressPanel(QWidget *parent = 0);
    virtual ~QWLocalAddressPanel();
private:
    Ui::EMLocalAddressPanel widget;
};

#endif /* _EMLOCALADDRESSPANEL_H */
