/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DMBEMETablePanel.cpp
 * Author: lenovo
 *
 * Created on July 29, 2017, 7:39 PM
 */

#include "DBMEMETablePanel.h"
#include <iostream>
#include <odb/core.hxx>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
using namespace odb;
using namespace odb::core;
#include "ORMHelper.h"
DBMEMETablePanel::DBMEMETablePanel(QWidget *parent)
:QWidget(parent)
{
    widget.setupUi(this);
    initializeSignal();
}

DBMEMETablePanel::~DBMEMETablePanel()
{
}

void DBMEMETablePanel::initializeSignal()
{
    connect(widget._btnSelectAll, &QPushButton::clicked,
            this, &DBMEMETablePanel::selectAll);
    connect(widget._btnSelectNone, &QPushButton::clicked,
             this, &DBMEMETablePanel::selectNone);
}

void DBMEMETablePanel::selectAll()
{
    if(widget._cbASC)
        widget._cbASC->setChecked(true);
    if(widget._cbWS)
        widget._cbWS->setChecked(true);
    if(widget._cbCS)
        widget._cbCS->setChecked(true);
    if(widget._cbDust)
        widget._cbDust->setChecked(true);
    if(widget._cbSQM)
        widget._cbSQM->setChecked(true);
    if(widget._cbDIMM)
        widget._cbDIMM->setChecked(true);
}

void DBMEMETablePanel::selectNone()
{
    if(widget._cbASC)
        widget._cbASC->setChecked(false);
    if(widget._cbWS)
        widget._cbWS->setChecked(false);
    if(widget._cbCS)
        widget._cbCS->setChecked(false);
    if(widget._cbDust)
        widget._cbDust->setChecked(false);
    if(widget._cbSQM)
        widget._cbSQM->setChecked(false);
    if(widget._cbDIMM)
        widget._cbDIMM->setChecked(false);
}

void DBMEMETablePanel::initializeDatabase()
{
    try
    {
        std::shared_ptr<database> db = ORMHelper::db();
        transaction t(db->begin());
        if (widget._cbWS->isChecked())
            schema_catalog::create_schema(*db, "wsrealtimedata");
        if (widget._cbCS->isChecked())
            schema_catalog::create_schema(*db, "csrealtimedata");
        if (widget._cbASC->isChecked())
            schema_catalog::create_schema(*db, "ascrealtimedata");
        if (widget._cbSQM->isChecked())
            schema_catalog::create_schema(*db, "sqmrealtimedata");
        if (widget._cbDust->isChecked())
            schema_catalog::create_schema(*db, "dustrealtimedata");
        if (widget._cbDIMM->isChecked())
            schema_catalog::create_schema(*db, "dimmrealtimedata");
        t.commit();
        emit initializeDBFinished(0, tr("EME tables are successfully initialized\n"));
    }
    catch (std::exception &e)
    {
        emit initializeDBFinished(1, QString(e.what()));
    }
}
