/********************************************************************************
** Form generated from reading UI file 'EMWSDataPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMWSDATAPANEL_H
#define UI_EMWSDATAPANEL_H

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

class Ui_EMWSDataPanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *_emName;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QFormLayout *formLayout;
    QLabel *_temperatureTag;
    QLabel *_temperatureValue;
    QLabel *_humidityTag;
    QLabel *_humidityValue;
    QLabel *_dewpointTag;
    QLabel *_dewpointValue;
    QLabel *_pressureTag;
    QLabel *_pressureValue;
    QLabel *_windspeedTag;
    QLabel *_windspeedValue;
    QLabel *_windspeed2Tag;
    QLabel *_windspeed2Value;
    QLabel *_windspeed10Tag;
    QLabel *_windspeed10Value;
    QLabel *_winddirectionTag;
    QLabel *_winddirectionValue;
    QLabel *_rainfallTag;
    QLabel *_rainfallValue;
    QLabel *_radiationTag;
    QLabel *_radiationValue;
    QLabel *_illuminationTag;
    QLabel *_illuminationValue;
    QSpacerItem *horizontalSpacer_4;
    QLabel *_timeTag;

    void setupUi(QWidget *EMWSDataPanel)
    {
        if (EMWSDataPanel->objectName().isEmpty())
            EMWSDataPanel->setObjectName(QStringLiteral("EMWSDataPanel"));
        EMWSDataPanel->resize(495, 417);
        verticalLayout = new QVBoxLayout(EMWSDataPanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _emName = new QLabel(EMWSDataPanel);
        _emName->setObjectName(QStringLiteral("_emName"));

        horizontalLayout->addWidget(_emName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        _temperatureTag = new QLabel(EMWSDataPanel);
        _temperatureTag->setObjectName(QStringLiteral("_temperatureTag"));

        formLayout->setWidget(0, QFormLayout::LabelRole, _temperatureTag);

        _temperatureValue = new QLabel(EMWSDataPanel);
        _temperatureValue->setObjectName(QStringLiteral("_temperatureValue"));

        formLayout->setWidget(0, QFormLayout::FieldRole, _temperatureValue);

        _humidityTag = new QLabel(EMWSDataPanel);
        _humidityTag->setObjectName(QStringLiteral("_humidityTag"));

        formLayout->setWidget(1, QFormLayout::LabelRole, _humidityTag);

        _humidityValue = new QLabel(EMWSDataPanel);
        _humidityValue->setObjectName(QStringLiteral("_humidityValue"));

        formLayout->setWidget(1, QFormLayout::FieldRole, _humidityValue);

        _dewpointTag = new QLabel(EMWSDataPanel);
        _dewpointTag->setObjectName(QStringLiteral("_dewpointTag"));

        formLayout->setWidget(2, QFormLayout::LabelRole, _dewpointTag);

        _dewpointValue = new QLabel(EMWSDataPanel);
        _dewpointValue->setObjectName(QStringLiteral("_dewpointValue"));

        formLayout->setWidget(2, QFormLayout::FieldRole, _dewpointValue);

        _pressureTag = new QLabel(EMWSDataPanel);
        _pressureTag->setObjectName(QStringLiteral("_pressureTag"));

        formLayout->setWidget(3, QFormLayout::LabelRole, _pressureTag);

        _pressureValue = new QLabel(EMWSDataPanel);
        _pressureValue->setObjectName(QStringLiteral("_pressureValue"));

        formLayout->setWidget(3, QFormLayout::FieldRole, _pressureValue);

        _windspeedTag = new QLabel(EMWSDataPanel);
        _windspeedTag->setObjectName(QStringLiteral("_windspeedTag"));

        formLayout->setWidget(4, QFormLayout::LabelRole, _windspeedTag);

        _windspeedValue = new QLabel(EMWSDataPanel);
        _windspeedValue->setObjectName(QStringLiteral("_windspeedValue"));

        formLayout->setWidget(4, QFormLayout::FieldRole, _windspeedValue);

        _windspeed2Tag = new QLabel(EMWSDataPanel);
        _windspeed2Tag->setObjectName(QStringLiteral("_windspeed2Tag"));

        formLayout->setWidget(5, QFormLayout::LabelRole, _windspeed2Tag);

        _windspeed2Value = new QLabel(EMWSDataPanel);
        _windspeed2Value->setObjectName(QStringLiteral("_windspeed2Value"));

        formLayout->setWidget(5, QFormLayout::FieldRole, _windspeed2Value);

        _windspeed10Tag = new QLabel(EMWSDataPanel);
        _windspeed10Tag->setObjectName(QStringLiteral("_windspeed10Tag"));

        formLayout->setWidget(6, QFormLayout::LabelRole, _windspeed10Tag);

        _windspeed10Value = new QLabel(EMWSDataPanel);
        _windspeed10Value->setObjectName(QStringLiteral("_windspeed10Value"));

        formLayout->setWidget(6, QFormLayout::FieldRole, _windspeed10Value);

        _winddirectionTag = new QLabel(EMWSDataPanel);
        _winddirectionTag->setObjectName(QStringLiteral("_winddirectionTag"));

        formLayout->setWidget(7, QFormLayout::LabelRole, _winddirectionTag);

        _winddirectionValue = new QLabel(EMWSDataPanel);
        _winddirectionValue->setObjectName(QStringLiteral("_winddirectionValue"));

        formLayout->setWidget(7, QFormLayout::FieldRole, _winddirectionValue);

        _rainfallTag = new QLabel(EMWSDataPanel);
        _rainfallTag->setObjectName(QStringLiteral("_rainfallTag"));

        formLayout->setWidget(8, QFormLayout::LabelRole, _rainfallTag);

        _rainfallValue = new QLabel(EMWSDataPanel);
        _rainfallValue->setObjectName(QStringLiteral("_rainfallValue"));

        formLayout->setWidget(8, QFormLayout::FieldRole, _rainfallValue);

        _radiationTag = new QLabel(EMWSDataPanel);
        _radiationTag->setObjectName(QStringLiteral("_radiationTag"));

        formLayout->setWidget(9, QFormLayout::LabelRole, _radiationTag);

        _radiationValue = new QLabel(EMWSDataPanel);
        _radiationValue->setObjectName(QStringLiteral("_radiationValue"));

        formLayout->setWidget(9, QFormLayout::FieldRole, _radiationValue);

        _illuminationTag = new QLabel(EMWSDataPanel);
        _illuminationTag->setObjectName(QStringLiteral("_illuminationTag"));

        formLayout->setWidget(10, QFormLayout::LabelRole, _illuminationTag);

        _illuminationValue = new QLabel(EMWSDataPanel);
        _illuminationValue->setObjectName(QStringLiteral("_illuminationValue"));

        formLayout->setWidget(10, QFormLayout::FieldRole, _illuminationValue);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        _timeTag = new QLabel(EMWSDataPanel);
        _timeTag->setObjectName(QStringLiteral("_timeTag"));
        _timeTag->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(_timeTag);


        retranslateUi(EMWSDataPanel);

        QMetaObject::connectSlotsByName(EMWSDataPanel);
    } // setupUi

    void retranslateUi(QWidget *EMWSDataPanel)
    {
        EMWSDataPanel->setWindowTitle(QApplication::translate("EMWSDataPanel", "EMWSDataPanel", Q_NULLPTR));
        _emName->setText(QApplication::translate("EMWSDataPanel", "WS", Q_NULLPTR));
        _temperatureTag->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _temperatureValue->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _humidityTag->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _humidityValue->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _dewpointTag->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _dewpointValue->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _pressureTag->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _pressureValue->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _windspeedTag->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _windspeedValue->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _windspeed2Tag->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _windspeed2Value->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _windspeed10Tag->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _windspeed10Value->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _winddirectionTag->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _winddirectionValue->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _rainfallTag->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _rainfallValue->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _radiationTag->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _radiationValue->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _illuminationTag->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _illuminationValue->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
        _timeTag->setText(QApplication::translate("EMWSDataPanel", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EMWSDataPanel: public Ui_EMWSDataPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMWSDATAPANEL_H
