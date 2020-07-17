#include "Source_File.h"

Source_File::Source_File(std::string name, std::string status, std::string creator, std::string reviewer)
{
	this->creator = creator;
	this->reviewer = reviewer;
	this->status = status;
	this->name = name;
}
