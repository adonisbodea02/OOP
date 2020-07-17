#pragma once
#include "Domain.h"
#include <vector>
#include <algorithm>

class Repository
{
private:
	std::vector<Tile> tiles;

public:

	Repository() {};
	void create_tiles();
	std::vector<Tile> get_tiles() { return tiles; };
};