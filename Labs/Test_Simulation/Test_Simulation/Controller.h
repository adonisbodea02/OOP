#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository repo;

public:
	Controller(const Repository& r) : repo { r } {}
	Repository get_repo() { return repo; }
	int add_offer_ctrl(Offer o) { return this->repo.add_offer_repo(o); }
	int delete_offer_ctrl(std::string address) { return this->repo.delete_offer_repo(address); }
	int update_price_offer_ctrl(std::string address, int new_price) { return this->repo.update_price_offer_repo(address, new_price); }
	int update_type_offer_ctrl(std::string address, std::string new_type) { return this->repo.update_type_offer_repo(address, new_type); }

	std::vector<Offer> filter_by_string_ctrl(std::string s);
};
