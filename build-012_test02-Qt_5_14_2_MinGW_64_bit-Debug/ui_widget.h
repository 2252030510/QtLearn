/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <form.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    Form *widget;
    QPushButton *btnget;
    QPushButton *btnset;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        widget = new Form(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 30, 221, 41));
        btnget = new QPushButton(Widget);
        btnget->setObjectName(QString::fromUtf8("btnget"));
        btnget->setGeometry(QRect(130, 110, 75, 23));
        btnset = new QPushButton(Widget);
        btnset->setObjectName(QString::fromUtf8("btnset"));
        btnset->setGeometry(QRect(130, 160, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btnget->setText(QCoreApplication::translate("Widget", "get", nullptr));
        btnset->setText(QCoreApplication::translate("Widget", "set50", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
