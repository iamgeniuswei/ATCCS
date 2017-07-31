/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QWFramelessWindow.h
 * Author: lenovo
 *
 * Created on June 30, 2017, 8:56 AM
 */

#ifndef QWFRAMELESSWINDOW_H
#define QWFRAMELESSWINDOW_H
#include <QWidget>
class QWFramelessWindow : public QWidget
{
    Q_OBJECT
    enum Direction
    {
        TOP,
        BOTTOM,
        LEFT,
        RIGHT,
        LEFT_TOP,
        LEFT_BOTTOM,
        RIGHT_TOP,
        RIGHT_BOTTOM,
        NONE
    };
public:
    QWFramelessWindow(QWidget *parent = 0);
    QWFramelessWindow(const QWFramelessWindow& orig) = delete;
    QWFramelessWindow(const QWFramelessWindow&& orig) = delete;
    QWFramelessWindow& operator=(const QWFramelessWindow& orig) = delete;
    QWFramelessWindow& operator=(const QWFramelessWindow&& orig) = delete;
    virtual ~QWFramelessWindow();

protected:
    void centerToDesktop();
    void region(const QPoint& cursorPoint);
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;




private:
    static const int PADDING = 2;
    bool _isLeftPressDown = false;
    Direction _direction = NONE;
    QPoint _dragPosition;
};

#endif /* QWFRAMELESSWINDOW_H */

