/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QWTitleBar.cpp
 * Author: lenovo
 * 
 * Created on June 29, 2017, 10:18 AM
 */

#include "QWTitleBar.h"
#include "private/qwtitlebar_p.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
QWTitleBar::QWTitleBar(QWidget *parent)
        :QFrame(parent), d_ptr(new QWTitleBarPrivate(this))
{
    Q_D(QWTitleBar);
    d->init();
    setLayout(d->_mainLayout);
}

QWTitleBar::~QWTitleBar()
{
}

void QWTitleBar::addTitleLogo(QLabel* logo)
{
    if(!logo)
        return;
    Q_D(QWTitleBar);
    if(!d->_mainLayout)
    {
        return;
    }
    d->_mainLayout->addWidget(logo, 0, 1, ROW, 1, Qt::AlignVCenter);    
}

void QWTitleBar::addTitleMainHead(QLabel* head)
{
    if(!head)
        return;
    Q_D(QWTitleBar);
    if(!d->_mainLayout)
        return;
    d->_mainLayout->addWidget(head, 1, 2, 1, 1, Qt::AlignBottom|Qt::AlignLeft);
}

void QWTitleBar::addSystemButton(QPushButton* btn)
{
    if(!btn)
        return;
    Q_D(QWTitleBar);
    if(!d->_sysBtnLayout)
        d->_sysBtnLayout = new QHBoxLayout();
    d->_sysBtnLayout->addWidget(btn);
    d->_mainLayout->addLayout(d->_sysBtnLayout, 0, 7, 1, 1, Qt::AlignRight|Qt::AlignTop);
}


void QWTitleBar::addTitleSubHead(QLabel* head)
{
    if(!head)
        return;
    Q_D(QWTitleBar);
    if(!d->_mainLayout)
        return;
    d->_mainLayout->addWidget(head, 2, 2, 1, 1, Qt::AlignTop|Qt::AlignLeft);
}



void QWTitleBarPrivate::init()
{
    _mainLayout = new QGridLayout(q_ptr);
    _mainLayout->setMargin(0);
}
