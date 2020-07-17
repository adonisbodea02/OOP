#include "Programmer.h"

Programmer::Programmer(std::string name, int revise, int to_revise)
{
	this->name = name;
	this->revised = revise;
	this->to_revise = to_revise;
}
