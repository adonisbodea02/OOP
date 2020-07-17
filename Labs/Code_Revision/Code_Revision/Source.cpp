#include "Source.h"

Source::Source(std::string name, std::string status, std::string creator, std::string reviewer)
{
	this->creator = creator;
	this->name = name;
	this->reviewer = reviewer;
	this->status = status;
}

Source::~Source()
{
}

std::string Source::to_string()
{
	return name + " " + status + " " + creator + " " + reviewer;
}
