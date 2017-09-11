/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMWSDataPanel.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 9:43 AM
 */

#ifndef _EMWSDATAPANEL_H
#define _EMWSDATAPANEL_H

#include "ui_EMWSDataPanel.h"

class EMWSDataPanel : public QWidget
{
    Q_OBJECT
public:
    EMWSDataPanel();
    virtual ~EMWSDataPanel();
private:
    Ui::EMWSDataPanel widget;
};

#endif /* _EMWSDATAPANEL_H */
