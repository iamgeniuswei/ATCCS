/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newForm1.h
 * Author: lenovo
 *
 * Created on July 28, 2017, 5:22 PM
 */

#ifndef _NEWFORM1_H
#define _NEWFORM1_H

#include "ui_newForm1.h"

class newForm1 : public QDialog
{
    Q_OBJECT
public:
    newForm1();
    virtual ~newForm1();
private:
    Ui::newForm1 widget;
};

#endif /* _NEWFORM1_H */
