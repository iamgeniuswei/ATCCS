/********************************************************************************
** Form generated from reading UI file 'newForm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
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
    QPushButton *pushButton_2;

    void setupUi(QWidget *newForm)
    {
        if (newForm->objectName().isEmpty())
            newForm->setObjectName(QStringLiteral("newForm"));
        newForm->resize(400, 300);
        pushButton = new QPushButton(newForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 120, 80, 24));
        pushButton_2 = new QPushButton(newForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 190, 80, 24));

        retranslateUi(newForm);

        QMetaObject::connectSlotsByName(newForm);
    } // setupUi

    void retranslateUi(QWidget *newForm)
    {
        newForm->setWindowTitle(QApplication::translate("newForm", "newForm", Q_NULLPTR));
        pushButton->setText(QApplication::translate("newForm", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("newForm", "Test", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class newForm: public Ui_newForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFORM_H
