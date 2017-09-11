/********************************************************************************
** Form generated from reading UI file 'EMCSDataPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMCSDATAPANEL_H
#define UI_EMCSDATAPANEL_H

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

class Ui_EMCSDataPanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *_emNameTag;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QFormLayout *formLayout;
    QLabel *_relskyTag;
    QLabel *_relskyValue;
    QLabel *_ambientTag;
    QLabel *_ambientValue;
    QLabel *_sensorTag;
    QLabel *_sensorValue;
    QLabel *_rainTag;
    QLabel *_rainValue;
    QLabel *_rainthreshValue;
    QLabel *_windTag;
    QLabel *_windValue;
    QLabel *_windunitTag;
    QLabel *_windunitValue;
    QLabel *_humidityTag;
    QLabel *_humidityValue;
    QLabel *_dewpointTag;
    QLabel *_dewpointValue;
    QLabel *_daylightTag;
    QLabel *_daylightValue;
    QLabel *_rainthreshTag;
    QSpacerItem *horizontalSpacer_4;
    QLabel *_timeTag;

    void setupUi(QWidget *EMCSDataPanel)
    {
        if (EMCSDataPanel->objectName().isEmpty())
            EMCSDataPanel->setObjectName(QStringLiteral("EMCSDataPanel"));
        EMCSDataPanel->resize(400, 300);
        verticalLayout = new QVBoxLayout(EMCSDataPanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _emNameTag = new QLabel(EMCSDataPanel);
        _emNameTag->setObjectName(QStringLiteral("_emNameTag"));

        horizontalLayout->addWidget(_emNameTag);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        _relskyTag = new QLabel(EMCSDataPanel);
        _relskyTag->setObjectName(QStringLiteral("_relskyTag"));

        formLayout->setWidget(0, QFormLayout::LabelRole, _relskyTag);

        _relskyValue = new QLabel(EMCSDataPanel);
        _relskyValue->setObjectName(QStringLiteral("_relskyValue"));

        formLayout->setWidget(0, QFormLayout::FieldRole, _relskyValue);

        _ambientTag = new QLabel(EMCSDataPanel);
        _ambientTag->setObjectName(QStringLiteral("_ambientTag"));

        formLayout->setWidget(1, QFormLayout::LabelRole, _ambientTag);

        _ambientValue = new QLabel(EMCSDataPanel);
        _ambientValue->setObjectName(QStringLiteral("_ambientValue"));

        formLayout->setWidget(1, QFormLayout::FieldRole, _ambientValue);

        _sensorTag = new QLabel(EMCSDataPanel);
        _sensorTag->setObjectName(QStringLiteral("_sensorTag"));

        formLayout->setWidget(2, QFormLayout::LabelRole, _sensorTag);

        _sensorValue = new QLabel(EMCSDataPanel);
        _sensorValue->setObjectName(QStringLiteral("_sensorValue"));

        formLayout->setWidget(2, QFormLayout::FieldRole, _sensorValue);

        _rainTag = new QLabel(EMCSDataPanel);
        _rainTag->setObjectName(QStringLiteral("_rainTag"));

        formLayout->setWidget(3, QFormLayout::LabelRole, _rainTag);

        _rainValue = new QLabel(EMCSDataPanel);
        _rainValue->setObjectName(QStringLiteral("_rainValue"));

        formLayout->setWidget(3, QFormLayout::FieldRole, _rainValue);

        _rainthreshValue = new QLabel(EMCSDataPanel);
        _rainthreshValue->setObjectName(QStringLiteral("_rainthreshValue"));

        formLayout->setWidget(4, QFormLayout::FieldRole, _rainthreshValue);

        _windTag = new QLabel(EMCSDataPanel);
        _windTag->setObjectName(QStringLiteral("_windTag"));

        formLayout->setWidget(5, QFormLayout::LabelRole, _windTag);

        _windValue = new QLabel(EMCSDataPanel);
        _windValue->setObjectName(QStringLiteral("_windValue"));

        formLayout->setWidget(5, QFormLayout::FieldRole, _windValue);

        _windunitTag = new QLabel(EMCSDataPanel);
        _windunitTag->setObjectName(QStringLiteral("_windunitTag"));

        formLayout->setWidget(6, QFormLayout::LabelRole, _windunitTag);

        _windunitValue = new QLabel(EMCSDataPanel);
        _windunitValue->setObjectName(QStringLiteral("_windunitValue"));

        formLayout->setWidget(6, QFormLayout::FieldRole, _windunitValue);

        _humidityTag = new QLabel(EMCSDataPanel);
        _humidityTag->setObjectName(QStringLiteral("_humidityTag"));

        formLayout->setWidget(7, QFormLayout::LabelRole, _humidityTag);

        _humidityValue = new QLabel(EMCSDataPanel);
        _humidityValue->setObjectName(QStringLiteral("_humidityValue"));

        formLayout->setWidget(7, QFormLayout::FieldRole, _humidityValue);

        _dewpointTag = new QLabel(EMCSDataPanel);
        _dewpointTag->setObjectName(QStringLiteral("_dewpointTag"));

        formLayout->setWidget(8, QFormLayout::LabelRole, _dewpointTag);

        _dewpointValue = new QLabel(EMCSDataPanel);
        _dewpointValue->setObjectName(QStringLiteral("_dewpointValue"));

        formLayout->setWidget(8, QFormLayout::FieldRole, _dewpointValue);

        _daylightTag = new QLabel(EMCSDataPanel);
        _daylightTag->setObjectName(QStringLiteral("_daylightTag"));

        formLayout->setWidget(9, QFormLayout::LabelRole, _daylightTag);

        _daylightValue = new QLabel(EMCSDataPanel);
        _daylightValue->setObjectName(QStringLiteral("_daylightValue"));

        formLayout->setWidget(9, QFormLayout::FieldRole, _daylightValue);

        _rainthreshTag = new QLabel(EMCSDataPanel);
        _rainthreshTag->setObjectName(QStringLiteral("_rainthreshTag"));

        formLayout->setWidget(4, QFormLayout::LabelRole, _rainthreshTag);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        _timeTag = new QLabel(EMCSDataPanel);
        _timeTag->setObjectName(QStringLiteral("_timeTag"));
        _timeTag->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(_timeTag);

        _timeTag->raise();
        _rainthreshTag->raise();

        retranslateUi(EMCSDataPanel);

        QMetaObject::connectSlotsByName(EMCSDataPanel);
    } // setupUi

    void retranslateUi(QWidget *EMCSDataPanel)
    {
        EMCSDataPanel->setWindowTitle(QApplication::translate("EMCSDataPanel", "EMCSDataPanel", Q_NULLPTR));
        _emNameTag->setText(QApplication::translate("EMCSDataPanel", "CS", Q_NULLPTR));
        _relskyTag->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _relskyValue->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _ambientTag->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _ambientValue->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _sensorTag->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _sensorValue->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _rainTag->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _rainValue->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _rainthreshValue->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _windTag->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _windValue->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _windunitTag->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _windunitValue->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _humidityTag->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _humidityValue->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _dewpointTag->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _dewpointValue->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _daylightTag->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _daylightValue->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _rainthreshTag->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
        _timeTag->setText(QApplication::translate("EMCSDataPanel", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EMCSDataPanel: public Ui_EMCSDataPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMCSDATAPANEL_H
