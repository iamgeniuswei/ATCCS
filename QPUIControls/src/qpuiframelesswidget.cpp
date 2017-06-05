/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPUIWidget.cpp
 * Author: lenovo
 * 
 * Created on May 21, 2017, 9:12 AM
 */

#include "qpuiframelesswidget.h"
#include "private/qpuiframelesswidget_p.h"
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>
#include <algorithm>
#include <QPixmap>
QPUIFramelessWidget::QPUIFramelessWidget(QWidget *parent) : QWidget(parent),
        d_ptr(new QPUIFramelessWidgetPrivate)
{
    pixmap.load(":/main/back");
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setMouseTracking(true);
    setFixedSize(pixmap.size());
}


QPUIFramelessWidget::~QPUIFramelessWidget() 
{
    qDebug() << "~QPUIFramelessWidget";
}

void QPUIFramelessWidget::paintEvent(QPaintEvent*) 
{
    Q_D(QPUIFramelessWidget);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.save();
    painter.setBrush(QBrush(Qt::green));
    QRect rect1 = pixmap.rect();
    rect1.adjust(-10,-10,-10,-10);
    painter.drawEllipse(rect1);
    painter.restore();
    painter.drawPixmap(rect(), pixmap);
//    QPainterPath path;
//    path.setFillRule(Qt::WindingFill);
//    path.addRect(10, 10, this->width() - 20, this->height() - 20);
//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.fillPath(path, QBrush(Qt::white));
//
//    QColor color(0, 0, 0, 50);
//    for (int i = 0; i < 10; i++) {
//        QPainterPath path;
//        path.setFillRule(Qt::WindingFill);
//        path.addRect(10 - i, 10 - i, this->width()-(10 - i)*2, this->height()-(10 - i)*2);
//        color.setAlpha(150 - i * 50);
//        painter.setPen(color);
//        painter.drawPath(path);
//    }
}

