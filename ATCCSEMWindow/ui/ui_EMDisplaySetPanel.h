/********************************************************************************
** Form generated from reading UI file 'EMDisplaySetPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMDISPLAYSETPANEL_H
#define UI_EMDISPLAYSETPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EMDisplaySetPanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *_nameTag;
    QPushButton *_selectAll;
    QPushButton *_selectNone;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QCheckBox *_cbASC;
    QCheckBox *_cbWS;
    QCheckBox *_cbCS;
    QCheckBox *_cbSQM;
    QCheckBox *_cbDUST;
    QCheckBox *_cbDIMM;
    QFrame *line;

    void setupUi(QWidget *EMDisplaySetPanel)
    {
        if (EMDisplaySetPanel->objectName().isEmpty())
            EMDisplaySetPanel->setObjectName(QStringLiteral("EMDisplaySetPanel"));
        EMDisplaySetPanel->resize(400, 300);
        verticalLayout = new QVBoxLayout(EMDisplaySetPanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        _nameTag = new QLabel(EMDisplaySetPanel);
        _nameTag->setObjectName(QStringLiteral("_nameTag"));

        horizontalLayout->addWidget(_nameTag);

        _selectAll = new QPushButton(EMDisplaySetPanel);
        _selectAll->setObjectName(QStringLiteral("_selectAll"));

        horizontalLayout->addWidget(_selectAll);

        _selectNone = new QPushButton(EMDisplaySetPanel);
        _selectNone->setObjectName(QStringLiteral("_selectNone"));

        horizontalLayout->addWidget(_selectNone);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        _cbASC = new QCheckBox(EMDisplaySetPanel);
        _cbASC->setObjectName(QStringLiteral("_cbASC"));

        gridLayout->addWidget(_cbASC, 0, 0, 1, 1);

        _cbWS = new QCheckBox(EMDisplaySetPanel);
        _cbWS->setObjectName(QStringLiteral("_cbWS"));

        gridLayout->addWidget(_cbWS, 0, 1, 1, 1);

        _cbCS = new QCheckBox(EMDisplaySetPanel);
        _cbCS->setObjectName(QStringLiteral("_cbCS"));

        gridLayout->addWidget(_cbCS, 0, 2, 1, 1);

        _cbSQM = new QCheckBox(EMDisplaySetPanel);
        _cbSQM->setObjectName(QStringLiteral("_cbSQM"));

        gridLayout->addWidget(_cbSQM, 1, 0, 1, 1);

        _cbDUST = new QCheckBox(EMDisplaySetPanel);
        _cbDUST->setObjectName(QStringLiteral("_cbDUST"));

        gridLayout->addWidget(_cbDUST, 1, 1, 1, 1);

        _cbDIMM = new QCheckBox(EMDisplaySetPanel);
        _cbDIMM->setObjectName(QStringLiteral("_cbDIMM"));

        gridLayout->addWidget(_cbDIMM, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line = new QFrame(EMDisplaySetPanel);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(EMDisplaySetPanel);

        QMetaObject::connectSlotsByName(EMDisplaySetPanel);
    } // setupUi

    void retranslateUi(QWidget *EMDisplaySetPanel)
    {
        EMDisplaySetPanel->setWindowTitle(QApplication::translate("EMDisplaySetPanel", "EMDisplaySetPanel", Q_NULLPTR));
        _nameTag->setText(QApplication::translate("EMDisplaySetPanel", "Display Setting", Q_NULLPTR));
        _selectAll->setText(QApplication::translate("EMDisplaySetPanel", "selectAll", Q_NULLPTR));
        _selectNone->setText(QApplication::translate("EMDisplaySetPanel", "selectNone", Q_NULLPTR));
        _cbASC->setText(QApplication::translate("EMDisplaySetPanel", "ASC", Q_NULLPTR));
        _cbWS->setText(QApplication::translate("EMDisplaySetPanel", "WS", Q_NULLPTR));
        _cbCS->setText(QApplication::translate("EMDisplaySetPanel", "CS", Q_NULLPTR));
        _cbSQM->setText(QApplication::translate("EMDisplaySetPanel", "SQM", Q_NULLPTR));
        _cbDUST->setText(QApplication::translate("EMDisplaySetPanel", "DUST", Q_NULLPTR));
        _cbDIMM->setText(QApplication::translate("EMDisplaySetPanel", "DIMM", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EMDisplaySetPanel: public Ui_EMDisplaySetPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMDISPLAYSETPANEL_H
