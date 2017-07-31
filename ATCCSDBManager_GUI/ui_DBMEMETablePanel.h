/********************************************************************************
** Form generated from reading UI file 'DBMEMETablePanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMEMETABLEPANEL_H
#define UI_DBMEMETABLEPANEL_H

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

class Ui_DMBEMETablePanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *_btnSelectAll;
    QPushButton *_btnSelectNone;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *_cbASC;
    QCheckBox *_cbWS;
    QCheckBox *_cbCS;
    QCheckBox *_cbDust;
    QCheckBox *_cbSQM;
    QCheckBox *_cbDIMM;
    QFrame *line;

    void setupUi(QWidget *DMBEMETablePanel)
    {
        if (DMBEMETablePanel->objectName().isEmpty())
            DMBEMETablePanel->setObjectName(QStringLiteral("DMBEMETablePanel"));
        DMBEMETablePanel->resize(777, 300);
        verticalLayout = new QVBoxLayout(DMBEMETablePanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DMBEMETablePanel);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        _btnSelectAll = new QPushButton(DMBEMETablePanel);
        _btnSelectAll->setObjectName(QStringLiteral("_btnSelectAll"));

        horizontalLayout->addWidget(_btnSelectAll);

        _btnSelectNone = new QPushButton(DMBEMETablePanel);
        _btnSelectNone->setObjectName(QStringLiteral("_btnSelectNone"));

        horizontalLayout->addWidget(_btnSelectNone);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        _cbASC = new QCheckBox(DMBEMETablePanel);
        _cbASC->setObjectName(QStringLiteral("_cbASC"));

        horizontalLayout_2->addWidget(_cbASC);

        _cbWS = new QCheckBox(DMBEMETablePanel);
        _cbWS->setObjectName(QStringLiteral("_cbWS"));

        horizontalLayout_2->addWidget(_cbWS);

        _cbCS = new QCheckBox(DMBEMETablePanel);
        _cbCS->setObjectName(QStringLiteral("_cbCS"));

        horizontalLayout_2->addWidget(_cbCS);

        _cbDust = new QCheckBox(DMBEMETablePanel);
        _cbDust->setObjectName(QStringLiteral("_cbDust"));

        horizontalLayout_2->addWidget(_cbDust);

        _cbSQM = new QCheckBox(DMBEMETablePanel);
        _cbSQM->setObjectName(QStringLiteral("_cbSQM"));

        horizontalLayout_2->addWidget(_cbSQM);

        _cbDIMM = new QCheckBox(DMBEMETablePanel);
        _cbDIMM->setObjectName(QStringLiteral("_cbDIMM"));

        horizontalLayout_2->addWidget(_cbDIMM);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(DMBEMETablePanel);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(DMBEMETablePanel);

        QMetaObject::connectSlotsByName(DMBEMETablePanel);
    } // setupUi

    void retranslateUi(QWidget *DMBEMETablePanel)
    {
        DMBEMETablePanel->setWindowTitle(QApplication::translate("DMBEMETablePanel", "DMBEMETablePanel", Q_NULLPTR));
        label->setText(QApplication::translate("DMBEMETablePanel", "Initialize EME Table", Q_NULLPTR));
        _btnSelectAll->setText(QApplication::translate("DMBEMETablePanel", "SelectAll", Q_NULLPTR));
        _btnSelectNone->setText(QApplication::translate("DMBEMETablePanel", "SelectNone", Q_NULLPTR));
        _cbASC->setText(QApplication::translate("DMBEMETablePanel", "ASC", Q_NULLPTR));
        _cbWS->setText(QApplication::translate("DMBEMETablePanel", "WS", Q_NULLPTR));
        _cbCS->setText(QApplication::translate("DMBEMETablePanel", "CS", Q_NULLPTR));
        _cbDust->setText(QApplication::translate("DMBEMETablePanel", "DUST", Q_NULLPTR));
        _cbSQM->setText(QApplication::translate("DMBEMETablePanel", "SQM", Q_NULLPTR));
        _cbDIMM->setText(QApplication::translate("DMBEMETablePanel", "DIMM", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DMBEMETablePanel: public Ui_DMBEMETablePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMEMETABLEPANEL_H
