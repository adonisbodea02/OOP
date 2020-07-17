#include "Special_Painting.h"

Special_Painting::Special_Painting(const std::string & title, const std::string artist, const int year, const double temperature)
{
	this->title = title;
	this->artist = artist;
	this->year = year;
	this->temperature = temperature;
}

std::string Special_Painting::to_string()
{
	std::string s;
	s += this->title;
	s += ", ";
	s += this->artist;
	s += ", ";
	s += std::to_string(this->year);
	s += ", ";
	s += std::to_string(this->temperature);
	return s;
}

bool Special_Painting::is_special()
{
	return (this->temperature <= 22 && this->temperature >= 18);
}
