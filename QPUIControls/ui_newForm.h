/********************************************************************************
** Form generated from reading UI file 'newForm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFORM_H
#define UI_NEWFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newForm
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *newForm)
    {
        if (newForm->objectName().isEmpty())
            newForm->setObjectName(QStringLiteral("newForm"));
        newForm->resize(400, 300);
        pushButton = new QPushButton(newForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 100, 121, 121));
        pushButton->setStyleSheet(QStringLiteral(""));

        retranslateUi(newForm);

        QMetaObject::connectSlotsByName(newForm);
    } // setupUi

    void retranslateUi(QWidget *newForm)
    {
        newForm->setWindowTitle(QApplication::translate("newForm", "newForm", 0));
        pushButton->setText(QApplication::translate("newForm", "\345\220\257\345\212\250", 0));
    } // retranslateUi

};

namespace Ui {
    class newForm: public Ui_newForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFORM_H
