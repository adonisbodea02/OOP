#include "Controller.h"

void Controller::add_source_ctrl(std::string name, std::string creator)
{
	this->repo.add_source(name, creator);
	notify();
}

void Controller::update_ctrl(std::string name)
{
	this->repo.update(name);
	notify();
}

void Controller::save()
{
	this->repo.write();
}