//void QPUIFramelessWidget::mousePressEvent(QMouseEvent* event) 
//{
//    Q_D(QPUIFramelessWidget);
//     if (event->button() == Qt::LeftButton) {
//        d->m_drag = true;
//        d->dragPos = event->pos();
//
//        d->resizeDownPos = event->globalPos();
//        d->mouseDownRect = this->rect();
//    } 
//}
//
//void QPUIFramelessWidget::mouseMoveEvent(QMouseEvent* event) 
//{
//    Q_D(QPUIFramelessWidget);
//    if (d->resizeRegion != QPUIFramelessWidgetPrivate::Default)
//    {
//        handleResize();
//        return;
//    }
//    if(d->m_move) {
//        move(event->globalPos() - d->dragPos);
//        return;
//    }
//    QPoint clientCursorPos = event->pos();
//    QRect r = this->rect();
//    QRect resizeInnerRect(d->resizeBorderWidth, d->resizeBorderWidth, r.width() - 2*d->resizeBorderWidth, r.height() - 2*d->resizeBorderWidth);
//    if(r.contains(clientCursorPos) && !resizeInnerRect.contains(clientCursorPos)) { 
//        QPUIFramelessWidgetPrivate::ResizeRegion resizeReg = getResizeRegion(clientCursorPos);
//        setResizeCursor(resizeReg);
//        if (d->m_drag && (event->buttons() & Qt::LeftButton)) {
//            d->resizeRegion = resizeReg;
//            handleResize();
//        }
//    }
//    else {
//        setCursor(Qt::ArrowCursor);
//        if (d->m_drag && (event->buttons() & Qt::LeftButton)) {
//            d->m_move = true;
//            move(event->globalPos() - d->dragPos);
//        }
//    }
//}
//
//void QPUIFramelessWidget::mouseReleaseEvent(QMouseEvent* event) 
//{
//    Q_D(QPUIFramelessWidget);
//      d->m_drag = false;
//    if(d->m_move) {
//        d->m_move = false;
//        handleMove(event->globalPos()); 
//    }
//    d->resizeRegion = QPUIFramelessWidgetPrivate::Default;
//    setCursor(Qt::ArrowCursor);
//}
//
//void QPUIFramelessWidget::setResizeCursor(QPUIFramelessWidgetPrivate::ResizeRegion region) 
//{
//switch (region)
//    {
//    case QPUIFramelessWidgetPrivate::North:
//    case QPUIFramelessWidgetPrivate::South:
//        setCursor(Qt::SizeVerCursor);
//        break;
//    case QPUIFramelessWidgetPrivate::East:
//    case QPUIFramelessWidgetPrivate::West:
//        setCursor(Qt::SizeHorCursor);
//        break;
//    case QPUIFramelessWidgetPrivate::NorthWest:
//    case QPUIFramelessWidgetPrivate::SouthEast:
//        setCursor(Qt::SizeFDiagCursor);
//        break;
//    default:
//        setCursor(Qt::SizeBDiagCursor);
//        break;
//    }
//}
//
//QPUIFramelessWidgetPrivate::ResizeRegion QPUIFramelessWidget::getResizeRegion(QPoint clientPos) {
//
//    Q_D(QPUIFramelessWidget);
//    if (clientPos.y() <= d->resizeBorderWidth) {
//        if (clientPos.x() <= d->resizeBorderWidth)
//            return QPUIFramelessWidgetPrivate::NorthWest;
//        else if (clientPos.x() >= this->width() - d->resizeBorderWidth)
//            return QPUIFramelessWidgetPrivate::NorthEast;
//        else
//            return QPUIFramelessWidgetPrivate::North;
//    }
//    else if (clientPos.y() >= this->height() - d->resizeBorderWidth) {
//        if (clientPos.x() <= d->resizeBorderWidth)
//            return QPUIFramelessWidgetPrivate::SouthWest;
//        else if (clientPos.x() >= this->width() - d->resizeBorderWidth)
//            return QPUIFramelessWidgetPrivate::SouthEast;
//        else
//            return QPUIFramelessWidgetPrivate::South;
//    }
//    else {
//        if (clientPos.x() <= d->resizeBorderWidth)
//            return QPUIFramelessWidgetPrivate::West;
//        else
//            return QPUIFramelessWidgetPrivate::East;
//    }
//}
//
//
//
//void QPUIFramelessWidget::handleMove(QPoint pt) 
//{
//    Q_D(QPUIFramelessWidget);
//    QPoint currentPos = pt - d->dragPos;
//    if(currentPos.x()<QApplication::desktop()->x()) { //吸附于屏幕左侧
//        currentPos.setX(QApplication::desktop()->x());
//    }
//    else if (currentPos.x()+this->width()>QApplication::desktop()->width()) { //吸附于屏幕右侧
//        currentPos.setX(QApplication::desktop()->width()-this->width());
//    }
//    if(currentPos.y()<QApplication::desktop()->y()) { //吸附于屏幕顶部
//        currentPos.setY(QApplication::desktop()->y());
//    }
//    move(currentPos);
//}
//
//void QPUIFramelessWidget::handleResize() 
//{
//    Q_D(QPUIFramelessWidget);
//int xdiff = QCursor::pos().x() - d->resizeDownPos.x();
//    int ydiff = QCursor::pos().y() -  d->resizeDownPos.y();
//    switch ( d->resizeRegion)
//    {
//    case QPUIFramelessWidgetPrivate::East:
//    {
//        resize( d->mouseDownRect.width()+xdiff, this->height());
//        break;
//    }
//    case QPUIFramelessWidgetPrivate::West:
//    {
//        resize( d->mouseDownRect.width()-xdiff, this->height());
//        move( d->resizeDownPos.x()+xdiff, this->y());
//        break;
//    }
//    case QPUIFramelessWidgetPrivate::South:
//    {
//        resize(this->width(), d->mouseDownRect.height()+ydiff);
//        break;
//    }
//    case QPUIFramelessWidgetPrivate::North:
//    {
//        resize(this->width(), d->mouseDownRect.height()-ydiff);
//        move(this->x(),  d->resizeDownPos.y()+ydiff);
//        break;
//    }
//    case QPUIFramelessWidgetPrivate::SouthEast:
//    {
//        resize( d->mouseDownRect.width() + xdiff,  d->mouseDownRect.height() + ydiff);
//        break;
//    }
//    case QPUIFramelessWidgetPrivate::NorthEast:
//    {
//        resize( d->mouseDownRect.width()+xdiff,  d->mouseDownRect.height()-ydiff);
//        move(this->x(),  d->resizeDownPos.y()+ydiff);
//        break;
//    }
//    case QPUIFramelessWidgetPrivate::NorthWest:
//    {
//        resize( d->mouseDownRect.width()-xdiff,  d->mouseDownRect.height()-ydiff);
//        move( d->resizeDownPos.x()+xdiff,  d->resizeDownPos.y()+ydiff);
//        break;
//    }
//    case QPUIFramelessWidgetPrivate::SouthWest:
//    {
//        resize( d->mouseDownRect.width()-xdiff,  d->mouseDownRect.height()+ydiff);
//        move( d->resizeDownPos.x()+xdiff, this->y());
//        break;
//    }
//    }
//}

void QPUIFramelessWidget::mouseMoveEvent(QMouseEvent* event) 
{
    Q_D(QPUIFramelessWidget);
    if(d->m_drag && (event->buttons() && Qt::LeftButton))
    {
        move(event->globalPos() - d->dragPos);
//        event->accept();
    }
}

void QPUIFramelessWidget::mousePressEvent(QMouseEvent* event) 
{
    Q_D(QPUIFramelessWidget);
    if(event->button() == Qt::LeftButton)
    {
        d->m_drag = true;
        d->dragPos = event->globalPos() - this->pos();
        
//        event->accept();
    }
}

void QPUIFramelessWidget::mouseReleaseEvent(QMouseEvent*) {
Q_D(QPUIFramelessWidget);
d->m_drag = false;
}


