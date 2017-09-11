/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCDevicePanel.h
 * Author: lenovo
 *
 * Created on August 3, 2017, 5:06 PM
 */

#ifndef _ATCDEVICEPANEL_H
#define _ATCDEVICEPANEL_H

#include "ui_ATCDevicePanel.h"

class ATCDevicePanel : public QWidget
{
    Q_OBJECT
public:
    ATCDevicePanel();
    virtual ~ATCDevicePanel();
    void setDeviceProperty(unsigned int type, const QString& name);

protected:
    void initializeUI();
    void initializeSignal();

    virtual void paintEvent(QPaintEvent* event);

private:
    Ui::ATCDevicePanel widget;
    unsigned int _type;
    QString _name;
};

#endif /* _ATCDEVICEPANEL_H */
