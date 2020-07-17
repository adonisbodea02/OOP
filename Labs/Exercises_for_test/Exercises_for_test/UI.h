#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void start();

private:
	static void print_menu();
	
	int add_material_ui();
	int delete_material_ui();
	int update_quantity_ui();
	void filter_by_string_ui();

	void print_materials();
};