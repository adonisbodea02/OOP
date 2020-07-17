#include "CVS_ShopList.h"

void CVS_Shop_list::write_to_file()
{
	std::ofstream out_file(this->filename);
	std::vector<Rock_Tshirt> rt = this->get_chosen_tshirts();
	for (auto r : rt)
		out_file << r << std::endl;
}

void CVS_Shop_list::display_shop_list() const
{
	system(this->filename.c_str());
}
