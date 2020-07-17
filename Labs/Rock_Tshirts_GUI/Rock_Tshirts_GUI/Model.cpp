#include "Model.h"

Model::Model(QWidget *parent, Controller& c) : ctrl{ c }
{
	ui.setupUi(this);
	this->m = new Shop_List_Table_Model(&this->ctrl);
	ui.table->setModel(m);
}

Model::~Model()
{
}
