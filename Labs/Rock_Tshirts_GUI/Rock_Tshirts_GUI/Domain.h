#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Rock_Tshirt
{
private:
	int ID;
	std::string size;
	std::string colour;
	int quantity;
	int price;
	std::string photo;
	std::string formation;

public:
	Rock_Tshirt();

	Rock_Tshirt(const int ID, const std::string& size, const std::string& colour, int quantity, int price, const std::string& photo, const std::string& formation);

	int operator==(const Rock_Tshirt& rt);

	int get_ID() const { return ID; }
	std::string get_size() const { return size; }
	std::string get_colour() const { return colour; }
	int get_price() const { return price; }
	int get_quantity() const { return quantity; }
	std::string get_photo() const { return photo; }
	std::string get_formation() const { return formation; }
	void set_size(std::string s) { size = s; }
	void set_colour(std::string c) { colour = c; }
	void set_quantity(int q) { quantity = q; }
	void set_price(int p) { price = p; }
	void set_photo(std::string p) { photo = p; }
	void set_formation(std::string f) { formation = f; }
	void display();
	void to_html(std::ostream & out);

	std::string to_string();
	std::string to_short_string();


	friend std::ostream& operator<<(std::ostream & stream, const Rock_Tshirt& rt);
	friend std::istream& operator>>(std::istream & stream, Rock_Tshirt& rt);
};
