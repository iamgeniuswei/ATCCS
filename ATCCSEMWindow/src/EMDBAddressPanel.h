/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMDBAddressPanel.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 9:51 AM
 */

#ifndef _EMDBADDRESSPANEL_H
#define _EMDBADDRESSPANEL_H

#include "ui_EMDBAddressPanel.h"

class EMDBAddressPanel : public QWidget
{
    Q_OBJECT
public:
    EMDBAddressPanel(QWidget *parent = 0);
    virtual ~QWDBAddressPanel();

protected:
    void initializeData();
private:
    Ui::EMDBAddressPanel widget;
};

#endif /* _EMDBADDRESSPANEL_H */
