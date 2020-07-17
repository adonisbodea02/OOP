#pragma once
#include "Domain.h"
#include <vector>

class Repository
{
private:
	std::vector<Material> materials;

public:
	Repository() {}

	int find_material(Material& m);

	int add_material(Material& m);

	int delete_material(std::string name, std::string supplier, Date expiry_date);

	int update_quantity(std::string name, std::string supplier, Date expiry_date, int new_quantity);

	std::vector<Material> get_materials_repo() { return materials; }

};