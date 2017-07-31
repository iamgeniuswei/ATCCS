/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DBMStartupBtnPanel.cpp
 * Author: lenovo
 *
 * Created on July 28, 2017, 11:24 AM
 */

#include "DBMStartupBtnPanel.h"

DBMStartupBtnPanel::DBMStartupBtnPanel(QWidget *parent)
:QWidget(parent)
{
    widget.setupUi(this);
    initializeSignal();
}

DBMStartupBtnPanel::~DBMStartupBtnPanel()
{
}

void DBMStartupBtnPanel::initializeSignal()
{
    connect(widget.cancelBtn, &QPushButton::clicked, this, &DBMStartupBtnPanel::cancelBtnClicked);
    connect(widget.okBtn, &QPushButton::clicked, this, &DBMStartupBtnPanel::okBtnClicked);
}
