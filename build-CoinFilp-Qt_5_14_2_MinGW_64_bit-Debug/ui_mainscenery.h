/********************************************************************************
** Form generated from reading UI file 'mainscenery.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENERY_H
#define UI_MAINSCENERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainScenery
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *mainScenery)
    {
        if (mainScenery->objectName().isEmpty())
            mainScenery->setObjectName(QString::fromUtf8("mainScenery"));
        mainScenery->resize(320, 588);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainScenery->sizePolicy().hasHeightForWidth());
        mainScenery->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(mainScenery);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainScenery->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainScenery);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        mainScenery->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());

        retranslateUi(mainScenery);

        QMetaObject::connectSlotsByName(mainScenery);
    } // setupUi

    void retranslateUi(QMainWindow *mainScenery)
    {
        mainScenery->setWindowTitle(QCoreApplication::translate("mainScenery", "\347\277\273\351\207\221\345\270\201", nullptr));
        menu->setTitle(QCoreApplication::translate("mainScenery", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainScenery: public Ui_mainScenery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENERY_H
