/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   QWPopupTitleBar.cpp
 * Author: lenovo
 *
 * Created on August 4, 2017, 8:53 AM
 */

#include "QWPopupTitleBar.h"

QWPopupTitleBar::QWPopupTitleBar(QWidget *parent)
:QWidget(parent)
{
    widget.setupUi(this);
    if(widget._title)
        widget._title->setObjectName("popup_title");
    if(widget._close)
        widget._close->setObjectName("close");
    if(widget._close)
        connect(widget._close, &QToolButton::clicked,
                this, &QWPopupTitleBar::closeClicked);

}

QWPopupTitleBar::~QWPopupTitleBar()
{
}

void QWPopupTitleBar::setTitle(const QString& _title)
{
    if(widget._title)
        widget._title->setText(_title);
}
