#pragma once
#include "subject.h"
#include "Repository.h"

class Ctrl : public subject
{
private:
	Repository repo;

public:
	Ctrl(Repository& r) : repo{r} {}
	std::vector<Programmer> get_programmers_ctrl() { return repo.get_programmers(); }
	std::vector<Source_File> get_sources_ctrl() { return repo.get_sources(); }
	void add_source_ctrl(std::string name, std::string creator);
	void update_source_ctrl(std::string name, std::string reviewer);
};

