#pragma once
#include <iostream>
class Offer
{
private:
	std::string type;
	std::string address;
	int surface;
	int price;
public:
	Offer();

	Offer(const std::string type, const std::string address, const int surface, const int price);

	bool operator==(Offer o);

	std::string get_type() { return type; };
	std::string get_address() { return address; };
	int get_surface() { return surface; };
	int get_price() { return price; };

	void set_type(std::string new_type) { type = new_type; };
	void set_price(int new_price) { price = new_price; };
	void set_surface(int new_surface) { surface = new_surface; };
	

};
