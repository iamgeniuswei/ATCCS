/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on August 3, 2017, 11:42 AM
 */

#include <QApplication>
#include "ATCTitleBar.h"
#include "ATCDevicePanel.h"
#include <QFile>
#include <QTranslator>
#include "ATCDisplayArea.h"
#include "ATCMainWindow.h"
#include <QDesktopWidget>
#include "ATCSelectionWindow.h"
#include "ATCSettingWindow.h"
int main(int argc, char *argv[])
{
    // initialize resources, if needed
     Q_INIT_RESOURCE(ATCCSATWindow);

    QApplication app(argc, argv);
    
    QFile qss(":/qss/default");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
        //load translator
    const QString langPath = ":/lang/zh_CN";
    QTranslator translator;
    translator.load(langPath);
    app.installTranslator(&translator);

    // create and show your widgets here
    ATCSettingWindow w;
    w.show();
    w.move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);

    return app.exec();
}
