/********************************************************************************
** Form generated from reading UI file 'DBMWOutPancel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMWOUTPANCEL_H
#define UI_DBMWOUTPANCEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBMWOutPancel
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;

    void setupUi(QWidget *DBMWOutPancel)
    {
        if (DBMWOutPancel->objectName().isEmpty())
            DBMWOutPancel->setObjectName(QStringLiteral("DBMWOutPancel"));
        DBMWOutPancel->resize(892, 449);
        verticalLayout = new QVBoxLayout(DBMWOutPancel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(DBMWOutPancel);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_2->addWidget(textEdit);


        verticalLayout->addWidget(groupBox);


        retranslateUi(DBMWOutPancel);

        QMetaObject::connectSlotsByName(DBMWOutPancel);
    } // setupUi

    void retranslateUi(QWidget *DBMWOutPancel)
    {
        DBMWOutPancel->setWindowTitle(QApplication::translate("DBMWOutPancel", "DBMWOutPancel", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DBMWOutPancel", "Output", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DBMWOutPanel: public Ui_DBMWOutPancel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMWOUTPANCEL_H
