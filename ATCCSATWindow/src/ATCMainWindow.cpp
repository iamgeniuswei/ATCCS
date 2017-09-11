/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCMainWindow.cpp
 * Author: lenovo
 *
 * Created on August 3, 2017, 5:50 PM
 */

#include "ATCMainWindow.h"
#include <QPainter>
#include <qmath.h>
ATCMainWindow::ATCMainWindow()
{
    setAttribute(Qt::WA_TranslucentBackground);
    _mainLayout = new QVBoxLayout(this);
    _mainLayout->setContentsMargins(10, 10, 10, 20);
    _titleBar = new ATCTitleBar(this);
    _displayArea = new ATCDisplayArea();
    _displayArea->addDevicePanel(100, "Gimbal");
    _displayArea->addDevicePanel(200, "CCD");
    _displayArea->addDevicePanel(300, "Focus");
    _displayArea->addDevicePanel(400, "Filter");
    _displayArea->addDevicePanel(500, "SlaveDome");
    _displayArea->addDevicePanel(600, "DPM");
    _outputArea = new QWOutputPanel();
    _mainLayout->addWidget(_titleBar);
    _mainLayout->addWidget(_displayArea);
    _mainLayout->addWidget(_outputArea);
    setLayout(_mainLayout);
    initializeSignal();
//    centerToDesktop();
    
}

ATCMainWindow::~ATCMainWindow()
{
}

void ATCMainWindow::paintEvent(QPaintEvent* event)
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(10, 10, this->width()-20, this->height()-20);
//    path.addRoundRect(10, 10, this->width()-20, this->height()-10, 2);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 50);
    for(int i=0; i<10; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(10-i, 10-i, this->width()-(10-i)*2, this->height()-(10-i)*2);
//        path.addRoundRect(10-i, 10-i, this->width()-(5-i)*2, this->height()-(5-i)*2, 2);
        color.setAlpha(150 - qSqrt(i)*50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void ATCMainWindow::initializeSignal()
{
    connect(_titleBar, &ATCTitleBar::closeClicked,
            this, &ATCMainWindow::close);
    connect(_titleBar, &ATCTitleBar::minClicked,
            this, &ATCMainWindow::showMinimized);    
}
