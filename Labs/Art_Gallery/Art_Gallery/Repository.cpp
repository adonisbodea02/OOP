#include "Repository.h"

void Repository::add_painting(Painting* p)
{
	this->paintings.push_back(p);
}

void Repository::remove_painting(std::string title, std::string artist, int year)
{
	std::vector<Painting*>::iterator it;
	it = std::find_if(this->paintings.begin(), this->paintings.end(), [&](Painting* p) {return (p->get_artist() == artist) && (p->get_title() == title) && (p->get_year() == year); });
	if (it != this->paintings.end())
		this->paintings.erase(it);
}

void Repository::write_to_file(std::string filename)
{
	std::ofstream fout(filename, std::ios::out | std::ios::trunc);
	std::for_each(this->paintings.begin(), this->paintings.end(), [&fout](Painting* p) {fout << p->to_string() << '\n'; });
	fout.close();
}

std::vector<Painting*>::iterator Repository::find(std::string title, std::string artist, int year)
{
	std::vector<Painting*>::iterator it;
	it = std::find_if(this->paintings.begin(), this->paintings.end(), [&](Painting* p) {return (p->get_artist() == artist) && (p->get_title() == title) && (p->get_year() == year); });
	return it;
}
