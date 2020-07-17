#pragma once
#include <string>
#include <iostream>
#include "Domain.h"
#include <vector>
#include <algorithm>
#include <fstream>

class RealEstateAgency
{
private:
	std::vector<Client*> clients;
	std::vector<Dwelling> dwellings;

public:
	RealEstateAgency() {}
	RealEstateAgency(std::vector<Client*> c) { this->clients = c; };

	Dwelling add_dwelling(std::string type, double price, bool is_profitable);
	void removeClient(std::string name);
	std::vector<Client*> get_interested(Dwelling d);
	void write_to_file(std::string filename);

	std::vector<Client*> get_clients() { return clients; };
	std::vector<Dwelling> get_dwellings() { return dwellings; };

};