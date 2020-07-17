#include "Repository.h"

void Repository::create_tiles()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 11; i++)
	{
		for (j = 0; j < 11; j++)
		{
			this->tiles.push_back(Tile(i, j));
		}
	}
}