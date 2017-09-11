/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCSelectionWindow.cpp
 * Author: lenovo
 *
 * Created on August 4, 2017, 9:01 AM
 */

#include "ATCSelectionWindow.h"
#include "ATCMainWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPainter>
#include <qmath.h>
ATCSelectionWindow::ATCSelectionWindow()
{
    setAttribute(Qt::WA_TranslucentBackground);
    setObjectName("selection_window");
    _mainLayout = new QVBoxLayout();
    _titleBar = new QWPopupTitleBar();
    _titleBar->setTitle(tr("AT Selection"));
    _spliterTop = new QLabel();
    _spliterTop->setObjectName("horizontal_line");
    _spliterTop->setScaledContents(true);
    _spliterBottom = new QLabel();
    _spliterBottom->setScaledContents(true);
    _spliterBottom->setObjectName("horizontal_line");
    _selectionPanel = new ATCSelectionPanel();
    _selectionPanel->addATItem(100, tr("AT 60"));
    _selectionPanel->addATItem(200, tr("AT 80"));
    _btnPanel = new QWButtonPanel();
    _mainLayout->addWidget(_titleBar);
    _mainLayout->addWidget(_spliterTop);
    _mainLayout->addWidget(_selectionPanel);
    _mainLayout->addWidget(_spliterBottom);
    _mainLayout->addWidget(_btnPanel);
    setLayout(_mainLayout);
    initializeSignal();
}

ATCSelectionWindow::~ATCSelectionWindow()
{
}

void ATCSelectionWindow::paintEvent(QPaintEvent* event)
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

void ATCSelectionWindow::initializeSignal()
{
    if(_titleBar)
        connect(_titleBar, &QWPopupTitleBar::closeClicked,
                this, &ATCSelectionWindow::close);
    if(_btnPanel)
    {
        connect(_btnPanel, &QWButtonPanel::cancelClicked,
                this, &ATCSelectionWindow::close);
        connect(_btnPanel, &QWButtonPanel::okClicked,
                this, &ATCSelectionWindow::showMainWindow);   
    }
}

#include <QDebug>
#include <QDesktopWidget>
#include "ATCMainWindow.h"
void ATCSelectionWindow::showMainWindow()
{
    qDebug() << _selectionPanel->at();
    this->close();
    ATCMainWindow *w = new ATCMainWindow();
    w->show();
    w->move ((QApplication::desktop()->width() - w->width())/2,(QApplication::desktop()->height() - w->height())/2);
}
