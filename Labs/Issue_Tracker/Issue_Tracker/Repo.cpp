#include "Repo.h"



Repo::Repo()
{
	read();
}

void Repo::read()
{
	std::ifstream f("programmers.txt");
	std::string name;
	std::string type;
	while (f >> name >> type)
		users.push_back(User(name, type));
	f.close();

	f.open("issues.txt");
	std::string description;
	std::string status;
	std::string reporter;
	std::string solver;
	while (f >> description >> status >> reporter >> solver)
		issues.push_back(Issue(description, status, reporter, solver));
	f.close();
}

void Repo::write()
{
	std::ofstream g("issues.txt");
	for (auto i : issues)
		g << i.to_string() << "\n";
	g.close();
}

void Repo::add_issue(std::string description, std::string reporter, std::string type)
{
	if (type != "Tester")
		throw "Error";
	if (description == "")
		throw "Error";
	for (auto i : issues)
		if (i.get_description() == description)
			throw "Error";
	issues.push_back(Issue(description, std::string("open"), reporter, std::string("none")));
}

void Repo::remove_issue(std::string description, std::string status)
{
	if (status == "open")
		throw "Error";
	std::vector<Issue>::iterator it = std::find_if(issues.begin(), issues.end(), [&](Issue& i) {return i.get_description() == description; });
	issues.erase(it);
}

void Repo::update_issue(std::string description, std::string solver)
{
	for(auto &i : issues)
		if (i.get_description() == description)
		{
			i.set_solver(solver);
			i.set_status(std::string("closed"));
			break;
		}
}
