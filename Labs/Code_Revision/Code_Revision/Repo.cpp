#include "Repo.h"



void Repo::read()
{
	std::ifstream f("programmers.txt");
	std::string name;
	int revised;
	int to_revised;
	while (f >> name >> revised >> to_revised)
	{
		Programmer p(name, revised, to_revised);
		prs.push_back(p);
	}
	f.close();

	f.open("source_files.txt");
	std::string status;
	std::string creator;
	std::string reviewer;
	while (f >> name >> status >> creator >> reviewer)
	{
		Source s(name, status, creator, reviewer);
		srs.push_back(s);
	}
	f.close();
}

void Repo::write()
{
	std::ofstream g("source_files.txt");
	for (auto i : srs)
		g << i.to_string() << "\n";
	g.close();
}

Repo::Repo()
{
	this->read();
}


Repo::~Repo()
{
	this->write();
}

void Repo::add_source(std::string name, std::string creator)
{
	if (name == "")
		throw "Invalid";
	for (auto i : srs)
	{
		if (i.get_name() == name)
			throw "Invalid";
	}
	srs.push_back(Source(name, std::string("not_revised"), creator, std::string("none")));
}

void Repo::update(std::string name)
{
	for (auto &i : srs)
		if (i.get_name() == name)
			i.set_status(std::string("revised"));
}
