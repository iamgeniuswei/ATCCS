/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPUIWidget.h
 * Author: lenovo
 *
 * Created on May 21, 2017, 9:12 AM
 */

#ifndef QPUIWIDGET_H
#define QPUIWIDGET_H

#include <QWidget>

#include "private/qpuiframelesswidget_p.h"


class QPUIFramelessWidgetPrivate;
class QPUIFramelessWidget : public QWidget
{
public:
    QPUIFramelessWidget(QWidget *parent = 0);
    QPUIFramelessWidget(const QPUIFramelessWidget& orig) = delete;
    virtual ~QPUIFramelessWidget();

public:
    void SetMinWidth(unsigned int _minWidth);
    unsigned int GetMinWidth() const;

    void SetMinHeight(unsigned int _minHeight);
    unsigned int GetMinHeight() const;

    void SetYRadius(unsigned int _yRadius);
    unsigned int GetYRadius() const;

    void SetXRadius(unsigned int _xRadius);
    unsigned int GetXRadius() const;
    
protected:
    virtual void paintEvent(QPaintEvent*);
    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);

//    void setResizeCursor(QPUIFramelessWidgetPrivate::ResizeRegion region);
//    QPUIFramelessWidgetPrivate::ResizeRegion getResizeRegion(QPoint clientPos);
//    void handleMove(QPoint pt);
//    void handleResize();

private:
    QPixmap pixmap;
    QPUIFramelessWidgetPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPUIFramelessWidget)
};

#endif /* QPUIWIDGET_H */

