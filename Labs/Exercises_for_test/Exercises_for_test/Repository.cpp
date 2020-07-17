#include "Repository.h"
#include <algorithm>

int Repository::find_material(Material& m)
{
	std::vector<Material>::iterator it;
	it = std::find(this->materials.begin(), this->materials.end(), m);
	if (it != this->materials.end())
		return it - this->materials.begin();
	else
		return -1;
}

int Repository::add_material(Material& m)
{
	int pos = this->find_material(m);
	if (pos == -1)
	{
		this->materials.push_back(m);
		return 1;
	}
	else
	{
		int q = m.get_quantity();
		q += this->materials.at(pos).get_quantity();
		this->materials.at(pos).set_quantity(q);
		return 0;
	}	
}

int Repository::delete_material(std::string name, std::string supplier, Date expiry_date)
{
	Material m = Material(name, supplier, 0, expiry_date);
	std::vector<Material>::iterator it = std::find(this->materials.begin(), this->materials.end(), m);
	if (it != this->materials.end())
	{
		this->materials.erase(it);
		return 1;
	}
	else
		return 0;


}

int Repository::update_quantity(std::string name, std::string supplier, Date expiry_date, int new_quantity)
{
	Material m = Material(name, supplier, 0, expiry_date);
	int pos = this->find_material(m);
	if (pos != -1)
	{
		this->materials.at(pos).set_quantity(new_quantity);
		return 1;
	}
	else
		return 0;
}