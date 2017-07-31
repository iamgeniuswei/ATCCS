/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DBMWOutPanel.cpp
 * Author: lenovo
 *
 * Created on July 31, 2017, 4:24 PM
 */

#include "DBMWOutPanel.h"
#include "DBMWOutputItem.h"

DBMWOutPanel::DBMWOutPanel()
{
    widget.setupUi(this);
    initializeUI();
}

DBMWOutPanel::~DBMWOutPanel()
{
}

void DBMWOutPanel::updateOutput(int ret, const QString& msg)
{
    DBMWOutputItem *item = new DBMWOutputItem(ret, msg);
    QListWidgetItem *row = new QListWidgetItem(widget.listWidget);
    row->setSizeHint(QSize(200, 32));
    widget.listWidget->setItemWidget(row, item);
}

void DBMWOutPanel::initializeUI()
{
    widget.listWidget->setFocusPolicy(Qt::NoFocus);
}
