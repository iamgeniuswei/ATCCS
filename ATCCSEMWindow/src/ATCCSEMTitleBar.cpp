/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCCSEMTitleBar.cpp
 * Author: lenovo
 *
 * Created on August 1, 2017, 3:32 PM
 */

#include "ATCCSEMTitleBar.h"
#include <QPushButton>
ATCCSEMTitleBar::ATCCSEMTitleBar()
{
    widget.setupUi(this);
    initializeUI();
    initializeSignal();
}

ATCCSEMTitleBar::~ATCCSEMTitleBar()
{
}

void ATCCSEMTitleBar::initializeUI()
{
    setAttribute(Qt::WA_StyledBackground);
    setObjectName("atccs_em_titlebar");
    widget._mainTitleTag->setObjectName("atccs_em_maintitle");
    widget._subTitleTag->setObjectName("atccs_em_subtitle");
    widget._setting->setObjectName("atccs_em_setting");
    widget._close->setObjectName("atccs_em_close");
}

void ATCCSEMTitleBar::initializeSignal()
{
    connect(widget._close, &QPushButton::clicked,
            this, &ATCCSEMTitleBar::btnCloseClicked);
    connect(widget._setting, &QPushButton::clicked,
            this, &ATCCSEMTitleBar::btnSettingClicked);
}
