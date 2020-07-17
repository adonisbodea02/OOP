#include "Controller.h"
#include <algorithm>
#include <ctime>

int Controller::add_material(Material& m)
{
	return this->repo.add_material(m);
}

int Controller::delete_material(std::string name, std::string supplier, Date expiry_date)
{
	return this->repo.delete_material(name, supplier, expiry_date);
}

int Controller::update_material_quantity(std::string name, std::string supplier, Date expiry_date, int new_quantity)
{
	return this->repo.update_quantity(name, supplier, expiry_date, new_quantity);
}

std::vector<Material> Controller::filter_by_string(std::string name)
{
	std::vector<Material> v1 = this->get_repo().get_materials_repo();
	std::vector<Material> v2(v1.size());
	auto it = std::copy_if(v1.begin(), v1.end(), v2.begin(), [&](Material m) {return (m.get_name().find(name) != std::string::npos); });
	v2.resize(std::distance(v2.begin(), it));

	return v2;
}

std::vector<Material> Controller::filter_by_expiry_date(std::vector<Material> v)
{
	std::vector<Material> v2(v.size());
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	auto it = std::copy_if(v.begin(), v.end(), v2.begin(), [&](Material m) { return m.get_expiry_date().compare_dates(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);  });
	v2.resize(std::distance(v2.begin(), it));

	return v2;
}