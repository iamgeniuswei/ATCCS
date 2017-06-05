/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   qpuiframelesswidget_p.h
 * Author: lenovo
 *
 * Created on May 21, 2017, 9:20 AM
 */

#ifndef QPUIFRAMELESSWIDGET_P_H
#define QPUIFRAMELESSWIDGET_P_H

#include <QPoint>
class QPUIFramelessWidget;

class QPUIFramelessWidgetPrivate
{
public:
    QPUIFramelessWidgetPrivate()
    {
        
    }
    enum ResizeRegion
{
    Default,
    North,
    NorthEast,
    East,
    SouthEast,
    South,
    SouthWest,
    West,
    NorthWest
};
public:
    unsigned int _xRadius = 0;
    unsigned int _yRadius = 0;
    unsigned int _minHeight = 1024;
    unsigned int _minWidth = 768;
    
    QPoint dragPos, resizeDownPos;
    volatile bool m_drag = false;
    volatile bool m_move = false;
    const int resizeBorderWidth = 5;
    ResizeRegion resizeRegion;
    QRect mouseDownRect;
};


#endif /* QPUIFRAMELESSWIDGET_P_H */

