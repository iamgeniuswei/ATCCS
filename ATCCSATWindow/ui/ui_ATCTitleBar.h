/********************************************************************************
** Form generated from reading UI file 'ATCTitleBar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCTITLEBAR_H
#define UI_ATCTITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCTitleBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *_logo;
    QLabel *_title;
    QSpacerItem *horizontalSpacer;
    QToolButton *_setting;
    QLabel *label;
    QToolButton *_min;
    QToolButton *_max;
    QToolButton *_close;

    void setupUi(QWidget *ATCTitleBar)
    {
        if (ATCTitleBar->objectName().isEmpty())
            ATCTitleBar->setObjectName(QStringLiteral("ATCTitleBar"));
        ATCTitleBar->resize(690, 64);
        ATCTitleBar->setMinimumSize(QSize(0, 48));
        ATCTitleBar->setMaximumSize(QSize(16777215, 64));
        ATCTitleBar->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(ATCTitleBar);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(8, 4, 8, 4);
        _logo = new QLabel(ATCTitleBar);
        _logo->setObjectName(QStringLiteral("_logo"));
        _logo->setMaximumSize(QSize(40, 40));
        _logo->setScaledContents(true);
        _logo->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(_logo);

        _title = new QLabel(ATCTitleBar);
        _title->setObjectName(QStringLiteral("_title"));
        _title->setScaledContents(true);

        horizontalLayout->addWidget(_title);

        horizontalSpacer = new QSpacerItem(471, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _setting = new QToolButton(ATCTitleBar);
        _setting->setObjectName(QStringLiteral("_setting"));
        _setting->setMinimumSize(QSize(20, 20));
        _setting->setMaximumSize(QSize(20, 20));
        _setting->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(_setting);

        label = new QLabel(ATCTitleBar);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 24));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/vertical_spilter")));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        _min = new QToolButton(ATCTitleBar);
        _min->setObjectName(QStringLiteral("_min"));
        _min->setMinimumSize(QSize(20, 20));
        _min->setMaximumSize(QSize(20, 20));
        _min->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(_min);

        _max = new QToolButton(ATCTitleBar);
        _max->setObjectName(QStringLiteral("_max"));
        _max->setMinimumSize(QSize(20, 20));
        _max->setMaximumSize(QSize(18, 18));
        _max->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(_max);

        _close = new QToolButton(ATCTitleBar);
        _close->setObjectName(QStringLiteral("_close"));
        _close->setMinimumSize(QSize(20, 20));
        _close->setMaximumSize(QSize(20, 20));
        _close->setCursor(QCursor(Qt::PointingHandCursor));
        _close->setIconSize(QSize(12, 12));

        horizontalLayout->addWidget(_close);


        retranslateUi(ATCTitleBar);

        QMetaObject::connectSlotsByName(ATCTitleBar);
    } // setupUi

    void retranslateUi(QWidget *ATCTitleBar)
    {
        ATCTitleBar->setWindowTitle(QApplication::translate("ATCTitleBar", "ATCTitleBar", Q_NULLPTR));
        _logo->setText(QApplication::translate("ATCTitleBar", "logo", Q_NULLPTR));
        _title->setText(QApplication::translate("ATCTitleBar", "title", Q_NULLPTR));
        _setting->setText(QString());
        label->setText(QString());
        _min->setText(QString());
        _max->setText(QString());
        _close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ATCTitleBar: public Ui_ATCTitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCTITLEBAR_H
