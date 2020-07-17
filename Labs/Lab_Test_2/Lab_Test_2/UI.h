#pragma once
#include "Repository.h"
#include <vector>
#include <algorithm>

using namespace std;

class UI
{
private:
	RealEstateAgency r;

public:
	UI(RealEstateAgency r) { this->r = r; };
	void run();
	void print_menu();
	void add_dwelling_ui();
	void remove_client_ui();
	void write_to_file_ui();
	void show_clients();
	//void show_dwellings();

};