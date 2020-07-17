#pragma once
#include <iostream>

class Tile
{
private:
	int x;
	int y;
	int status;

public:
	Tile(const int x, const int y);
	int get_x() { return x; };
	int get_y() { return y; };
	int get_status(){ return status; };
	void set_status(int new_status) { status = new_status; };
};
