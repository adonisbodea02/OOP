#include "File_Repo.h"

File_Repo::File_Repo(std::string filename)
{
	this->filename = filename;
	std::ifstream f(filename);
	std::string family;
	std::string name;
	std::string type;
	while (!f.eof()) {
		std::getline(f, family, '|');
		std::getline(f, name, '|');
		std::getline(f, type);
		vs.push_back(Vegetable(family, name, type));
	}
	std::ofstream g("output.txt");
	for (auto i : vs)
		g << i.get_family() << " " << i.get_name() << " " << i.get_type() << "\n";

}

File_Repo::~File_Repo()
{
}
