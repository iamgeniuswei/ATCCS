/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMDisplaySetPanel.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 9:53 AM
 */

#ifndef _EMDISPLAYSETPANEL_H
#define _EMDISPLAYSETPANEL_H

#include "ui_EMDisplaySetPanel.h"
#include "QWUIInitializer.h"
class EMDisplaySetPanel : public QWidget, protected QWUIInitializer
{
    Q_OBJECT
public:
    EMDisplaySetPanel(QWidget *parent = 0);
    virtual ~EMDisplaySetPanel();

public slots:
    void selectAll();
    void selectNone();

protected:
    void initializeSignal() override;

private:
    Ui::EMDisplaySetPanel widget;
};

#endif /* _EMDISPLAYSETPANEL_H */
