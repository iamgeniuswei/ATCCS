/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCSelectionPanel.h
 * Author: lenovo
 *
 * Created on August 4, 2017, 9:12 AM
 */

#ifndef _ATCSELECTIONPANEL_H
#define _ATCSELECTIONPANEL_H

#include "ui_ATCSelectionPanel.h"
#include <QHash>
class ATCSelectionPanel : public QWidget
{
    Q_OBJECT
public:
    ATCSelectionPanel();
    virtual ~ATCSelectionPanel();
    void addATItem(unsigned int type, const QString& text);
    unsigned int at();
private:
    Ui::ATCSelectionPanel widget;
    QHash<unsigned int ,unsigned int> _itmeMap;
    unsigned int _index = 0;
    
};

#endif /* _ATCSELECTIONPANEL_H */
