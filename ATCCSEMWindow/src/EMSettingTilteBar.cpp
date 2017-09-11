/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EMSettingTilteBar.cpp
 * Author: lenovo
 *
 * Created on August 2, 2017, 10:38 AM
 */

#include "EMSettingTilteBar.h"
#include <QToolButton>
EMSettingTilteBar::EMSettingTilteBar(QWidget *parent)
:QWidget(parent)
{
    widget.setupUi(this);
    widget._close->setObjectName("atccs_em_close");
    initializeSignal();
    setObjectName("setting_titlebar");
    setAttribute(Qt::WA_StyledBackground);
}

EMSettingTilteBar::~EMSettingTilteBar()
{
}

void EMSettingTilteBar::initializeSignal()
{
    connect(widget._close, &QToolButton::clicked,
            this, &EMSettingTilteBar::closeBtnClicked);
}
