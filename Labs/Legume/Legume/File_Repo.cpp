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
	this->sort_alphabetically();
	std::ofstream g("output.txt");
	for (auto i : vs)
		g << i.get_family() << " " << i.get_name() << " " << i.get_type() << "\n";

}

void File_Repo::sort_alphabetically()
{
	std::sort(vs.begin(), vs.end(), [](Vegetable& v1, Vegetable& v2) {return v1.get_family() < v2.get_family(); });
}

std::vector<Vegetable> File_Repo::get_family(std::string family)
{
	std::vector<Vegetable> fam;
	for (auto i : vs)
		if (i.get_family() == family)
			fam.push_back(i);
	return fam;
}
