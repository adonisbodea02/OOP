#include "Repository.h"
#include <algorithm>

int Repository::find_offer_by_address(std::string address)
{
	std::vector<Offer>::iterator it;
	it = std::find_if(this->offers.begin(), this->offers.end(), [&](Offer o) {return o.get_address() == address; });
	if (it != this->offers.end())
		return it - this->offers.begin();
	return -1;
}
int Repository::add_offer_repo(Offer o)
{
	int pos = this->find_offer_by_address(o.get_address());
	if (pos == -1)
	{
		this->offers.push_back(o);
		return 1;
	}
	return 0;

}
int Repository::delete_offer_repo(std::string address)
{
	std::vector<Offer>::iterator it;
	it = std::find_if(this->offers.begin(), this->offers.end(), [&](Offer o) {return o.get_address() == address; });
	if (it != this->offers.end())
	{
		this->offers.erase(it);
		return 1;
	}
	return 0;
}
int Repository::update_price_offer_repo(std::string address, int new_price)
{
	int pos = this->find_offer_by_address(address);
	if (pos != -1)
	{
		this->offers.at(pos).set_price(new_price);
		return 1;
	}
	return 0;
}
int Repository::update_type_offer_repo(std::string address, std::string new_type)
{
	int pos = this->find_offer_by_address(address);
	if (pos != -1)
	{
		this->offers.at(pos).set_type(new_type);
		return 1;
	}
	return 0;
}