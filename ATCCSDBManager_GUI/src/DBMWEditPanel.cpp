/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DBMWEditPancel.cpp
 * Author: lenovo
 *
 * Created on July 29, 2017, 7:57 PM
 */

#include <exception>
#include <iostream>

#include "DBMWEditPanel.h"
#include "DBMPublicTablePanel.h"
#include "DBMEMETablePanel.h"

DBMWEditPanel::DBMWEditPanel(QWidget *parent)
{
    initializeUI();
    initializeSignal();
}

DBMWEditPanel::~DBMWEditPanel()
{
}

void DBMWEditPanel::initializeUI()
{
    try
    {
        _contentWidget = new QWidget(this);
        _mainLayout = new QVBoxLayout(_contentWidget);
        _publicPanel = new DBMPublicTablePanel(_contentWidget);
        _emePanel = new DBMEMETablePanel(_contentWidget);
        _at60Panel = new DBMAT60TablePanel(_contentWidget);
        _mainLayout->addWidget(_publicPanel);
        _mainLayout->addWidget(_emePanel);
        _mainLayout->addWidget(_at60Panel);
        _contentWidget->setLayout(_mainLayout);
        //        setLayout(_mainLayout);
        setWidget(_contentWidget);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void DBMWEditPanel::selectAll()
{

}

void DBMWEditPanel::selectNone()
{

}

void DBMWEditPanel::initializeSignal()
{
    connect(this, &DBMWEditPanel::initializeDatabase,
            _publicPanel, &DBMPublicTablePanel::initializeDatabase);
    connect(this, &DBMWEditPanel::initializeDatabase,
            _emePanel, &DBMEMETablePanel::initializeDatabase);
    connect(this, &DBMWEditPanel::initializeDatabase,
            _at60Panel, &DBMAT60TablePanel::initializeDatabase);
    connect(_publicPanel, &DBMPublicTablePanel::initializeDBFinished,
            this, &DBMWEditPanel::initializeDBFinished);
    connect(_emePanel, &DBMEMETablePanel::initializeDBFinished,
            this, &DBMWEditPanel::initializeDBFinished);
    connect(_at60Panel, &DBMAT60TablePanel::initializeDBFinished,
            this, &DBMWEditPanel::initializeDBFinished);
}


