#pragma once
#include <string>
#include <vector>
#include "Equation.h"
#include <fstream>

class File_Repo
{
public:
	File_Repo(std::string filename);
	std::vector<Equation> get_eqs() { return eqs; };

private:
	std::string filename;
	std::vector<Equation> eqs;
};

