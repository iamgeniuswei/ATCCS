/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DBMWTitleBar.cpp
 * Author: lenovo
 *
 * Created on July 31, 2017, 10:07 AM
 */

#include "DBMWTitleBar.h"

DBMWTitleBar::DBMWTitleBar()
{
    widget.setupUi(this);
    initializeUI();
}

DBMWTitleBar::~DBMWTitleBar()
{
}

void DBMWTitleBar::initializeUI()
{
    widget._btnClose->setObjectName("atccs_mt_close");
    widget._mainTitleTag->setObjectName("mw_main_title");
}
