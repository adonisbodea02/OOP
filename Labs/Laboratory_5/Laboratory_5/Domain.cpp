#include "Domain.h"
#include <Windows.h>
#include <shellapi.h>

Rock_Tshirt::Rock_Tshirt(): ID(), size(""), colour(""), quantity(), price(), photo(""), formation("") {}

Rock_Tshirt::Rock_Tshirt(const int ID, const std::string& size, const std::string& colour, int quantity, int price, const std::string& photo, const std::string& formation)
{
	this->ID = ID;
	this->size = size;
	this->colour = colour;
	this->quantity = quantity;
	this->price = price;
	this->photo = photo;
	this->formation = formation;
}

int Rock_Tshirt::operator==(const Rock_Tshirt& rt)
{
	return this->get_ID() == rt.get_ID();
}

void Rock_Tshirt::display()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->get_photo().c_str(), NULL, SW_SHOWMAXIMIZED);
}

void Rock_Tshirt::to_html(std::ostream & out)
{
	out << "\n\t\t<tr>";
	out << "\n\t\t\t<td>" << this->size << "</td>";
	out << "\n\t\t\t<td>" << this->colour << "</td>";
	out << "\n\t\t\t<td>" << this->price << "</td>";
	out << "\n\t\t\t<td>" << this->quantity << "</td>";
	out << "\n\t\t\t<td>" << this->formation << "</td>";
	out << "\n\t\t\t<td><a href =\"" << this->photo << "\">Link</a></td>";
	out << "\n\t\t<tr>";
}

std::ostream & operator<<(std::ostream & stream, const Rock_Tshirt & rt)
{
	stream << rt.get_ID() << "," << rt.get_size() << "," << rt.get_colour() << "," << rt.get_quantity() << "," << rt.get_price() << "," << rt.get_photo() << "," << rt.get_formation();
	return stream;
}

std::istream & operator>>(std::istream & stream, Rock_Tshirt & rt)
{
	stream >> rt.ID;
	stream.get();
	getline(stream, rt.size, ',');
	getline(stream, rt.colour, ',');
	stream >> rt.quantity;
	stream.get();
	stream >> rt.price;
	stream.get();
	getline(stream, rt.photo, ',');
	getline(stream, rt.formation);
	return stream;
}
