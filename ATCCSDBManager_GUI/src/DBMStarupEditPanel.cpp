/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DBMStarupEditPanel.cpp
 * Author: lenovo
 *
 * Created on July 28, 2017, 11:42 AM
 */

#include "DBMStarupEditPanel.h"
#include <QRegExp>
#include <QRegExpValidator>
#include "ORMHelper.h"
DBMStarupEditPanel::DBMStarupEditPanel(QWidget *parent)
:QWidget(parent)
{
    widget.setupUi(this);
    initializeUI();
}

DBMStarupEditPanel::~DBMStarupEditPanel()
{
}

void DBMStarupEditPanel::initializeUI()
{
    QRegExp portRegExp = QRegExp("((6553[0-5])|[655[0-2][0-9]|65[0-4][0-9]{2}|6[0-4][0-9]{3}|[1-5][0-9]{4}|[1-9][0-9]{3}|[1-9][0-9]{2}|[1-9][0-9]|[0-9])");
    widget._dbPort->setValidator(new QRegExpValidator(portRegExp));
    

    QRegExp regExpIP("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])[\\.]){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])"); 
    widget._dbIP->setValidator(new QRegExpValidator(regExpIP, this));
}

void DBMStarupEditPanel::connectToDatabase()
{
    try
    {
        ORMHelper::initDB(widget._dbType->currentText().toStdString(), 
                          widget._dbUser->text().toStdString(),
                          widget._dbPassword->text().toStdString(),
                          widget._dbName->text().toStdString(),
                          widget._dbIP->text().toStdString(),
                          widget._dbPort->text().toShort());
        std::shared_ptr<database> db = ORMHelper::db();
        db->connection();
        widget._outputTag->setText(tr("Success to connect"));
        emit successToConnectDB();
    }
    catch(std::exception &e)
    {
        widget._outputTag->setText(e.what());
    }
}
