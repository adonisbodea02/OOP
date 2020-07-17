#pragma once

#include <QWidget>
#include "ui_Model.h"
#include <qabstractitemmodel.h>
#include "File_ShopList.h"
#include "Shop_List_Table_Model.h"
#include "CVS_ShopList.h"
#include "Controller.h"

class Model : public QWidget
{
	Q_OBJECT

public:
	Model(QWidget *parent, Controller& c);
	~Model();

private:
	Ui::Model ui;
	Controller ctrl;
	Shop_List_Table_Model* m;
};
