/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCCSDBMMainWindow.cpp
 * Author: lenovo
 *
 * Created on July 29, 2017, 7:24 PM
 */

#include <exception>

#include "ATCCSDBMMainWindow.h"
#include <QVBoxLayout>
#include "DBMPublicTablePanel.h"
#include "DBMEMETablePanel.h"
#include "DBMAT60TablePanel.h"
#include "QWTitleBar.h"
#include <iostream>
#include <ratio>
ATCCSDBMMainWindow::ATCCSDBMMainWindow(QWidget *parent)
:QWFramelessWindow(parent)
{
    initializeUI();
    initializeSignal();
    centerToDesktop();
}

ATCCSDBMMainWindow::~ATCCSDBMMainWindow()
{
}

void ATCCSDBMMainWindow::initializeUI()
{
    try
    {
        _mainLayout = new QVBoxLayout(this);
        _titleBar = new DBMWTitleBar();
        _editPanel = new DBMWEditPanel(this);
        _btnPanel = new DBMWBtnPanel();
        _outPanel = new DBMWOutPanel();
        
        _mainLayout->addWidget(_titleBar);
        _mainLayout->addWidget(_editPanel);
        _mainLayout->addWidget(_btnPanel);
        _mainLayout->addWidget(_outPanel);
        setLayout(_mainLayout);
        
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

void ATCCSDBMMainWindow::initializeSignal()
{
    connect(_btnPanel, &DBMWBtnPanel::initializeBtnClicked,
            _editPanel, &DBMWEditPanel::initializeDatabase);
    connect(_editPanel, &DBMWEditPanel::initializeDBFinished,
            _outPanel, &DBMWOutPanel::updateOutput);
}
