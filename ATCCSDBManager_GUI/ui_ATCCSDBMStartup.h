/********************************************************************************
** Form generated from reading UI file 'ATCCSDBMStartup.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCCSDBMSTARTUP_H
#define UI_ATCCSDBMSTARTUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCCSDBMStartup
{
public:
    QLabel *label;

    void setupUi(QWidget *ATCCSDBMStartup)
    {
        if (ATCCSDBMStartup->objectName().isEmpty())
            ATCCSDBMStartup->setObjectName(QStringLiteral("ATCCSDBMStartup"));
        ATCCSDBMStartup->resize(400, 300);
        label = new QLabel(ATCCSDBMStartup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 70, 64, 16));

        retranslateUi(ATCCSDBMStartup);

        QMetaObject::connectSlotsByName(ATCCSDBMStartup);
    } // setupUi

    void retranslateUi(QWidget *ATCCSDBMStartup)
    {
        ATCCSDBMStartup->setWindowTitle(QApplication::translate("ATCCSDBMStartup", "ATCCSDBMStartup", Q_NULLPTR));
        label->setText(QApplication::translate("ATCCSDBMStartup", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ATCCSDBMStartup: public Ui_ATCCSDBMStartup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCCSDBMSTARTUP_H
