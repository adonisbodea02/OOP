/********************************************************************************
** Form generated from reading UI file 'Model.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODEL_H
#define UI_MODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Model
{
public:
    QGridLayout *gridLayout;
    QTableView *table;

    void setupUi(QWidget *Model)
    {
        if (Model->objectName().isEmpty())
            Model->setObjectName(QStringLiteral("Model"));
        Model->resize(400, 296);
        gridLayout = new QGridLayout(Model);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        table = new QTableView(Model);
        table->setObjectName(QStringLiteral("table"));

        gridLayout->addWidget(table, 0, 0, 1, 1);


        retranslateUi(Model);

        QMetaObject::connectSlotsByName(Model);
    } // setupUi

    void retranslateUi(QWidget *Model)
    {
        Model->setWindowTitle(QApplication::translate("Model", "Model", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Model: public Ui_Model {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODEL_H
