/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on August 1, 2017, 8:10 AM
 */

#include <QApplication>
#include "EMSingleDataPanel.h"
#include "ATCCSEMSettingWindow.h"
#include "ATCCSEMWindow.h"
#include <QFile>
#include "emsetting.h"

int main(int argc, char *argv[])
{
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    Q_INIT_RESOURCE(ATCCSEMWindow);

    QApplication app(argc, argv);
    
    QFile qss(":/qss/default");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    // create and show your widgets here
    ATCCSEMWindow w;
    w.show();
    EMSetting *setting = EMSetting::instance();
    setting->initSysSetting();
    

    return app.exec();
}
