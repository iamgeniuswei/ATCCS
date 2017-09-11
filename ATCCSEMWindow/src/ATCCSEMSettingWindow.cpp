/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCCSEMSettingWindow.cpp
 * Author: lenovo
 *
 * Created on August 1, 2017, 11:24 AM
 */

#include "ATCCSEMSettingWindow.h"
#include <QVBoxLayout>
#include <scoped_allocator>

ATCCSEMSettingWindow::ATCCSEMSettingWindow(QWidget *parent)
:QWFramelessWindow(parent)
{
//    widget.setupUi(this);
    initializeUI();
    initializeSignal();
    centerToDesktop();
}

ATCCSEMSettingWindow::~ATCCSEMSettingWindow()
{
}

void ATCCSEMSettingWindow::initializeUI()
{
    setObjectName("setting_window");
    
    _localPanel = new EMLocalAddressPanel;
    _dbPanel = new EMDBAddressPanel();
    _displayPanel = new EMDisplaySetPanel();
    _contentWidget = new QWidget(this);
    _contentWidget->setObjectName("atccs_em_window");
    _scrollLayout = new QVBoxLayout(_contentWidget);
    _scrollLayout->addWidget(_localPanel);
    _scrollLayout->addWidget(_dbPanel);
    _scrollLayout->addWidget(_displayPanel);
    _contentWidget->setLayout(_scrollLayout);
    _scrollArea = new QScrollArea(this);
    _scrollArea->setObjectName("atccs_em_window");
    _scrollArea->setWidgetResizable(true);
    _scrollArea->setWidget(_contentWidget);  
    _titleBar = new EMSettingTilteBar();
    _mainLayout = new QVBoxLayout();
    _mainLayout->setSpacing(0);
    _mainLayout->addWidget(_titleBar);
    _mainLayout->addWidget(_scrollArea);
    setLayout(_mainLayout);
    this->setFixedWidth(640);
}

void ATCCSEMSettingWindow::initializeSignal()
{
    connect(_titleBar, &EMSettingTilteBar::closeBtnClicked,
            this, &ATCCSEMSettingWindow::close);
}
