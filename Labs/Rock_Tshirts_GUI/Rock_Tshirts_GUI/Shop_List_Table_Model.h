#pragma once
#include "qabstractitemmodel.h"
#include "CVS_ShopList.h"
#include "Controller.h"

class Shop_List_Table_Model : public QAbstractTableModel
{
private:
	Controller *ctrl;

public:
	Shop_List_Table_Model(Controller *c) : ctrl{ c } {}
	virtual ~Shop_List_Table_Model() {}
	int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
	int columnCount(const QModelIndex& parent = QModelIndex{}) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	//bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
	//Qt::ItemFlags flags(const QModelIndex& index) const override;
};