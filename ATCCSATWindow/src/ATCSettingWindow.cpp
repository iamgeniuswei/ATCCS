/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCSettingWindow.cpp
 * Author: lenovo
 *
 * Created on August 4, 2017, 3:49 PM
 */

#include "ATCSettingWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
ATCSettingWindow::ATCSettingWindow()
{
    initializeUI();
}

ATCSettingWindow::~ATCSettingWindow()
{
}

void ATCSettingWindow::initializeUI()
{
    _mainLayout = new QVBoxLayout();
    _mainLayout->setMargin(12);
    _titleBar = new QWPopupTitleBar(this);
    _titleBar->setTitle(tr("Setting"));
    _spilterTop = new QLabel(this);
    _spilterTop->setObjectName("horizontal_line");
    _spilterTop->setScaledContents(true);
    _settingArea = new QScrollArea(this);
    _settingPanel = new QWidget(_settingArea);
    _settingPanel->setObjectName("setting_panel");
    _settingLayout = new QGridLayout(_settingPanel);
    
    _navigator = new QWTimeLine(_settingPanel);
    _navigator->addTimeLinePoint(tr("About"), QWTimeLine::START);
    _navigator->addTimeLinePoint(tr("DB"), QWTimeLine::INTERMEDIATE);
    _navigator->addTimeLinePoint(tr("HOST"), QWTimeLine::INTERMEDIATE);
    _navigator->addTimeLinePoint(tr("GIMBAL"), QWTimeLine::INTERMEDIATE);
    _navigator->addTimeLinePoint(tr("CCD"), QWTimeLine::INTERMEDIATE);
    _navigator->addTimeLinePoint(tr("Filter"), QWTimeLine::INTERMEDIATE);
    _navigator->addTimeLinePoint(tr("Focus"), QWTimeLine::INTERMEDIATE);
    _navigator->addTimeLinePoint(tr("Dome"), QWTimeLine::END);
    
    
    _hostPanel = new QWLocalAddressPanel(_settingPanel);
    _dbPanel = new QWDBAddressPanel(_settingPanel);
    _settingLayout->addWidget(_navigator, 0, 0, 2, 1);
    _settingLayout->addWidget(_hostPanel, 0, 1);
    _settingLayout->addWidget(_dbPanel, 1, 1);
    _settingPanel->setLayout(_settingLayout);
    _settingArea->setWidget(_settingPanel);
    _settingArea->setWidgetResizable(true);  
    
    
    _btnPanel = new QWButtonPanel(this);
    _spilterBottom = new QLabel(this);
    _spilterBottom->setObjectName("horizontal_line");
    _spilterBottom->setScaledContents(true);
    _mainLayout->addWidget(_titleBar);
    _mainLayout->addWidget(_spilterTop);
    _mainLayout->addWidget(_settingArea);
    _mainLayout->addWidget(_spilterBottom);
    _mainLayout->addWidget(_btnPanel);
    setLayout(_mainLayout);
    
}
