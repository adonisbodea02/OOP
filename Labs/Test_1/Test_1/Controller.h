#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository repo;

public:

	Controller() {};
	Controller(Repository r) { repo = r; };
	int move_robot(int i, int j);
	std::vector<Tile> filter_cleaned_tiles();
	std::vector<Tile> get_tiles_ctrl() { return repo.get_tiles(); };
	double get_percentage();

};
