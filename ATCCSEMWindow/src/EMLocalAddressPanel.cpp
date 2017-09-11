/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EMLocalAddressPanel.cpp
 * Author: lenovo
 *
 * Created on August 1, 2017, 9:48 AM
 */

#include "EMLocalAddressPanel.h"
#include "emsetting.h"
#include "atccsaddress.h"
#include "EMSQMPanel.h"

EMLocalAddressPanel::EMLocalAddressPanel(QWidget *parent)
:QWidget(parent)
{
    widget.setupUi(this);
    EMSetting *setting = EMSetting::instance();
    if (setting && setting->hostAddress())
    {
        widget._ip->setText(QString::fromStdString(setting->hostAddress()->ip()));
        widget._port->setText(QString::number(setting->hostAddress()->port()));
    }
}

EMLocalAddressPanel::~QWLocalAddressPanel()
{
}
