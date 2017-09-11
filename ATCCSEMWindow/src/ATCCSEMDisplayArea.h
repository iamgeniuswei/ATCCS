/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSEMDisplayArea.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 3:57 PM
 */

#ifndef _ATCCSEMDISPLAYAREA_H
#define _ATCCSEMDISPLAYAREA_H

#include "QWUIInitializer.h"
#include <QWidget>
class QGridLayout;
class ATCCSEMDisplayArea : public QWidget, protected QWUIInitializer
{
    Q_OBJECT
public:
    ATCCSEMDisplayArea(QWidget *parent = 0);
    virtual ~ATCCSEMDisplayArea();
    void addEMDisplayPanel(QWidget *panel = nullptr);
protected:
    void initializeUI() override;

private:
    QGridLayout *_mainLayout;
    unsigned int _panelCount = 0;

};

#endif /* _ATCCSEMDISPLAYAREA_H */
