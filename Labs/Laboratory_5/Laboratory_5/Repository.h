#pragma once
#include "Domain.h"
#include "Dynamic_Vector.h"
#include <assert.h>
#include <vector>
#include <algorithm>

class Repository
{
protected:
	std::vector<Rock_Tshirt> rock_tshirts;

public:
	Repository() {}

	int find_by_id(int id);

	int add_rock_tshirt(Rock_Tshirt& rt);

	int delete_rock_thsirt(int id);

	int update_rock_thsirt_size(int id, std::string& new_size);

	int update_rock_thsirt_colour(int id, std::string& new_colour);

	int update_rock_thsirt_quantity(int id, int new_quantity);

	int update_rock_thsirt_price(int id, int new_price);

	int update_rock_thsirt_photo(int id, std::string& new_photo);

	std::vector<Rock_Tshirt> get_rock_tshirts() const { return rock_tshirts; }

	void populate_from_file(std::string file_name);
};
