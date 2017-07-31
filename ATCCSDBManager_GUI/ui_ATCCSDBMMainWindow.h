/********************************************************************************
** Form generated from reading UI file 'ATCCSDBMMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCCSDBMMAINWINDOW_H
#define UI_ATCCSDBMMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCCSDBMMainWindow
{
public:

    void setupUi(QWidget *ATCCSDBMMainWindow)
    {
        if (ATCCSDBMMainWindow->objectName().isEmpty())
            ATCCSDBMMainWindow->setObjectName(QStringLiteral("ATCCSDBMMainWindow"));
        ATCCSDBMMainWindow->resize(400, 300);

        retranslateUi(ATCCSDBMMainWindow);

        QMetaObject::connectSlotsByName(ATCCSDBMMainWindow);
    } // setupUi

    void retranslateUi(QWidget *ATCCSDBMMainWindow)
    {
        ATCCSDBMMainWindow->setWindowTitle(QApplication::translate("ATCCSDBMMainWindow", "ATCCSDBMMainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ATCCSDBMMainWindow: public Ui_ATCCSDBMMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCCSDBMMAINWINDOW_H
