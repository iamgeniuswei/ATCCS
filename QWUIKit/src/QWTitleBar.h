/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QWTitleBar.h
 * Author: lenovo
 *
 * Created on June 29, 2017, 10:18 AM
 */

#ifndef QWTITLEBAR_H
#define QWTITLEBAR_H
#include <QFrame>

#include "private/qwtitlebar_p.h"
class QWTitleBarPrivate;
class QLabel;
class QPushButton;
class  QWTitleBar : public QFrame
{
    enum
    {
        ROW = 4
    };
public:
    QWTitleBar(QWidget *parent = 0);
    QWTitleBar(const QWTitleBar& orig) = delete;
    QWTitleBar(const QWTitleBar&& orig) = delete;
    QWTitleBar& operator=(const QWTitleBar& orig) = delete;
    QWTitleBar& operator=(const QWTitleBar&& orig) = delete;
    virtual ~QWTitleBar();
    
    void addTitleLogo(QLabel *logo = nullptr);
    void addTitleMainHead(QLabel *head = nullptr);
    void addTitleSubHead(QLabel *head = nullptr);
    void addSystemButton(QPushButton *btn = nullptr);
    void addCustomField(QWidget *field = nullptr);

protected:

private:
    QWTitleBarPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QWTitleBar)

};

#endif /* QWTITLEBAR_H */

