#pragma once
#include "Painting.h"
#include "Special_Painting.h"
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>

class Repository
{
protected:
	std::vector<Painting*> paintings;

public:
	Repository() {}

	void add_painting(Painting* p);

	void remove_painting(std::string title, std::string artist, int year);

	std::vector<Painting*> get_all() { return paintings; };

	void write_to_file(std::string filename);

	std::vector<Painting*>::iterator find(std::string title, std::string artist, int year);

	void remove_painting_pos(std::vector<Painting*>::iterator it) { this->paintings.erase(it); }

	bool valid_iterator(std::vector<Painting*>::iterator it) { return it != this->paintings.end(); }
};