#include "Repository.h"

Dwelling RealEstateAgency::add_dwelling(std::string type, double price, bool is_profitable)
{
	Dwelling d(type, price, is_profitable);
	this->dwellings.push_back(d);
	return d;
}

void RealEstateAgency::removeClient(std::string name)
{
	//std::vector<Client*>::iterator it;
	//it = std::find(this->clients.begin(), this->clients.end(), [&](Client* c) {return (c->get_name() == name); });
	//if (it != this->clients.end())
	//	this->clients.erase(it);
}

std::vector<Client*> RealEstateAgency::get_interested(Dwelling d)
{
	std::vector<Client*> ic;
	for (auto i : clients)
	{
		if (i->is_interested(d))
			ic.push_back(i);
	}
	return ic;
}

void RealEstateAgency::write_to_file(std::string filename)
{
	std::ofstream fout(filename, std::ios::out | std::ios::trunc);
	std::for_each(this->clients.begin(), this->clients.end(), [&fout](Client* c) {fout << c->to_string() << '\n'; });
	fout.close();
}
