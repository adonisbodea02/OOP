#pragma once
#include  <string>
#include "Vegetable.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
class File_Repo
{
private:
	std::string filename;
	std::vector<Vegetable> vs;

public:
	File_Repo(std::string filename);
	std::vector<Vegetable> get_all() { return vs; };
	void sort_alphabetically();
	std::vector<Vegetable> get_family(std::string family);
};

