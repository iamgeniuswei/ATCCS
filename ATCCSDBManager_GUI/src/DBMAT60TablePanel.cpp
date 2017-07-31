/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DBMAT60TablePanel.cpp
 * Author: lenovo
 *
 * Created on July 29, 2017, 7:42 PM
 */

#include "DBMAT60TablePanel.h"
#include <iostream>
#include <odb/core.hxx>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
using namespace odb;
using namespace odb::core;
#include "ORMHelper.h"
DBMAT60TablePanel::DBMAT60TablePanel(QWidget *parent)
: QWidget(parent)
{
    widget.setupUi(this);
    initializeSignal();
}

DBMAT60TablePanel::~DBMAT60TablePanel()
{
}

void DBMAT60TablePanel::initializeSignal()
{
    connect(widget._btnSelectAll, &QPushButton::clicked,
            this, &DBMAT60TablePanel::selectAll);
    connect(widget._btnSelectNone, &QPushButton::clicked,
            this, &DBMAT60TablePanel::selectNone);
}

void DBMAT60TablePanel::selectAll()
{
    QObjectList child = this->children();
    for (auto item : child)
    {
        QCheckBox *cb = nullptr;
        if(cb = qobject_cast<QCheckBox*>(item))
            cb->setChecked(true);            
    }

}

void DBMAT60TablePanel::selectNone()
{
    QObjectList child = this->children();
    for (auto item : child)
    {
        QCheckBox *cb = nullptr;
        if(cb = qobject_cast<QCheckBox*>(item))
            cb->setChecked(false);            
    }
}

void DBMAT60TablePanel::initializeDatabase()
{
    try
    {
        std::shared_ptr<database> db = ORMHelper::db();
        transaction t(db->begin());
        if (widget._cbGimbal->isChecked())
            schema_catalog::create_schema(*db, "at60gimbalstatus");
        if (widget._cbCCD->isChecked())
            schema_catalog::create_schema(*db, "at60ccdstatus");
        if (widget._cbFilter->isChecked())
            schema_catalog::create_schema(*db, "at60filterstatus");
        if (widget._cbFocus->isChecked())
            schema_catalog::create_schema(*db, "at60focusstatus");
        if (widget._cbSlaveDome->isChecked())
            schema_catalog::create_schema(*db, "at60slavedomestatus");
        if (widget._cbInstruction->isChecked())
            schema_catalog::create_schema(*db, "at60instruction");
        if (widget._cbPlan->isChecked())
            schema_catalog::create_schema(*db, "at60plan");
        t.commit();
        emit initializeDBFinished(0, tr("AT60 tables are successfully initialized\n"));
    }
    catch (std::exception &e)
    {
        emit initializeDBFinished(1, QString(e.what()));
    }
}
