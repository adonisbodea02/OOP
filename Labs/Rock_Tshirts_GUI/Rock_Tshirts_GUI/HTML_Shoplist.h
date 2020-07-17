#pragma once
#include "File_ShopList.h"
#include <string>

class HTML_Shop_list : public File_Shop_list
{
public:
	HTML_Shop_list(const std::string& filename) : File_Shop_list{ filename } {}
	void write_to_file() override;
	void display_shop_list() const override;

};
