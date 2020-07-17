#include "Programmer.h"

Programmer::Programmer(std::string name, int r, int to_r)
{
	this->name = name;
	this->revised = r;
	this->to_revise = to_r;
}

std::string Programmer::to_string()
{
	return name + " " + std::to_string(revised) + " " + std::to_string(to_revise);
}

Programmer::~Programmer()
{
}
