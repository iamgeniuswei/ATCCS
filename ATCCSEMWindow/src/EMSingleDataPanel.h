/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMSingleDataPanel.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 8:39 AM
 */

#ifndef _EMSINGLEDATAPANEL_H
#define _EMSINGLEDATAPANEL_H

#include "ui_EMSingleDataPanel.h"
#include "QWUIInitializer.h"

class EMSingleDataPanel : public QWidget, protected QWUIInitializer
{
    Q_OBJECT
public:
    EMSingleDataPanel();
    virtual ~EMSingleDataPanel();

protected:
    virtual void initializeUI();
    virtual void initializeSignal();

public slots:
    void updateData(int value, unsigned int time);
    void setEMName(const QString& name);
private:
    Ui::EMSingleDataPanel widget;
};

#endif /* _EMSINGLEDATAPANEL_H */
