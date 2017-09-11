/********************************************************************************
** Form generated from reading UI file 'newForm1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFORM1_H
#define UI_NEWFORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_newForm1
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *newForm1)
    {
        if (newForm1->objectName().isEmpty())
            newForm1->setObjectName(QStringLiteral("newForm1"));
        newForm1->resize(400, 300);
        buttonBox = new QDialogButtonBox(newForm1);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(newForm1);
        QObject::connect(buttonBox, SIGNAL(accepted()), newForm1, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newForm1, SLOT(reject()));

        QMetaObject::connectSlotsByName(newForm1);
    } // setupUi

    void retranslateUi(QDialog *newForm1)
    {
        newForm1->setWindowTitle(QApplication::translate("newForm1", "newForm1", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class newForm1: public Ui_newForm1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFORM1_H
