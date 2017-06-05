/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on May 21, 2017, 9:40 AM
 */

#include <QApplication>
#include "qpuiframelesswidget.h"
#include <QSharedPointer>
#include "newForm.h"
#include "TestBtn.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here
    QSharedPointer<TestBtn> widget(new TestBtn);
    
    widget->show();

    return app.exec();
}
