/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DBMPublicTablePanel.cpp
 * Author: lenovo
 *
 * Created on July 29, 2017, 7:32 PM
 */

#include "DBMPublicTablePanel.h"
#include <iostream>
#include <QDebug>
#include <odb/core.hxx>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
using namespace odb;
using namespace odb::core;
#include "ORMHelper.h"
DBMPublicTablePanel::DBMPublicTablePanel(QWidget *parent)
:QWidget(parent)
{
    widget.setupUi(this);
    initializeSignal();
}

DBMPublicTablePanel::~DBMPublicTablePanel()
{
}

void DBMPublicTablePanel::selectAll()
{
    if(widget._cbUserTable)
        widget._cbUserTable->setChecked(true);
    if(widget._cbATTable)
        widget._cbATTable->setChecked(true);
    if(widget._cbDeviceTable)
        widget._cbDeviceTable->setChecked(true);
    if(widget._cbEMETable)
        widget._cbEMETable->setChecked(true);
    if(widget._cbATUtilizationTable)
        widget._cbATUtilizationTable->setChecked(true);
    if(widget._cbATUtilizationLogTable)
        widget._cbATUtilizationLogTable->setChecked(true);
        
}

void DBMPublicTablePanel::selectNone()
{
    if(widget._cbUserTable)
        widget._cbUserTable->setChecked(false);
    if(widget._cbATTable)
        widget._cbATTable->setChecked(false);
    if(widget._cbDeviceTable)
        widget._cbDeviceTable->setChecked(false);
    if(widget._cbEMETable)
        widget._cbEMETable->setChecked(false);
    if(widget._cbATUtilizationTable)
        widget._cbATUtilizationTable->setChecked(false);
    if(widget._cbATUtilizationLogTable)
        widget._cbATUtilizationLogTable->setChecked(false);
}

void DBMPublicTablePanel::initializeSignal()
{
    connect(widget._btnSelectAll, &QPushButton::clicked,
            this, &DBMPublicTablePanel::selectAll);
    connect(widget._btnSelectNone, &QPushButton::clicked,
            this, &DBMPublicTablePanel::selectNone);
}

void DBMPublicTablePanel::initializeDatabase()
{
    try
    {
        std::shared_ptr<database> db = ORMHelper::db();
        transaction t(db->begin());        
        if(widget._cbUserTable->isChecked())
            schema_catalog::create_schema(*db, "atccsuser");
        if(widget._cbATTable->isChecked())
            schema_catalog::create_schema(*db, "atccsat");
        if(widget._cbDeviceTable->isChecked())
            schema_catalog::create_schema(*db, "atccsdevice");
        if(widget._cbEMETable->isChecked())
            schema_catalog::create_schema(*db, "atccseme");
        if(widget._cbATUtilizationTable->isChecked())
            schema_catalog::create_schema(*db, "atccsutilization");
        if(widget._cbATUtilizationLogTable->isChecked())
            schema_catalog::create_schema(*db, "atccsutilizationlog");
        t.commit();
        emit initializeDBFinished(SUCCESS, tr("Public tables are successfully initialized\n"));
    }
    catch(std::exception &e)
    {
        emit initializeDBFinished(FAIL, QString(e.what()));
    }
}
