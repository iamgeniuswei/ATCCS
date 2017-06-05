/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newForm.cpp
 * Author: lenovo
 *
 * Created on May 21, 2017, 3:25 PM
 */

#include "newForm.h"
#include <QPushButton>
newForm::newForm() {
    widget.setupUi(this);
    QPixmap icon(":/main/back");
    widget.pushButton->setFixedSize(icon.size());
    widget.pushButton->setFlat(true);
    
}

newForm::~newForm() {
}
