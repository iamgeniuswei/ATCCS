/********************************************************************************
** Form generated from reading UI file 'DBMPublicTablePanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMPUBLICTABLEPANEL_H
#define UI_DBMPUBLICTABLEPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBMPublicTablePanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *_publicTableTag;
    QPushButton *_btnSelectAll;
    QPushButton *_btnSelectNone;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *_cbUserTable;
    QCheckBox *_cbATTable;
    QCheckBox *_cbDeviceTable;
    QCheckBox *_cbEMETable;
    QCheckBox *_cbATUtilizationTable;
    QCheckBox *_cbATUtilizationLogTable;
    QFrame *line;

    void setupUi(QWidget *DBMPublicTablePanel)
    {
        if (DBMPublicTablePanel->objectName().isEmpty())
            DBMPublicTablePanel->setObjectName(QStringLiteral("DBMPublicTablePanel"));
        DBMPublicTablePanel->resize(889, 300);
        verticalLayout = new QVBoxLayout(DBMPublicTablePanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        _publicTableTag = new QLabel(DBMPublicTablePanel);
        _publicTableTag->setObjectName(QStringLiteral("_publicTableTag"));
        _publicTableTag->setScaledContents(true);

        horizontalLayout->addWidget(_publicTableTag);

        _btnSelectAll = new QPushButton(DBMPublicTablePanel);
        _btnSelectAll->setObjectName(QStringLiteral("_btnSelectAll"));

        horizontalLayout->addWidget(_btnSelectAll);

        _btnSelectNone = new QPushButton(DBMPublicTablePanel);
        _btnSelectNone->setObjectName(QStringLiteral("_btnSelectNone"));

        horizontalLayout->addWidget(_btnSelectNone);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        _cbUserTable = new QCheckBox(DBMPublicTablePanel);
        _cbUserTable->setObjectName(QStringLiteral("_cbUserTable"));

        horizontalLayout_2->addWidget(_cbUserTable);

        _cbATTable = new QCheckBox(DBMPublicTablePanel);
        _cbATTable->setObjectName(QStringLiteral("_cbATTable"));

        horizontalLayout_2->addWidget(_cbATTable);

        _cbDeviceTable = new QCheckBox(DBMPublicTablePanel);
        _cbDeviceTable->setObjectName(QStringLiteral("_cbDeviceTable"));

        horizontalLayout_2->addWidget(_cbDeviceTable);

        _cbEMETable = new QCheckBox(DBMPublicTablePanel);
        _cbEMETable->setObjectName(QStringLiteral("_cbEMETable"));

        horizontalLayout_2->addWidget(_cbEMETable);

        _cbATUtilizationTable = new QCheckBox(DBMPublicTablePanel);
        _cbATUtilizationTable->setObjectName(QStringLiteral("_cbATUtilizationTable"));

        horizontalLayout_2->addWidget(_cbATUtilizationTable);

        _cbATUtilizationLogTable = new QCheckBox(DBMPublicTablePanel);
        _cbATUtilizationLogTable->setObjectName(QStringLiteral("_cbATUtilizationLogTable"));

        horizontalLayout_2->addWidget(_cbATUtilizationLogTable);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(DBMPublicTablePanel);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(DBMPublicTablePanel);

        QMetaObject::connectSlotsByName(DBMPublicTablePanel);
    } // setupUi

    void retranslateUi(QWidget *DBMPublicTablePanel)
    {
        DBMPublicTablePanel->setWindowTitle(QApplication::translate("DBMPublicTablePanel", "DBMPublicTablePanel", Q_NULLPTR));
        _publicTableTag->setText(QApplication::translate("DBMPublicTablePanel", "Initialize Public Table", Q_NULLPTR));
        _btnSelectAll->setText(QApplication::translate("DBMPublicTablePanel", "SelectAll", Q_NULLPTR));
        _btnSelectNone->setText(QApplication::translate("DBMPublicTablePanel", "SelectNone", Q_NULLPTR));
        _cbUserTable->setText(QApplication::translate("DBMPublicTablePanel", "user", Q_NULLPTR));
        _cbATTable->setText(QApplication::translate("DBMPublicTablePanel", "at", Q_NULLPTR));
        _cbDeviceTable->setText(QApplication::translate("DBMPublicTablePanel", "device", Q_NULLPTR));
        _cbEMETable->setText(QApplication::translate("DBMPublicTablePanel", "eme", Q_NULLPTR));
        _cbATUtilizationTable->setText(QApplication::translate("DBMPublicTablePanel", "atUtilization", Q_NULLPTR));
        _cbATUtilizationLogTable->setText(QApplication::translate("DBMPublicTablePanel", "atUtilizationLog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DBMPublicTablePanel: public Ui_DBMPublicTablePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMPUBLICTABLEPANEL_H
