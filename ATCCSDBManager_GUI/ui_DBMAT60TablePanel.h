/********************************************************************************
** Form generated from reading UI file 'DBMAT60TablePanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMAT60TABLEPANEL_H
#define UI_DBMAT60TABLEPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBMAT60TablePanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *_btnSelectAll;
    QPushButton *_btnSelectNone;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QCheckBox *_cbGimbal;
    QCheckBox *_cbCCD;
    QCheckBox *_cbFocus;
    QCheckBox *_cbFilter;
    QCheckBox *_cbSlaveDome;
    QCheckBox *_cbPlan;
    QCheckBox *_cbInstruction;

    void setupUi(QWidget *DBMAT60TablePanel)
    {
        if (DBMAT60TablePanel->objectName().isEmpty())
            DBMAT60TablePanel->setObjectName(QStringLiteral("DBMAT60TablePanel"));
        DBMAT60TablePanel->resize(782, 300);
        verticalLayout = new QVBoxLayout(DBMAT60TablePanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(DBMAT60TablePanel);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        _btnSelectAll = new QPushButton(DBMAT60TablePanel);
        _btnSelectAll->setObjectName(QStringLiteral("_btnSelectAll"));

        horizontalLayout_2->addWidget(_btnSelectAll);

        _btnSelectNone = new QPushButton(DBMAT60TablePanel);
        _btnSelectNone->setObjectName(QStringLiteral("_btnSelectNone"));

        horizontalLayout_2->addWidget(_btnSelectNone);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        _cbGimbal = new QCheckBox(DBMAT60TablePanel);
        _cbGimbal->setObjectName(QStringLiteral("_cbGimbal"));

        gridLayout->addWidget(_cbGimbal, 0, 0, 1, 1);

        _cbCCD = new QCheckBox(DBMAT60TablePanel);
        _cbCCD->setObjectName(QStringLiteral("_cbCCD"));

        gridLayout->addWidget(_cbCCD, 0, 1, 1, 1);

        _cbFocus = new QCheckBox(DBMAT60TablePanel);
        _cbFocus->setObjectName(QStringLiteral("_cbFocus"));

        gridLayout->addWidget(_cbFocus, 0, 2, 1, 1);

        _cbFilter = new QCheckBox(DBMAT60TablePanel);
        _cbFilter->setObjectName(QStringLiteral("_cbFilter"));

        gridLayout->addWidget(_cbFilter, 0, 3, 1, 1);

        _cbSlaveDome = new QCheckBox(DBMAT60TablePanel);
        _cbSlaveDome->setObjectName(QStringLiteral("_cbSlaveDome"));

        gridLayout->addWidget(_cbSlaveDome, 0, 4, 1, 1);

        _cbPlan = new QCheckBox(DBMAT60TablePanel);
        _cbPlan->setObjectName(QStringLiteral("_cbPlan"));

        gridLayout->addWidget(_cbPlan, 1, 0, 1, 1);

        _cbInstruction = new QCheckBox(DBMAT60TablePanel);
        _cbInstruction->setObjectName(QStringLiteral("_cbInstruction"));

        gridLayout->addWidget(_cbInstruction, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(DBMAT60TablePanel);

        QMetaObject::connectSlotsByName(DBMAT60TablePanel);
    } // setupUi

    void retranslateUi(QWidget *DBMAT60TablePanel)
    {
        DBMAT60TablePanel->setWindowTitle(QApplication::translate("DBMAT60TablePanel", "DBMAT60TablePanel", Q_NULLPTR));
        label->setText(QApplication::translate("DBMAT60TablePanel", "Initialize AT60 Table", Q_NULLPTR));
        _btnSelectAll->setText(QApplication::translate("DBMAT60TablePanel", "SelectAll", Q_NULLPTR));
        _btnSelectNone->setText(QApplication::translate("DBMAT60TablePanel", "SelectNone", Q_NULLPTR));
        _cbGimbal->setText(QApplication::translate("DBMAT60TablePanel", "Gimbal", Q_NULLPTR));
        _cbCCD->setText(QApplication::translate("DBMAT60TablePanel", "CCD", Q_NULLPTR));
        _cbFocus->setText(QApplication::translate("DBMAT60TablePanel", "Focus", Q_NULLPTR));
        _cbFilter->setText(QApplication::translate("DBMAT60TablePanel", "Filter", Q_NULLPTR));
        _cbSlaveDome->setText(QApplication::translate("DBMAT60TablePanel", "SlaveDome", Q_NULLPTR));
        _cbPlan->setText(QApplication::translate("DBMAT60TablePanel", "Plan", Q_NULLPTR));
        _cbInstruction->setText(QApplication::translate("DBMAT60TablePanel", "Instruction", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DBMAT60TablePanel: public Ui_DBMAT60TablePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMAT60TABLEPANEL_H
