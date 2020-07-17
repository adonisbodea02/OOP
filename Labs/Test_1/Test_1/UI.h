#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;
	int x;
	int y;

public:
	UI() {};
	void start();
	void set_controller(Controller c) { ctrl = c; };

private:
	static void print_menu();
	int move_up();
	int move_down();
	int move_right();
	int move_left();
	void show_tiles();
	int get_x_ui() { return x; };
	int get_y_ui() { return y; };
};
