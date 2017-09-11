/********************************************************************************
** Form generated from reading UI file 'EMSettingTilteBar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMSETTINGTILTEBAR_H
#define UI_EMSETTINGTILTEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EMSettingTilteBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *_logo;
    QLabel *_title;
    QToolButton *_close;

    void setupUi(QWidget *EMSettingTilteBar)
    {
        if (EMSettingTilteBar->objectName().isEmpty())
            EMSettingTilteBar->setObjectName(QStringLiteral("EMSettingTilteBar"));
        EMSettingTilteBar->resize(400, 34);
        EMSettingTilteBar->setMaximumSize(QSize(16777215, 48));
        horizontalLayout = new QHBoxLayout(EMSettingTilteBar);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        _logo = new QLabel(EMSettingTilteBar);
        _logo->setObjectName(QStringLiteral("_logo"));
        _logo->setMaximumSize(QSize(24, 24));
        _logo->setPixmap(QPixmap(QString::fromUtf8(":/img/setting_logo")));
        _logo->setScaledContents(true);

        horizontalLayout->addWidget(_logo);

        _title = new QLabel(EMSettingTilteBar);
        _title->setObjectName(QStringLiteral("_title"));
        QFont font;
        font.setPointSize(14);
        _title->setFont(font);

        horizontalLayout->addWidget(_title);

        _close = new QToolButton(EMSettingTilteBar);
        _close->setObjectName(QStringLiteral("_close"));

        horizontalLayout->addWidget(_close);

        horizontalLayout->setStretch(1, 1);

        retranslateUi(EMSettingTilteBar);

        QMetaObject::connectSlotsByName(EMSettingTilteBar);
    } // setupUi

    void retranslateUi(QWidget *EMSettingTilteBar)
    {
        EMSettingTilteBar->setWindowTitle(QApplication::translate("EMSettingTilteBar", "EMSettingTilteBar", Q_NULLPTR));
        _logo->setText(QString());
        _title->setText(QApplication::translate("EMSettingTilteBar", "Setting", Q_NULLPTR));
        _close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EMSettingTilteBar: public Ui_EMSettingTilteBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMSETTINGTILTEBAR_H
