/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCCSDBMStartup.cpp
 * Author: lenovo
 *
 * Created on July 28, 2017, 10:13 AM
 */

#include "ATCCSDBMStartup.h"
#include <QVBoxLayout>
#include "DBMStartupBtnPanel.h"
#include "DBMStarupEditPanel.h"
#include "QWPopupWindowTitleBar.h"
#include "DBMAT60TablePanel.h"
#include <iostream>
#include <QLabel>
#include <QDesktopWidget>
#include "ATCCSDBMMainWindow.h"

ATCCSDBMStartup::ATCCSDBMStartup(QWidget *parent)
:QWFramelessWindow(parent)
{
    initializeUI();
    initializeSignal();
        QDesktopWidget *desktop = QApplication::desktop();
    if(desktop)
        move((desktop->width() - width())/2, (desktop->height() - height())/2);
}

ATCCSDBMStartup::~ATCCSDBMStartup()
{
}

void ATCCSDBMStartup::initializeUI()
{
    try
    {
        _mainLayout = new QVBoxLayout(this);
        _titleBar = new QWPopupWindowTitleBar(this); 
        _titleBar->setCloseBtnObjectName("atccs_mt_close");
        _titleBar->setLogoObjectName("add_db_logo");
        _titleBar->setTitleObjectName("add_db_text");        
        _editPanel = new DBMStarupEditPanel(this);
        _btnPanel = new DBMStartupBtnPanel(this);
        _mainLayout->addWidget(_titleBar);
        _mainLayout->addWidget(_editPanel);
        _mainLayout->addWidget(_btnPanel);
        setLayout(_mainLayout);
                
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void ATCCSDBMStartup::initializeSignal()
{
    connect(_btnPanel, &DBMStartupBtnPanel::cancelBtnClicked, this, &QWidget::close);
    connect(_btnPanel, &DBMStartupBtnPanel::okBtnClicked, _editPanel, &DBMStarupEditPanel::connectToDatabase);
    connect(_editPanel, &DBMStarupEditPanel::successToConnectDB, this, &ATCCSDBMStartup::showATCCSDBMainWindow);
}

void ATCCSDBMStartup::showATCCSDBMainWindow()
{
    close();
    ATCCSDBMMainWindow *mw = new ATCCSDBMMainWindow();
    mw->show();
}
