#pragma once
#include "Programmer.h"
#include "Source.h"
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

class Repo
{
private:
	std::vector<Programmer> prs;
	std::vector<Source> srs;
	void read();

public:
	Repo();
	~Repo();
	std::vector<Programmer> get_programmers() { return prs; }
	std::vector<Source> get_sources() { return srs; }
	void add_source(std::string, std::string);
	void update(std::string name);
	void write();
};

