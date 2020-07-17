#pragma once
#include "Domain.h"
#include <vector>
#include <algorithm>

class Shop_list
{
private:
	std::vector<Rock_Tshirt> tshirts;
	std::vector<Rock_Tshirt> chosen_tshirts;
	int current;
	//int price{ 0 };

public:
	Shop_list();

	void set_tshirts(std::vector<Rock_Tshirt> v);

	Rock_Tshirt get_current_tshirt();

	Rock_Tshirt next();

	void add_chosen_tshirt(Rock_Tshirt rt);

	std::vector<Rock_Tshirt> get_chosen_tshirts() { return chosen_tshirts; };

	bool is_empty();
};
