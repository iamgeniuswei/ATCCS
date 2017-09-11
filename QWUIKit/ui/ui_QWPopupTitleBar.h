/********************************************************************************
** Form generated from reading UI file 'QWPopupTitleBar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWPOPUPTITLEBAR_H
#define UI_QWPOPUPTITLEBAR_H

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

class Ui_QWPopupTitleBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *_logo;
    QLabel *_title;
    QSpacerItem *horizontalSpacer;
    QToolButton *_close;

    void setupUi(QWidget *QWPopupTitleBar)
    {
        if (QWPopupTitleBar->objectName().isEmpty())
            QWPopupTitleBar->setObjectName(QStringLiteral("QWPopupTitleBar"));
        QWPopupTitleBar->setWindowModality(Qt::NonModal);
        QWPopupTitleBar->resize(400, 50);
        QWPopupTitleBar->setMinimumSize(QSize(0, 50));
        QWPopupTitleBar->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(QWPopupTitleBar);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 0, 5, 0);
        _logo = new QLabel(QWPopupTitleBar);
        _logo->setObjectName(QStringLiteral("_logo"));
        _logo->setMaximumSize(QSize(16777215, 48));

        horizontalLayout->addWidget(_logo);

        _title = new QLabel(QWPopupTitleBar);
        _title->setObjectName(QStringLiteral("_title"));
        _title->setMaximumSize(QSize(16777215, 48));

        horizontalLayout->addWidget(_title);

        horizontalSpacer = new QSpacerItem(351, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _close = new QToolButton(QWPopupTitleBar);
        _close->setObjectName(QStringLiteral("_close"));
        _close->setMinimumSize(QSize(20, 20));
        _close->setMaximumSize(QSize(20, 20));
        _close->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(_close);


        retranslateUi(QWPopupTitleBar);

        QMetaObject::connectSlotsByName(QWPopupTitleBar);
    } // setupUi

    void retranslateUi(QWidget *QWPopupTitleBar)
    {
        QWPopupTitleBar->setWindowTitle(QApplication::translate("QWPopupTitleBar", "QWPopupTitleBar", Q_NULLPTR));
        _logo->setText(QString());
        _title->setText(QString());
        _close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QWPopupTitleBar: public Ui_QWPopupTitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWPOPUPTITLEBAR_H
