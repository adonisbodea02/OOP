#pragma once
#include <iostream>
#include <string.h>

class Painting
{
protected:
	std::string title;
	std::string artist;
	int year;

public:

	bool operator==(Painting& p);

	std::string get_title() { return title; };

	std::string get_artist() { return artist; };

	int get_year() { return year; };

	Painting();

	Painting(const std::string& title, const std::string artist, const int year);

	virtual bool is_special() { return false; };

	virtual std::string to_string();
};