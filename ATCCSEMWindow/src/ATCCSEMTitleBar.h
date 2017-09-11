/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSEMTitleBar.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 3:32 PM
 */

#ifndef _ATCCSEMTITLEBAR_H
#define _ATCCSEMTITLEBAR_H

#include "ui_ATCCSEMTitleBar.h"
#include "QWUIInitializer.h"

class ATCCSEMTitleBar : public QWidget, protected QWUIInitializer
{
    Q_OBJECT
public:
    ATCCSEMTitleBar();
    virtual ~ATCCSEMTitleBar();
protected:
    virtual void initializeUI();
    void initializeSignal() override;
signals:
    void btnSettingClicked();
    void btnCloseClicked();


private:
    Ui::ATCCSEMTitleBar widget;
};

#endif /* _ATCCSEMTITLEBAR_H */
