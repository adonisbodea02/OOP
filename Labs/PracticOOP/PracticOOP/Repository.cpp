#include "Repository.h"

Repository::Repository()
{
	this->read();
}

void Repository::add_source(std::string name, std::string creator)
{
	if (name == "")
		//throw std::runtime_error("Invalid");
		throw std::string("Invalid");
	for (auto i : sources)
		if (i.get_name() == name)
			//throw std::runtime_error("Invalid");
			throw std::string("Invalid");
	sources.push_back(Source_File(name, std::string("not_revised"), creator, std::string("none")));
}

void Repository::update(std::string name, std::string reviewer)
{
	for (auto &i : sources)
		if (name == i.get_name())
		{
			i.set_status(std::string("revised"));
			i.set_reviewer(reviewer);
		}
}

void Repository::read()
{
	std::ifstream f("Programmers.txt");
	std::string name;
	int revised;
	int to_revise;
	while (f >> name >> revised >> to_revise)
		pros.push_back(Programmer(name, revised, to_revise));
	f.close();

	f.open("Sources.txt");
	std::string status;
	std::string creator;
	std::string reviewer;
	while (f >> name >> status >> creator >> reviewer)
		sources.push_back(Source_File(name, status, creator, reviewer));
	f.close();
}

void Repository::write()
{
	std::ofstream f("Sources.txt");
	for (auto i : sources)
		f << i.to_string() << "\n";
	f.close();
}