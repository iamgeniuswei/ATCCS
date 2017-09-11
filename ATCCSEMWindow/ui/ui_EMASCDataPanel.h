/********************************************************************************
** Form generated from reading UI file 'EMASCDataPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMASCDATAPANEL_H
#define UI_EMASCDATAPANEL_H

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

class Ui_EMASCDataPanel
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
    QLabel *_shutterspeedTag;
    QLabel *_shutterSpeedValue;
    QLabel *_apertureTag;
    QLabel *_apertureValue;
    QLabel *_isoTag;
    QLabel *_isoValue;
    QLabel *_jpegTag;
    QLabel *_jpegValue;
    QLabel *_rawTag;
    QLabel *_rawValue;
    QLabel *_fitsTag;
    QLabel *_fitsValue;
    QSpacerItem *horizontalSpacer_4;
    QLabel *_timeTag;

    void setupUi(QWidget *EMASCDataPanel)
    {
        if (EMASCDataPanel->objectName().isEmpty())
            EMASCDataPanel->setObjectName(QStringLiteral("EMASCDataPanel"));
        EMASCDataPanel->resize(400, 300);
        verticalLayout = new QVBoxLayout(EMASCDataPanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _emNameTag = new QLabel(EMASCDataPanel);
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
        _shutterspeedTag = new QLabel(EMASCDataPanel);
        _shutterspeedTag->setObjectName(QStringLiteral("_shutterspeedTag"));
        _shutterspeedTag->setScaledContents(true);
        _shutterspeedTag->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, _shutterspeedTag);

        _shutterSpeedValue = new QLabel(EMASCDataPanel);
        _shutterSpeedValue->setObjectName(QStringLiteral("_shutterSpeedValue"));
        _shutterSpeedValue->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, _shutterSpeedValue);

        _apertureTag = new QLabel(EMASCDataPanel);
        _apertureTag->setObjectName(QStringLiteral("_apertureTag"));
        _apertureTag->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, _apertureTag);

        _apertureValue = new QLabel(EMASCDataPanel);
        _apertureValue->setObjectName(QStringLiteral("_apertureValue"));
        _apertureValue->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, _apertureValue);

        _isoTag = new QLabel(EMASCDataPanel);
        _isoTag->setObjectName(QStringLiteral("_isoTag"));

        formLayout->setWidget(2, QFormLayout::LabelRole, _isoTag);

        _isoValue = new QLabel(EMASCDataPanel);
        _isoValue->setObjectName(QStringLiteral("_isoValue"));
        _isoValue->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, _isoValue);

        _jpegTag = new QLabel(EMASCDataPanel);
        _jpegTag->setObjectName(QStringLiteral("_jpegTag"));

        formLayout->setWidget(3, QFormLayout::LabelRole, _jpegTag);

        _jpegValue = new QLabel(EMASCDataPanel);
        _jpegValue->setObjectName(QStringLiteral("_jpegValue"));
        _jpegValue->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, _jpegValue);

        _rawTag = new QLabel(EMASCDataPanel);
        _rawTag->setObjectName(QStringLiteral("_rawTag"));

        formLayout->setWidget(4, QFormLayout::LabelRole, _rawTag);

        _rawValue = new QLabel(EMASCDataPanel);
        _rawValue->setObjectName(QStringLiteral("_rawValue"));
        _rawValue->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, _rawValue);

        _fitsTag = new QLabel(EMASCDataPanel);
        _fitsTag->setObjectName(QStringLiteral("_fitsTag"));

        formLayout->setWidget(5, QFormLayout::LabelRole, _fitsTag);

        _fitsValue = new QLabel(EMASCDataPanel);
        _fitsValue->setObjectName(QStringLiteral("_fitsValue"));
        _fitsValue->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(5, QFormLayout::FieldRole, _fitsValue);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        _timeTag = new QLabel(EMASCDataPanel);
        _timeTag->setObjectName(QStringLiteral("_timeTag"));
        _timeTag->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(_timeTag);


        retranslateUi(EMASCDataPanel);

        QMetaObject::connectSlotsByName(EMASCDataPanel);
    } // setupUi

    void retranslateUi(QWidget *EMASCDataPanel)
    {
        EMASCDataPanel->setWindowTitle(QApplication::translate("EMASCDataPanel", "EMASCDataPanel", Q_NULLPTR));
        _emNameTag->setText(QApplication::translate("EMASCDataPanel", "ASC", Q_NULLPTR));
        _shutterspeedTag->setText(QApplication::translate("EMASCDataPanel", "ShutterSpeed:", Q_NULLPTR));
        _shutterSpeedValue->setText(QApplication::translate("EMASCDataPanel", "TextLabel", Q_NULLPTR));
        _apertureTag->setText(QApplication::translate("EMASCDataPanel", "Aperture:", Q_NULLPTR));
        _apertureValue->setText(QApplication::translate("EMASCDataPanel", "TextLabel", Q_NULLPTR));
        _isoTag->setText(QApplication::translate("EMASCDataPanel", "ISO:", Q_NULLPTR));
        _isoValue->setText(QApplication::translate("EMASCDataPanel", "TextLabel", Q_NULLPTR));
        _jpegTag->setText(QApplication::translate("EMASCDataPanel", "JPEG:", Q_NULLPTR));
        _jpegValue->setText(QApplication::translate("EMASCDataPanel", "TextLabel", Q_NULLPTR));
        _rawTag->setText(QApplication::translate("EMASCDataPanel", "RAW:", Q_NULLPTR));
        _rawValue->setText(QApplication::translate("EMASCDataPanel", "TextLabel", Q_NULLPTR));
        _fitsTag->setText(QApplication::translate("EMASCDataPanel", "FITS:", Q_NULLPTR));
        _fitsValue->setText(QApplication::translate("EMASCDataPanel", "TextLabel", Q_NULLPTR));
        _timeTag->setText(QApplication::translate("EMASCDataPanel", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EMASCDataPanel: public Ui_EMASCDataPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMASCDATAPANEL_H
