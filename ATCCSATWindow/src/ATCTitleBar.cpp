/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCTitleBar.cpp
 * Author: lenovo
 *
 * Created on August 3, 2017, 11:17 AM
 */

#include "ATCTitleBar.h"

ATCTitleBar::ATCTitleBar(QWidget *parent)
:QWidget(parent)
{
    widget.setupUi(this);
    initializeUI();
    initializeSignal();
    
}

ATCTitleBar::~ATCTitleBar()
{
}

void ATCTitleBar::initializeUI()
{
    this->setAttribute(Qt::WA_StyledBackground);
    setObjectName("titleBar");
    if(widget._setting)
        widget._setting->setObjectName("setting");
    if(widget._close)
        widget._close->setObjectName("close");
    if(widget._min)
        widget._min->setObjectName("min");
    if(widget._max)
        widget._max->setObjectName("max");
    if(widget._logo)
        widget._logo->setObjectName("main_logo");
    if(widget._title)
        widget._title->setObjectName("main_title");
}

void ATCTitleBar::initializeSignal()
{
    if (widget._setting)
        connect(widget._setting, &QToolButton::clicked,
                this, &ATCTitleBar::settingClicked);
    if (widget._close)
        connect(widget._close, &QToolButton::clicked,
                this, &ATCTitleBar::closeClicked);
    if (widget._min)
        connect(widget._min, &QToolButton::clicked,
                this, &ATCTitleBar::minClicked);
    if (widget._max)
        connect(widget._max, &QToolButton::clicked,
                this, &ATCTitleBar::maxClicked);
}
