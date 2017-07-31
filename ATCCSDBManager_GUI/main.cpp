/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on July 28, 2017, 9:55 AM
 */

#include <QApplication>
#include <QFile>
#include "src/ATCCSDBMStartup.h"
#include "src/DBMStartupBtnPanel.h"
#include "src/DBMStarupEditPanel.h"
#include "src/ATCCSDBMMainWindow.h"
int main(int argc, char *argv[])
{
    // initialize resources, if needed
     Q_INIT_RESOURCE(ATCCSDBManager);

    QApplication app(argc, argv);

    QFile qss(":/qss/default");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    // create and show your widgets here
    ATCCSDBMStartup w;
    w.show();
    return app.exec();
}
