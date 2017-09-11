/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newForm.h
 * Author: lenovo
 *
 * Created on July 28, 2017, 5:03 PM
 */

#ifndef _NEWFORM_H
#define _NEWFORM_H

#include "ui_newForm.h"

class newForm : public QWidget
{
    Q_OBJECT
public:
    newForm();
    virtual ~newForm();
private:
    Ui::newForm widget;
};

#endif /* _NEWFORM_H */
