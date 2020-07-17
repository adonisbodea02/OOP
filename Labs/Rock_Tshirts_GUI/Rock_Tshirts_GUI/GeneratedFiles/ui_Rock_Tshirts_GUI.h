/********************************************************************************
** Form generated from reading UI file 'Rock_Tshirts_GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROCK_TSHIRTS_GUI_H
#define UI_ROCK_TSHIRTS_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rock_Tshirts_GUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Rock_Tshirts_GUIClass)
    {
        if (Rock_Tshirts_GUIClass->objectName().isEmpty())
            Rock_Tshirts_GUIClass->setObjectName(QStringLiteral("Rock_Tshirts_GUIClass"));
        Rock_Tshirts_GUIClass->resize(600, 400);
        menuBar = new QMenuBar(Rock_Tshirts_GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Rock_Tshirts_GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Rock_Tshirts_GUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Rock_Tshirts_GUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Rock_Tshirts_GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Rock_Tshirts_GUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Rock_Tshirts_GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Rock_Tshirts_GUIClass->setStatusBar(statusBar);

        retranslateUi(Rock_Tshirts_GUIClass);

        QMetaObject::connectSlotsByName(Rock_Tshirts_GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *Rock_Tshirts_GUIClass)
    {
        Rock_Tshirts_GUIClass->setWindowTitle(QApplication::translate("Rock_Tshirts_GUIClass", "Rock_Tshirts_GUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rock_Tshirts_GUIClass: public Ui_Rock_Tshirts_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROCK_TSHIRTS_GUI_H
