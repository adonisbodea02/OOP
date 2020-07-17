#include "Issue.h"

Issue::Issue(std::string description, std::string status, std::string reporter, std::string solver)
{
	this->description = description;
	this->status = status;
	this->reporter = reporter;
	this->solver = solver;
}
