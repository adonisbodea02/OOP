#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository repo;

public:
	Controller(const Repository& r) : repo{ r } {}

	Repository get_repo() const { return repo; }

	int add_material(Material& m);

	int delete_material(std::string name, std::string supplier, Date expiry_date);

	int update_material_quantity(std::string name, std::string supplier, Date expiry_date, int new_quantity);

	std::vector<Material> filter_by_string(std::string name);

	std::vector<Material> filter_by_expiry_date(std::vector<Material> v);
};