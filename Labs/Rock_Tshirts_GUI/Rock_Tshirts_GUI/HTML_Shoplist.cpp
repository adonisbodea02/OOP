#include "HTML_Shoplist.h"
#include "Windows.h"
#include <fstream>

void HTML_Shop_list::write_to_file()
{
	std::ofstream out_file(this->filename);
	std::vector<Rock_Tshirt> rts = this->get_chosen_tshirts();
	out_file << "<!DOCTYPE html>\n<html>\n\t<head>\n\t\t<title>HTML_Repository</title>\n\t</head>\n\t<body>\n\t\t<table border=\"1\">\n\t\t<tr>\n\t\t\t<td>Size</td>\n\t\t\t<td>Colour</td>\n\t\t\t<td>Price</td>\n\t\t\t<td>Quantity</td>\n\t\t\t<td>Formation</td>\n\t\t\t<td>Online source</td>\n\t\t</tr>";
	for (auto rt : rts)
		rt.to_html(out_file);
	out_file << "\n\t</table>\n\t</body>\n</html>";
	out_file.close();
}

void HTML_Shop_list::display_shop_list() const
{
	ShellExecuteA(NULL, "open", "file:///A:/UBB/1st_Year/OOP/Labs/Rock_Tshirts_GUI/Rock_Tshirts_GUI/adonis.html", NULL, NULL, SW_SHOWNORMAL);
}
