/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCDisplayArea.h
 * Author: lenovo
 *
 * Created on August 3, 2017, 5:38 PM
 */

#ifndef _ATCDISPLAYAREA_H
#define _ATCDISPLAYAREA_H

#include "ui_ATCDisplayArea.h"
#include "ATCDevicePanel.h"
#include <QHash>

class ATCDisplayArea : public QWidget
{
    Q_OBJECT
public:
    ATCDisplayArea();
    virtual ~ATCDisplayArea();
    void addDevicePanel(unsigned int type, const QString& name);
private:
    QGridLayout *_mainLayout;
    QHash<unsigned int, ATCDevicePanel*> _panelMap;
};

#endif /* _ATCDISPLAYAREA_H */
