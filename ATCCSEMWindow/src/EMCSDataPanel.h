/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMCSDataPanel.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 9:46 AM
 */

#ifndef _EMCSDATAPANEL_H
#define _EMCSDATAPANEL_H

#include "ui_EMCSDataPanel.h"


class EMCSDataPanel : public QWidget
{
    Q_OBJECT
public:
    EMCSDataPanel();
    virtual ~EMCSDataPanel();
private:
    Ui::EMCSDataPanel widget;
};

#endif /* _EMCSDATAPANEL_H */
