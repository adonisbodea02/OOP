#include "File_Repo.h"
#include "Exception_Class.h"

File_Repo::File_Repo(std::string filename) : Repository()
{
	this->filename = filename;
	this->read();
}

File_Repo::~File_Repo()
{
	this->write();
}

void File_Repo::write()
{
	std::ofstream fout(this->filename, std::ios::out | std::ios::trunc);

	std::for_each(this->rock_tshirts.begin(), this->rock_tshirts.end(), [&fout](const Rock_Tshirt& rt) {fout << rt << '\n'; });
	fout.close();
}

void File_Repo::read()
{
	std::ifstream fin(this->filename, std::ios::in);
	if (!fin.is_open())
		throw File_Error("Could not open file!");
	this->rock_tshirts.clear();

	//std::string params, id, size, colour, quantity, price, photo, formation;
	Rock_Tshirt rt{};
	while (fin >> rt)
	{
		this->add_rock_tshirt(rt);
	}

	fin.close();
}
