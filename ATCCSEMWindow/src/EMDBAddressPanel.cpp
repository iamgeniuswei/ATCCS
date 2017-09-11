/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EMDBAddressPanel.cpp
 * Author: lenovo
 *
 * Created on August 1, 2017, 9:51 AM
 */

#include "EMDBAddressPanel.h"
#include "emsetting.h"
#include "atccsdbaddress.h"
EMDBAddressPanel::EMDBAddressPanel(QWidget *parent)
:QWidget(parent)
{
    widget.setupUi(this);
    initializeData();
}

EMDBAddressPanel::~QWDBAddressPanel()
{
}

void EMDBAddressPanel::initializeData()
{
    EMSetting *setting = EMSetting::instance();
    if (setting && setting->dbAddress())
    {
        widget._dbType->addItem(QString::fromStdString(setting->dbAddress()->type()));
        widget._dbIP->setText(QString::fromStdString(setting->dbAddress()->ip()));
        widget._dbName->setText(QString::fromStdString(setting->dbAddress()->db()));
        widget._dbUser->setText(QString::fromStdString(setting->dbAddress()->user()));
        widget._dbPassword->setText(QString::fromStdString(setting->dbAddress()->password()));
        widget._dbPort->setText(QString::number(setting->dbAddress()->port()));
    }
}
