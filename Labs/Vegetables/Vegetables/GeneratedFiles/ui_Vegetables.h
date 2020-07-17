/********************************************************************************
** Form generated from reading UI file 'Vegetables.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEGETABLES_H
#define UI_VEGETABLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VegetablesClass
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QWidget *VegetablesClass)
    {
        if (VegetablesClass->objectName().isEmpty())
            VegetablesClass->setObjectName(QStringLiteral("VegetablesClass"));
        VegetablesClass->resize(600, 400);
        centralWidget = new QWidget(VegetablesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(40, 20, 256, 192));
        VegetablesClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VegetablesClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        VegetablesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VegetablesClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VegetablesClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VegetablesClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VegetablesClass->setStatusBar(statusBar);

        retranslateUi(VegetablesClass);

        QMetaObject::connectSlotsByName(VegetablesClass);
    } // setupUi

    void retranslateUi(QMainWindow *VegetablesClass)
    {
        VegetablesClass->setWindowTitle(QApplication::translate("VegetablesClass", "Vegetables", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VegetablesClass: public Ui_VegetablesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEGETABLES_H
