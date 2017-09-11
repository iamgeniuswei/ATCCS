/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMSQMPanel.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 8:38 AM
 */

#ifndef _EMSQMPANEL_H
#define _EMSQMPANEL_H

#include "ui_EMSQMPanel.h"

class EMSQMPanel : public QWidget
{
    Q_OBJECT
public:
    EMSQMPanel();
    virtual ~EMSQMPanel();
private:
    Ui::EMSQMPanel widget;
};

#endif /* _EMSQMPANEL_H */
