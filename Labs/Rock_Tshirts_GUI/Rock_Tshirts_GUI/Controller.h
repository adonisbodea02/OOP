#pragma once
#include "Repository.h"
#include "File_Repo.h"
#include "Exception_Class.h"
#include "File_ShopList.h"
#include "Undo.h"

class Controller
{
private:
	Repository & repo;
	Validator v;
	std::vector<Undo*> undos;
	std::vector<Undo*> redos;
	//File_Repo frepo;


public:
	File_Shop_list * sh;

	Controller(Repository& r, File_Shop_list* s) : repo{ r }, sh{ s } {}

	//Controller(const File_Repo& r) : frepo{ r } {}

	Repository get_repo() const { return repo; }

	int add_rock_tshirt_ctrl(const int ID, const std::string& size, const std::string& colour, int quantity, int price, const std::string& photo, const std::string& formation);

	int delete_rock_tshirt_ctrl(int id);

	int update_rock_thsirt_size_ctrl(int id, std::string& new_size);

	int update_rock_tshirt_colour_ctrl(int id, std::string& new_colour);

	int update_rock_thsirt_photo_ctrl(int id, std::string& new_photo);

	int update_rock_thsirt_price_ctrl(int id, int new_price);

	int update_rock_thsirt_quantity_ctrl(int id, int new_quantity);

	std::vector<Rock_Tshirt> filter_by_size(const std::string size);

	void undo();

	void redo();
};
