#include "Controller.h"

void Controller::add_painting_ctrl(Painting* p)
{
	this->repo_all.add_painting(p);
}

void Controller::delete_painting_ctrl(std::string title, std::string artist, int year)
{
	this->repo_all.remove_painting(title, artist, year);
}

void Controller::move(std::string title, std::string artist, int year)
{
	std::vector<Painting*>::iterator it;
	it = this->repo_all.find(title, artist, year);
	if(this->repo_all.valid_iterator(it))
		if ((*it)->is_special())
		{
			Painting* keep;
			keep = *it;
			this->repo_all.remove_painting_pos(it);
			this->special_storage.add_painting(keep);
		}
}

void Controller::write_ctrl(std::string filename)
{
	std::string f = filename;
	filename += "_all.txt";
	this->repo_all.write_to_file(filename);
	f += "_special.txt";
	this->special_storage.write_to_file(f);
}


