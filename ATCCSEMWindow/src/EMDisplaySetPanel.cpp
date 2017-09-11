/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EMDisplaySetPanel.cpp
 * Author: lenovo
 *
 * Created on August 1, 2017, 9:53 AM
 */

#include "EMDisplaySetPanel.h"
#include <QPushButton>
EMDisplaySetPanel::EMDisplaySetPanel(QWidget *parent)
:QWidget(parent)
{
    widget.setupUi(this);
    initializeSignal();
}

EMDisplaySetPanel::~EMDisplaySetPanel()
{
}

void EMDisplaySetPanel::selectAll()
{
    QObjectList child = this->children();
    for (auto item : child)
    {
        QCheckBox *cb = nullptr;
        if (cb = qobject_cast<QCheckBox*>(item))
            cb->setChecked(true);
    }
}

void EMDisplaySetPanel::selectNone()
{
    QObjectList child = this->children();
    for (auto item : child)
    {
        QCheckBox *cb = nullptr;
        if (cb = qobject_cast<QCheckBox*>(item))
            cb->setChecked(false);
    }
}

void EMDisplaySetPanel::initializeSignal()
{
    connect(widget._selectAll, &QPushButton::clicked,
            this, &EMDisplaySetPanel::selectAll);
    connect(widget._selectNone, &QPushButton::clicked,
            this, &EMDisplaySetPanel::selectNone);
}
