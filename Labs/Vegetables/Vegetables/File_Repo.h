#pragma once
#include  <string>
#include "Vegetable.h"
#include <vector>
#include <fstream>
class File_Repo
{
private:
	std::string filename;
	std::vector<Vegetable> vs;

public:
	File_Repo(std::string filename);
	~File_Repo();

};

