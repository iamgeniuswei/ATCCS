/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMASCDataPanel.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 9:22 AM
 */

#ifndef _EMASCDATAPANEL_H
#define _EMASCDATAPANEL_H

#include "ui_EMASCDataPanel.h"

class EMASCDataPanel : public QWidget
{
    Q_OBJECT
public:
    EMASCDataPanel();
    virtual ~EMASCDataPanel();
private:
    Ui::EMASCDataPanel widget;
};

#endif /* _EMASCDATAPANEL_H */
