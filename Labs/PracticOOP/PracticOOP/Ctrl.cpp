#include "Ctrl.h"

void Ctrl::add_source_ctrl(std::string name, std::string creator)
{
	repo.add_source(name, creator);
	notify();
}

void Ctrl::update_source_ctrl(std::string name, std::string reviewer)
{
	repo.update(name, reviewer);
	notify();
}
