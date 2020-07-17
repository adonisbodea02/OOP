#pragma once
#include "Controller.h"
#include "ShopList.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void start();

private:
	static void print_menu();
	static void print_administrator_menu();
	static void print_user_menu();
	static void print_shop_list_menu();

	int add_rock_tshirt_ui();
	int delete_rock_thsirt_ui();
	int update_rock_thsirt_size_ui();
	int update_rock_tshirt_colour_ui();
	int update_rock_thsirt_photo_ui();
	int update_rock_thsirt_price_ui();
	int update_rock_thsirt_quantity_ui();

	void print_all_rock_tshirts();
	std::vector<Rock_Tshirt> filter_by_size_ui();

	void shop_list_ui();
};
