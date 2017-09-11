/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCCSEMWindow.cpp
 * Author: lenovo
 *
 * Created on August 1, 2017, 8:36 AM
 */

#include "ATCCSEMWindow.h"
#include "EMASCDataPanel.h"
#include "EMWSDataPanel.h"
#include "EMCSDataPanel.h"
#include "EMSingleDataPanel.h"
#include "QWOutputPanel.h"
#include "ATCCSEMSettingWindow.h"
#include <QVBoxLayout>
ATCCSEMWindow::ATCCSEMWindow(QWidget *parent)
:QWFramelessWindow(parent)
{
    centerToDesktop();
    initializeUI();
    initializeSignal();
    
}

ATCCSEMWindow::~ATCCSEMWindow()
{
}

void ATCCSEMWindow::initializeUI()
{
    setAttribute(Qt::WA_StyledBackground);
    setObjectName("atccs_em_window");
    _mainLayout = new QVBoxLayout(this);
    _titleBar = new ATCCSEMTitleBar();
    _displayArea = new ATCCSEMDisplayArea(this);
    EMASCDataPanel *ascPanel = new EMASCDataPanel();
    EMWSDataPanel *wsPanel = new EMWSDataPanel();
    EMCSDataPanel *csPanel = new EMCSDataPanel();
    EMSingleDataPanel *sqmPanel = new EMSingleDataPanel();
    EMSingleDataPanel *dustPanel = new EMSingleDataPanel();
    EMSingleDataPanel *dimmPanel = new EMSingleDataPanel();
    _displayArea->addEMDisplayPanel(ascPanel);
    _displayArea->addEMDisplayPanel(wsPanel);
    _displayArea->addEMDisplayPanel(csPanel);
    _displayArea->addEMDisplayPanel(sqmPanel);
    _displayArea->addEMDisplayPanel(dustPanel);
    _displayArea->addEMDisplayPanel(dimmPanel);
    _outputArea = new QWOutputPanel();
    _mainLayout->setContentsMargins(0, 0, 0, 5);
    _mainLayout->addWidget(_titleBar, 0);
    _mainLayout->addWidget(_displayArea, 1);
    _mainLayout->addWidget(_outputArea, 0);
    setLayout(_mainLayout);
}

void ATCCSEMWindow::initializeSignal()
{
    connect(_titleBar, &ATCCSEMTitleBar::btnCloseClicked, 
            this,&ATCCSEMWindow::close);
    connect(_titleBar, &ATCCSEMTitleBar::btnSettingClicked, 
            this,&ATCCSEMWindow::showSettingWindow);
    
}

void ATCCSEMWindow::showSettingWindow()
{
    ATCCSEMSettingWindow *w = new ATCCSEMSettingWindow;
    w->show();
}
