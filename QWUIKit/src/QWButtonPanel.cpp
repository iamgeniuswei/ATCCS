/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   QWButtonPanel.cpp
 * Author: lenovo
 *
 * Created on August 4, 2017, 9:09 AM
 */

#include "QWButtonPanel.h"
#include <QPushButton>
QWButtonPanel::QWButtonPanel(QWidget *parent)
:QWidget(parent)
{
    widget.setupUi(this);
    connect(widget._ok, &QPushButton::clicked,
            this, &QWButtonPanel::okClicked);
    connect(widget._cancel, &QPushButton::clicked,
            this, &QWButtonPanel::cancelClicked);
    widget._ok->setFocus();
    widget._cancel->setFocus();
    widget._cancel->setShortcut(QKeySequence::InsertParagraphSeparator ); 
}

QWButtonPanel::~QWButtonPanel()
{
}
