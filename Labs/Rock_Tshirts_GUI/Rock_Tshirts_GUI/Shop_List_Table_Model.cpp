#include "Shop_List_Table_Model.h"

int Shop_List_Table_Model::rowCount(const QModelIndex & parent) const
{
	return this->ctrl->sh->get_chosen_tshirts().size();
}

int Shop_List_Table_Model::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QVariant Shop_List_Table_Model::data(const QModelIndex & index, int role) const
{
	Rock_Tshirt rt = this->ctrl->sh->get_chosen_tshirts()[index.row()];
	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:
			return QString::fromStdString(rt.get_formation());
		case 1:
			return QString::fromStdString(rt.get_size());
		case 2:
			return QString::fromStdString(rt.get_colour());
		case 3:
			return QString::number(rt.get_price());
		case 4:
			return QString::fromStdString(rt.get_photo());
		default:
			break;
		}
	}
	return QVariant();
}

QVariant Shop_List_Table_Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Formation: " };
			case 1:
				return QString{ "Size: " };
			case 2:
				return QString{ "Colour: " };
			case 3:
				return QString{ "Price: " };
			case 4:
				return QString{ "Photo: " };
			}
		}
	}
	return QVariant();
}

/*
bool Shop_List_Table_Model::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;
	int row = index.row();
	int col = index.column();
	Rock_Tshirt rt = this->sh->get_chosen_tshirts()[index.row()];
	return true;
}

Qt::ItemFlags Shop_List_Table_Model::flags(const QModelIndex & index) const
{
	int col = index.column();
	if (col == 0 || col == 1 || col == 2 || col == 3 || col == 4)
		return Qt::ItemFlags{};
}
*/
