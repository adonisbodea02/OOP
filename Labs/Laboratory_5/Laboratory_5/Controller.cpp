#include "Controller.h"

int Controller::add_rock_tshirt_ctrl(const int ID, const std::string& size, const std::string& colour, int quantity, int price, const std::string& photo, const std::string& formation)
{
	v.validate_rock_tshirt(ID, size, colour, quantity, price, photo, formation);
	Rock_Tshirt rt{ ID, size, colour, quantity, price, photo, formation };
	return this->repo.add_rock_tshirt(rt);
}

int Controller::delete_rock_tshirt_ctrl(int id)
{
	return this->repo.delete_rock_thsirt(id);
}

int Controller::update_rock_thsirt_size_ctrl(int id, std::string& new_size)
{
	return this->repo.update_rock_thsirt_size(id, new_size);
}

int Controller::update_rock_tshirt_colour_ctrl(int id, std::string& new_colour)
{
	return this->repo.update_rock_thsirt_colour(id, new_colour);
}

int Controller::update_rock_thsirt_photo_ctrl(int id, std::string& new_photo)
{
	return this->repo.update_rock_thsirt_photo(id, new_photo);
}

int Controller::update_rock_thsirt_price_ctrl(int id, int new_price)
{
	return this->repo.update_rock_thsirt_price(id, new_price);
}

int Controller::update_rock_thsirt_quantity_ctrl(int id, int new_quantity)
{
	return this->repo.update_rock_thsirt_quantity(id, new_quantity);
}

std::vector<Rock_Tshirt> Controller::filter_by_size(const std::string size)
{
	std::vector<Rock_Tshirt> v = this->repo.get_rock_tshirts();
	std::vector<Rock_Tshirt> v2(v.size());
	std::vector<Rock_Tshirt>::iterator it = std::copy_if(v.begin(), v.end(), v2.begin(), [&](Rock_Tshirt rt) {return rt.get_size() == size; });
	v2.resize(std::distance(v2.begin(), it));
	return v2;
}