/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCSettingPanel.h
 * Author: lenovo
 *
 * Created on August 4, 2017, 4:11 PM
 */

#ifndef _ATCSETTINGPANEL_H
#define _ATCSETTINGPANEL_H

#include "ui_ATCSettingPanel.h"

class ATCSettingPanel : public QWidget
{
    Q_OBJECT
public:
    ATCSettingPanel();
    virtual ~ATCSettingPanel();
private:
    Ui::ATCSettingPanel widget;
};

#endif /* _ATCSETTINGPANEL_H */
