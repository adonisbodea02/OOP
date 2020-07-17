#pragma once
#include "Subject.h"
#include "Repo.h"

class Controller : public Subject
{
private:
	Repo & repo;

public:
	Controller(Repo & r) : repo{ r } {}
	std::vector<Programmer> get_programmers_ctrl() { return this->repo.get_programmers(); }
	std::vector<Source> get_sources_ctrl() { return this->repo.get_sources(); }
	void add_source_ctrl(std::string name, std::string creator);
	void update_ctrl(std::string name);
	void save();
};