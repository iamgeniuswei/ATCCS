/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DBMWBtnPanel.cpp
 * Author: lenovo
 *
 * Created on July 31, 2017, 11:36 AM
 */

#include "DBMWBtnPanel.h"

DBMWBtnPanel::DBMWBtnPanel()
{
    widget.setupUi(this);
    initializeSignal();
}

DBMWBtnPanel::~DBMWBtnPanel()
{
}

void DBMWBtnPanel::initializeSignal()
{
    connect(widget._btnInitialize, &QPushButton::clicked,
            this, &DBMWBtnPanel::initializeBtnClicked);
}
