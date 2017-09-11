/********************************************************************************
** Form generated from reading UI file 'ATCDevicePanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCDEVICEPANEL_H
#define UI_ATCDEVICEPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCDevicePanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *_deviceName;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QFormLayout *formLayout;
    QLabel *_curStatusTag;
    QLabel *_curStatusValue;
    QLabel *_lastStatusTag;
    QLabel *_lastStatusValue;
    QLabel *_errorTag;
    QLabel *_errorValue;
    QLabel *_warningTag;
    QLabel *_warningValue;
    QLabel *_instructionTag;
    QLabel *_instructionValue;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *ATCDevicePanel)
    {
        if (ATCDevicePanel->objectName().isEmpty())
            ATCDevicePanel->setObjectName(QStringLiteral("ATCDevicePanel"));
        ATCDevicePanel->resize(400, 300);
        ATCDevicePanel->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(ATCDevicePanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _deviceName = new QLabel(ATCDevicePanel);
        _deviceName->setObjectName(QStringLiteral("_deviceName"));

        horizontalLayout->addWidget(_deviceName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        _curStatusTag = new QLabel(ATCDevicePanel);
        _curStatusTag->setObjectName(QStringLiteral("_curStatusTag"));

        formLayout->setWidget(0, QFormLayout::LabelRole, _curStatusTag);

        _curStatusValue = new QLabel(ATCDevicePanel);
        _curStatusValue->setObjectName(QStringLiteral("_curStatusValue"));

        formLayout->setWidget(0, QFormLayout::FieldRole, _curStatusValue);

        _lastStatusTag = new QLabel(ATCDevicePanel);
        _lastStatusTag->setObjectName(QStringLiteral("_lastStatusTag"));

        formLayout->setWidget(1, QFormLayout::LabelRole, _lastStatusTag);

        _lastStatusValue = new QLabel(ATCDevicePanel);
        _lastStatusValue->setObjectName(QStringLiteral("_lastStatusValue"));

        formLayout->setWidget(1, QFormLayout::FieldRole, _lastStatusValue);

        _errorTag = new QLabel(ATCDevicePanel);
        _errorTag->setObjectName(QStringLiteral("_errorTag"));

        formLayout->setWidget(2, QFormLayout::LabelRole, _errorTag);

        _errorValue = new QLabel(ATCDevicePanel);
        _errorValue->setObjectName(QStringLiteral("_errorValue"));

        formLayout->setWidget(2, QFormLayout::FieldRole, _errorValue);

        _warningTag = new QLabel(ATCDevicePanel);
        _warningTag->setObjectName(QStringLiteral("_warningTag"));

        formLayout->setWidget(3, QFormLayout::LabelRole, _warningTag);

        _warningValue = new QLabel(ATCDevicePanel);
        _warningValue->setObjectName(QStringLiteral("_warningValue"));

        formLayout->setWidget(3, QFormLayout::FieldRole, _warningValue);

        _instructionTag = new QLabel(ATCDevicePanel);
        _instructionTag->setObjectName(QStringLiteral("_instructionTag"));

        formLayout->setWidget(4, QFormLayout::LabelRole, _instructionTag);

        _instructionValue = new QLabel(ATCDevicePanel);
        _instructionValue->setObjectName(QStringLiteral("_instructionValue"));

        formLayout->setWidget(4, QFormLayout::FieldRole, _instructionValue);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ATCDevicePanel);

        QMetaObject::connectSlotsByName(ATCDevicePanel);
    } // setupUi

    void retranslateUi(QWidget *ATCDevicePanel)
    {
        ATCDevicePanel->setWindowTitle(QApplication::translate("ATCDevicePanel", "ATCDevicePanel", Q_NULLPTR));
        _deviceName->setText(QApplication::translate("ATCDevicePanel", "TextLabel", Q_NULLPTR));
        _curStatusTag->setText(QApplication::translate("ATCDevicePanel", "CurStatus:", Q_NULLPTR));
        _curStatusValue->setText(QApplication::translate("ATCDevicePanel", "NULL", Q_NULLPTR));
        _lastStatusTag->setText(QApplication::translate("ATCDevicePanel", "LastStatus:", Q_NULLPTR));
        _lastStatusValue->setText(QApplication::translate("ATCDevicePanel", "NULL", Q_NULLPTR));
        _errorTag->setText(QApplication::translate("ATCDevicePanel", "Error:", Q_NULLPTR));
        _errorValue->setText(QApplication::translate("ATCDevicePanel", "NULL", Q_NULLPTR));
        _warningTag->setText(QApplication::translate("ATCDevicePanel", "Warning:", Q_NULLPTR));
        _warningValue->setText(QApplication::translate("ATCDevicePanel", "NULL", Q_NULLPTR));
        _instructionTag->setText(QApplication::translate("ATCDevicePanel", "Instruction:", Q_NULLPTR));
        _instructionValue->setText(QApplication::translate("ATCDevicePanel", "NULL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ATCDevicePanel: public Ui_ATCDevicePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCDEVICEPANEL_H
