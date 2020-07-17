#include "Repository.h"
#include <string>

using namespace std;

int Repository::find_by_id(int id)
{
	std::vector<Rock_Tshirt>::iterator it;
	it = std::find_if(this->rock_tshirts.begin(), this->rock_tshirts.end(), [&](Rock_Tshirt rt) {return rt.get_ID() == id; });
	if (it != this->rock_tshirts.end())
		return it - this->rock_tshirts.begin();

	return -1;
}

int Repository::add_rock_tshirt(Rock_Tshirt& rt)
{
	int res = this->find_by_id(rt.get_ID());
	if (res == -1)
	{
		this->rock_tshirts.push_back(rt);
		return 1;
	}
	return 0;
}

int Repository::delete_rock_thsirt(int id)
{
	std::vector<Rock_Tshirt>::iterator it;
	it = std::find_if(this->rock_tshirts.begin(), this->rock_tshirts.end(), [&](Rock_Tshirt rt) {return rt.get_ID() == id; });
	if (it != this->rock_tshirts.end())
	{
		this->rock_tshirts.erase(it);
		return 1;
	}
	return 0;
}

int Repository::update_rock_thsirt_size(int id, std::string& new_size)
{
	int res = this->find_by_id(id);
	if (res >= 0)
	{
		this->rock_tshirts.at(res).set_size(new_size);
		return 1;
	}
	return 0;
}

int Repository::update_rock_thsirt_colour(int id, std::string& new_colour)
{
	int res = this->find_by_id(id);
	if (res >= 0)
	{
		this->rock_tshirts.at(res).set_colour(new_colour);
		return 1;
	}
	return 0;
}

int Repository::update_rock_thsirt_photo(int id, std::string& new_photo)
{
	int res = this->find_by_id(id);
	if (res >= 0)
	{
		this->rock_tshirts.at(res).set_photo(new_photo);
		return 1;
	}
	return 0;
}

int Repository::update_rock_thsirt_price(int id, int new_price)
{
	int res = this->find_by_id(id);
	if (res >= 0)
	{
		this->rock_tshirts.at(res).set_price(new_price);
		return 1;
	}
	return 0;
}

int Repository::update_rock_thsirt_quantity(int id, int new_quantity)
{
	int res = this->find_by_id(id);
	if (res >= 0)
	{
		this->rock_tshirts.at(res).set_quantity(new_quantity);
		return 1;
	}
	return 0;
}

void Repository::populate_from_file(std::string file_name)
{

}

