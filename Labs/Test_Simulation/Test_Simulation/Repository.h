#pragma once
#include "Domain.h"
#include <vector>
#include <algorithm>

class Repository
{
private:
	std::vector<Offer> offers;

public:
	Repository() {}

	int find_offer_by_address(std::string address);
	int add_offer_repo(Offer o);
	int delete_offer_repo(std::string address);
	int update_price_offer_repo(std::string address, int new_price);
	int update_type_offer_repo(std::string address, std::string new_type);

	std::vector<Offer> get_vector() { return offers; }

};