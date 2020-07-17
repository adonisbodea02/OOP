#include "ShopList.h"

Shop_list::Shop_list()
{
	this->current = 0;
}

void Shop_list::set_tshirts(std::vector<Rock_Tshirt> v)
{
	this->tshirts = v;
}

Rock_Tshirt Shop_list::get_current_tshirt()
{
	if (this->current == this->tshirts.size())
		this->current = 0;
	std::vector<Rock_Tshirt> v = this->tshirts;
	return v.at(current);
}

void Shop_list::add_chosen_tshirt(Rock_Tshirt rt)
{
	std::vector<Rock_Tshirt>::iterator it;
	it = std::find_if(this->chosen_tshirts.begin(), this->chosen_tshirts.end(), [&](Rock_Tshirt r) {return r.get_ID() == rt.get_ID(); });
	if (it == this->chosen_tshirts.end())
	{
		rt.set_quantity(1);
		this->chosen_tshirts.push_back(rt);
	}
	else
	{
		int q = this->chosen_tshirts.at(it - this->chosen_tshirts.begin()).get_quantity();
		q++;
		this->chosen_tshirts.at(it - this->chosen_tshirts.begin()).set_quantity(q);
	}
}

Rock_Tshirt Shop_list::next()
{
	if (this->tshirts.size() == 0)
		return Rock_Tshirt{};
	this->current++;
	Rock_Tshirt rt = this->get_current_tshirt();
	rt.display();
	return rt;
}

bool Shop_list::is_empty()
{
	return this->tshirts.size() == 0;
}