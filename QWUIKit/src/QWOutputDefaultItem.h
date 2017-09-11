/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QWOutputDefaultItem.h
 * Author: lenovo
 *
 * Created on August 2, 2017, 8:31 AM
 */

#ifndef _QWOUTPUTDEFAULTITEM_H
#define _QWOUTPUTDEFAULTITEM_H

#include "ui_QWOutputDefaultItem.h"


class QWOutputDefaultItem : public QWidget
{
    Q_OBJECT
public:
    QWOutputDefaultItem(QWidget *parent = 0);
    virtual ~QWOutputDefaultItem();
    void setIcon(const QPixmap& icon);
    void setText(const QString& text);
private:
    Ui::QWOutputDefaultItem widget;
};

#endif /* _QWOUTPUTDEFAULTITEM_H */
