#pragma once
#include "ShopList.h"

class File_Shop_list : public Shop_list
{
protected:
	std::string filename;

public:
	File_Shop_list(const std::string& filename);
	virtual ~File_Shop_list() {}

	virtual void write_to_file() = 0;
	virtual void display_shop_list() const = 0;
};