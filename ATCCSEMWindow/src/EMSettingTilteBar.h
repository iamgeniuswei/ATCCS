/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMSettingTilteBar.h
 * Author: lenovo
 *
 * Created on August 2, 2017, 10:38 AM
 */

#ifndef _EMSETTINGTILTEBAR_H
#define _EMSETTINGTILTEBAR_H

#include "ui_EMSettingTilteBar.h"
#include "QWUIInitializer.h"

class EMSettingTilteBar : public QWidget, protected QWUIInitializer
{
    Q_OBJECT
public:
    EMSettingTilteBar(QWidget *parent = 0);
    virtual ~EMSettingTilteBar();

protected:
    void initializeSignal() override;
    
    signals:
    void closeBtnClicked();

private:
    Ui::EMSettingTilteBar widget;
};

#endif /* _EMSETTINGTILTEBAR_H */
