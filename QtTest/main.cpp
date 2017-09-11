/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on July 28, 2017, 5:02 PM
 */

#include <QApplication>
#include <QTranslator>
#include "newForm.h"
int main(int argc, char *argv[])
{
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here
    const QString langPath = "/home/lenovo/Project/ATCCS/QtTest/nbproject/newtranslation.qm";
    QTranslator translator;
    translator.load(langPath);
    app.installTranslator(&translator);

    newForm w;
    w.show();
    return app.exec();
}
