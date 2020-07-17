#include "Domain.h"

Offer::Offer() : type(""), address(""), price(), surface() {}

Offer::Offer(const std::string type, const std::string address, const int surface, const int price)
{
	this->address = address;
	this->type = type;
	this->price = price;
	this->surface = surface;
}

bool Offer::operator==(Offer o)
{
	return this->get_address() == o.get_address();
}
