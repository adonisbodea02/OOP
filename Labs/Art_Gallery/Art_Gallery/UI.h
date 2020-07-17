#pragma once
#include "Controller.h"
#include <algorithm>
#include <string>

using namespace std;

class UI
{
private:
	Controller c;

public:

	UI(Controller& c) { this->c = c; }

	void print_menu();
	void add_painting();
	void remove_painting();
	void move_painting();
	void save_to_file();
	void print_all();
	void print_special();
	void run();
};