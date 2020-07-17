#include "Controller.h"
#include <iostream>

int Controller::move_robot(int i, int j)
{
	if (i < 0 || j < 0)
		return 0;
	if (i > 10 || j > 10)
		return 0;
	for (auto k : this->get_tiles_ctrl())
	{
		if (k.get_x() == i && k.get_y() == j && k.get_status() == 1)
			return 0;
	}

	for (auto i : this->get_tiles_ctrl())
		std::cout << "x: " << i.get_x() << "  y: " << i.get_y() << "  status: " << i.get_status() << "\n";

	return 1;
}

std::vector<Tile> Controller::filter_cleaned_tiles()
{
	std::vector<Tile> v = this->get_tiles_ctrl();
	std::vector<Tile> v2;
	for (auto i : v)
	{
		if (i.get_status() == 1)
			v2.push_back(i);
	}
	return v2;
}

double Controller::get_percentage()
{
	double p;
	std::vector<Tile> v = this->get_tiles_ctrl();
	std::vector<Tile> v2= this->filter_cleaned_tiles();


	p = v2.size() / v.size();
	return p;
}
