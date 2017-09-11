/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCDevicePanel.cpp
 * Author: lenovo
 *
 * Created on August 3, 2017, 5:06 PM
 */

#include "ATCDevicePanel.h"
#include <QStyleOption>
#include <QPainter>
ATCDevicePanel::ATCDevicePanel()
{
    widget.setupUi(this);
    setObjectName("device_panel");
}

ATCDevicePanel::~ATCDevicePanel()
{
}

void ATCDevicePanel::paintEvent(QPaintEvent* event)
{
    //    Q_D(QPUIWidget);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ATCDevicePanel::setDeviceProperty(unsigned int type, const QString& name)
{
    _type = type;
    _name = name;
    if(widget._deviceName)
        widget._deviceName->setText(name);
}

