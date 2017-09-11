/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QWPopupTitleBar.h
 * Author: lenovo
 *
 * Created on August 4, 2017, 8:53 AM
 */

#ifndef _QWPOPUPTITLEBAR_H
#define _QWPOPUPTITLEBAR_H

#include "ui_QWPopupTitleBar.h"

class QWPopupTitleBar : public QWidget
{
    Q_OBJECT
public:
    QWPopupTitleBar(QWidget *parent = 0);
    virtual ~QWPopupTitleBar();
    void setTitle(const QString& _title);
signals:
    void closeClicked();
private:
    Ui::QWPopupTitleBar widget;
};

#endif /* _QWPOPUPTITLEBAR_H */
