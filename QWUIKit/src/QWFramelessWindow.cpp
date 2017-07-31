/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QWFramelessWindow.cpp
 * Author: lenovo
 * 
 * Created on June 30, 2017, 8:56 AM
 */

#include "QWFramelessWindow.h"
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QApplication>
#include <iostream>
#include <QPushButton>
QWFramelessWindow::QWFramelessWindow(QWidget *parent)
:QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setMouseTracking(true);
}

QWFramelessWindow::~QWFramelessWindow()
{
    std::cerr << "~QWFramelessWindow()" << std::endl;
}

void QWFramelessWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        _isLeftPressDown = false;
        if(_direction != NONE)
        {
            releaseMouse();
            setCursor(Qt::ArrowCursor);
        }
    }
}

void QWFramelessWindow::mousePressEvent(QMouseEvent* event)
{
    switch(event->button())
    {
        case Qt::LeftButton:
        {
            _isLeftPressDown = true;
            if(_direction != NONE)
            {
                mouseGrabber();
            }
            else
            {
                _dragPosition = event->globalPos() - frameGeometry().topLeft();
            }
            break;
        }
        case Qt::RightButton:
        {
            close();
            break;
        }
        default:
            QWidget::mousePressEvent(event);
    }
}

void QWFramelessWindow::mouseMoveEvent(QMouseEvent* event)
{
    QPoint globalPoint = event->globalPos();
    QRect rect = this->rect();
    QPoint top_left = mapToGlobal(rect.topLeft());
    QPoint right_bottom = mapToGlobal(rect.bottomRight());
    
    if(!_isLeftPressDown)
    {
        region(globalPoint);
    }
    else
    {
        if(_direction != NONE)
        {
            QRect rMove(top_left, right_bottom);
            
            switch(_direction)
            {
                case LEFT:
                {
                    if(right_bottom.x() - globalPoint.x() <= minimumWidth())
                        rMove.setX(top_left.x());
                    else
                        rMove.setX(globalPoint.x());
                    break;
                }
                case RIGHT:
                {
                    rMove.setWidth(globalPoint.x() - top_left.x());
                    break;
                }
                case TOP:
                {
                    if(right_bottom.y() - globalPoint.y() <= minimumHeight())
                        rMove.setY(top_left.y());
                    else
                        rMove.setY(globalPoint.y());                            
                    break;
                }
                case BOTTOM:
                {
                    rMove.setHeight(globalPoint.y() - top_left.y());
                    break;
                }
                case LEFT_TOP:
                {
                    if(right_bottom.x() - globalPoint.x() <= minimumWidth())
                        rMove.setX(top_left.x());
                    else
                        rMove.setX(globalPoint.x());
                    if(right_bottom.y() - globalPoint.y() <= minimumHeight())
                        rMove.setY(top_left.y());
                    else
                        rMove.setY(globalPoint.y());
                    break;
                }
                case RIGHT_TOP:
                {
                    rMove.setWidth(globalPoint.x() - top_left.x());
                    rMove.setY(globalPoint.y());
                    break;
                }
                case LEFT_BOTTOM:
                {
                    rMove.setX(globalPoint.x());
                    rMove.setHeight(globalPoint.y() - top_left.y());
                    break;
                }
                case RIGHT_BOTTOM:
                {
                    rMove.setWidth(globalPoint.x() - top_left.x());
                    rMove.setHeight(globalPoint.y() - top_left.y());
                    break;
                }
                default:
                    break;
            }
            
            setGeometry(rMove);
        }
        else
        {
            move(globalPoint - _dragPosition);
            event->accept();
        }
    }
    
    QWidget::mouseMoveEvent(event);
}

void QWFramelessWindow::region(const QPoint& cursorPoint)
{
    QRect rect = this->rect();
    QPoint top_left = mapToGlobal(rect.topLeft());
    QPoint right_bottom = mapToGlobal(rect.bottomRight());
    int x = cursorPoint.x();
    int y = cursorPoint.y();
    
    if(top_left.x() + PADDING >= x 
       && top_left.x() <= x 
       && top_left.y() + PADDING >=y 
       && top_left.y() <=y)
    {
        //left-top
        _direction = LEFT_TOP;
        setCursor(Qt::SizeFDiagCursor);
    }
    else if(x >= right_bottom.x() - PADDING
            && x <= right_bottom.x() 
            && y >= right_bottom.y() - PADDING
            && y <= right_bottom.y())
    {
        //right-bottom
        _direction = RIGHT_BOTTOM;
        setCursor(Qt::SizeFDiagCursor);
    }
    else if(x <= top_left.x() + PADDING
            && x >= top_left.x()
            && y >= right_bottom.y() - PADDING
            && y <= right_bottom.y())
    {
        //left-bottom
        _direction = LEFT_BOTTOM;
        setCursor(Qt::SizeBDiagCursor);
    }
    else if(x <= right_bottom.x()
                                && x >= right_bottom.x() - PADDING
            && y >= top_left.y()
                               && y <= top_left.y() + PADDING)
    {
        //right-top
        _direction = RIGHT_TOP;
        setCursor(Qt::SizeBDiagCursor);
    }
    else if(x <= top_left.x() + PADDING
            && x >= top_left.x())
    {
        //left
        _direction = LEFT;
        setCursor(Qt::SizeHorCursor);
    }
    else if(x <= right_bottom.x()
            && x >= right_bottom.x() - PADDING )
    {
        _direction = RIGHT;
        setCursor(Qt::SizeHorCursor);
    }
    else if(y >= top_left.y()
                            && y <= top_left.y() + PADDING)
    {
        _direction = TOP;
        setCursor(Qt::SizeVerCursor);
    }
    else if(y <= right_bottom.y()
                                && y >= right_bottom.y() - PADDING)
    {
        _direction = BOTTOM;
        setCursor(Qt::SizeVerCursor);
    }
    else
    {
        _direction = NONE;
        setCursor(Qt::ArrowCursor);
    }
}

void QWFramelessWindow::centerToDesktop()
{
    QDesktopWidget *desktop = QApplication::desktop();
    if(desktop)
        move((desktop->width() - width())/2, (desktop->height() - height())/2);  
}
