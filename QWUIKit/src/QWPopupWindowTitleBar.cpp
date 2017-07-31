/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QWPopupWindowTitleBar.cpp
 * Author: lenovo
 * 
 * Created on June 30, 2017, 8:06 AM
 */

#include "QWPopupWindowTitleBar.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <iostream>

QWPopupWindowTitleBar::QWPopupWindowTitleBar(QWidget *parent)
:QFrame(parent)
{
    initializeUI();
}

QWPopupWindowTitleBar::~QWPopupWindowTitleBar()
{
    std::cerr << "~QWPopupWindowTitleBar" << std::endl;
}

void QWPopupWindowTitleBar::initializeUI()
{
    if (!_mainLayout)
    {
        try
        {
            _mainLayout = new QHBoxLayout(this);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return;
        }
    }
    _mainLayout->setContentsMargins(5, 5, 5, 5);

    if (!_logoLabel)
    {
        try
        {
            _logoLabel = new QLabel(this);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return;
        }
    }
    
    _mainLayout->addWidget(_logoLabel, 0, Qt::AlignLeft);

    if (!_titleLabel)
    {
        try
        {
            _titleLabel = new QLabel(this);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return;
        }
    }
    _mainLayout->addWidget(_titleLabel, 0, Qt::AlignLeft);
    _mainLayout->addStretch();
    
    if(!_closeBtn)
    {
        try
        {
            _closeBtn = new QToolButton(this);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return;
        }
    }
    _mainLayout->addWidget(_closeBtn, 0, Qt::AlignRight);
    setLayout(_mainLayout);
}

void QWPopupWindowTitleBar::setTitleObjectName(const QString& objectName)
{
    if(_titleLabel)
        _titleLabel->setObjectName(objectName);
}

void QWPopupWindowTitleBar::setLogoObjectName(const QString& objectName)
{
    if(_logoLabel)
        _logoLabel->setObjectName(objectName);
}

void QWPopupWindowTitleBar::setCloseBtnObjectName(const QString& objectName)
{
    if(_closeBtn)
        _closeBtn->setObjectName(objectName);
}




void QWPopupWindowTitleBar::setLogo(QPixmap& pixmap)
{
    if(_logoLabel)
    {
        pixmap = pixmap.scaled(32,40,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        _logoLabel->setPixmap(pixmap);
    }
            
}
