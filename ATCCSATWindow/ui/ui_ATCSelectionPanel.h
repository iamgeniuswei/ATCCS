/********************************************************************************
** Form generated from reading UI file 'ATCSelectionPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCSELECTIONPANEL_H
#define UI_ATCSELECTIONPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCSelectionPanel
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QComboBox *_items;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ATCSelectionPanel)
    {
        if (ATCSelectionPanel->objectName().isEmpty())
            ATCSelectionPanel->setObjectName(QStringLiteral("ATCSelectionPanel"));
        ATCSelectionPanel->resize(400, 300);
        ATCSelectionPanel->setMinimumSize(QSize(0, 100));
        horizontalLayout = new QHBoxLayout(ATCSelectionPanel);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _items = new QComboBox(ATCSelectionPanel);
        _items->setObjectName(QStringLiteral("_items"));
        _items->setMinimumSize(QSize(200, 0));
        _items->setCursor(QCursor(Qt::PointingHandCursor));
        _items->setEditable(true);
        _items->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(_items);

        horizontalSpacer_2 = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(ATCSelectionPanel);

        QMetaObject::connectSlotsByName(ATCSelectionPanel);
    } // setupUi

    void retranslateUi(QWidget *ATCSelectionPanel)
    {
        ATCSelectionPanel->setWindowTitle(QApplication::translate("ATCSelectionPanel", "ATCSelectionPanel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ATCSelectionPanel: public Ui_ATCSelectionPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCSELECTIONPANEL_H
