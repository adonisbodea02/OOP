#pragma once
#include "Controller.h"

class UI 
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl{c} {}
	void start();

private:
	static void print_menu();
	int add_offer_ui();
	int delete_offer_ui();
	int update_offer_price_ui();
	int update_offer_type_ui();
	void filter_by_string_ui();
	void print_offers(std::vector<Offer> v);
};