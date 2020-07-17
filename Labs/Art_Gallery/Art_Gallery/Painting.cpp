#include "Painting.h"
#include <string>

bool Painting::operator==(Painting & p)
{
	return (this->get_title() == p.get_title()) && (this->get_artist() == p.get_artist()) && (this->get_year() == p.get_year());
}

Painting::Painting(): title(""), artist(""), year() {}

Painting::Painting(const std::string & title, const std::string artist, const int year)
{
	this->title = title;
	this->year = year;
	this->artist = artist;
}

std::string Painting::to_string()
{
	std::string s;
	s += title;
	s += ", ";
	s += artist;
	s += ", ";
	s += std::to_string(year);
	return s;
}
