#pragma once

#include "Repository.h"
#include <fstream>
#include <vector>
#include <algorithm>

class File_Repo : public Repository
{
private:
	std::string filename;

public:
	File_Repo(std::string filename);

	~File_Repo();

	void write();

	void read();
};