#include "UI.h"
#include <string>

using namespace std;

void UI::print_menu()
{
	cout << endl;
	cout << "1. Administrator mode." << endl;
	cout << "2. User mode." << endl;
	cout << "0. Exit" << endl;
}

void UI::print_administrator_menu()
{
	cout << "1.Add a Rock T-shirt." << endl;
	cout << "2.Delete a Rock T-shirt. :(" << endl;
	cout << "3.Update a Rock T-shirt's size." << endl;
	cout << "4.Update a Rock T-shirt's colour." << endl;
	cout << "5.Update a Rock T-shirt's quantity." << endl;
	cout << "6.Update a Rock T-shirt's price." << endl;
	cout << "7.Update a Rock T-shirt's photo ." << endl;
	cout << "8.Display all rock T-shirts." << endl;
}

int UI::add_rock_tshirt_ui()
{
	//cout << "Please give an ID: " << endl;
	int ID = 0;
	while (cout << "Please give an ID: " && !(cin >> ID)) {
		cout << "Please give a number! ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cin.get();
	std::string size_ui;
	cout << "Please give a size: " << endl;
	getline(cin, size_ui);
	std::string colour;
	cout << "Please give a colour: " << endl;
	getline(cin, colour);
	std::string photo;
	cout << "Please give a link to a photo: " << endl;
	getline(cin, photo);
	int price = 0;
	while (cout << "Please give a price: " && !(cin >> price)) {
		cout << "Please give a number! ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cin.get();
	int quantity = 0;
	while (cout << "Please give a quantity: " && !(cin >> quantity)) {
		cout << "Please give a number! ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cin.get();
	std::string formation;
	cout << "Please give the name of the rock band: " << endl;
	getline(cin, formation);
	//Rock_Tshirt rt{ ID, size_ui, colour, quantity, price, photo, formation };
	return this->ctrl.add_rock_tshirt_ctrl(ID, size_ui, colour, quantity, price, photo, formation);
}

int UI::delete_rock_thsirt_ui()
{
	int ID = 0;
	while (cout << "Please give an ID: " && !(cin >> ID)) {
		cout << "Please give a number! ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cin.get();
	return this->ctrl.delete_rock_tshirt_ctrl(ID);
}

int UI::update_rock_thsirt_size_ui()
{
	cout << "Please give an ID: " << endl;
	int ID = 0;
	while (cout << "Please give an ID: " && !(cin >> ID)) {
		cout << "Please give a number! ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cin.get();
	std::string size_ui;
	cout << "Please give a new size: " << endl;
	getline(cin, size_ui);
	return this->ctrl.update_rock_thsirt_size_ctrl(ID, size_ui);
}

int UI::update_rock_tshirt_colour_ui()
{
	cout << "Please give an ID: " << endl;
	int ID = 0;
	while (cout << "Please give an ID: " && !(cin >> ID)) {
		cout << "Please give a number! ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cin.get();
	std::string colour;
	cout << "Please give a new colour: " << endl;
	getline(cin, colour);
	return this->ctrl.update_rock_tshirt_colour_ctrl(ID, colour);
}

int UI::update_rock_thsirt_photo_ui()
{
	int ID = 0;
	while (cout << "Please give an ID: " && !(cin >> ID)) {
		cout << "Please give a number! ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cin.get();
	std::string photo;
	cout << "Please give a new link to the photo: " << endl;
	getline(cin, photo);
	return this->ctrl.update_rock_thsirt_photo_ctrl(ID, photo);
}

int UI::update_rock_thsirt_price_ui()
{
	cout << "Please give an ID: " << endl;
	int ID = 0;
	while (cout << "Please give an ID: " && !(cin >> ID)) {
		cout << "Please give a number! ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cin.get();
	int price = 0;
	while (cout << "Please give a price: " && !(cin >> price)) {
		cout << "Please give a number! ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cin.get();
	return this->ctrl.update_rock_thsirt_price_ctrl(ID, price);
}

int UI::update_rock_thsirt_quantity_ui()
{
	int ID = 0;
	while (cout << "Please give an ID: " && !(cin >> ID)) {
		cout << "Please give a number! ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cin.get();
	int quantity = 0;
	while (cout << "Please give a quantity: " && !(cin >> quantity)) {
		cout << "Please give a number! ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cin.get();
	return this->ctrl.update_rock_thsirt_quantity_ctrl(ID, quantity);
}

std::vector<Rock_Tshirt> UI::filter_by_size_ui()
{
	//cin.ignore();
	std::string size_ui;
	cout << "Please give a size: " << endl;
	getline(cin, size_ui);
	std::vector<Rock_Tshirt> v;
	if (size_ui.length() == 0)
		v = this->ctrl.get_repo().get_rock_tshirts();
	else
		v = this->ctrl.filter_by_size(size_ui);

	return v;
	/*
	Rock_Tshirt* rts = dv.get_all_elems();
	if (dv.get_size() == 0)
	{
		cout << "There are no rock t-shirts!" << endl;
		return;
	}
	for (int i = 0; i < dv.get_size(); i++)
	{
		Rock_Tshirt rt = rts[i];
		cout << rt.get_ID() << ". Rock band: " << rt.get_formation() << " Colour: " << rt.get_colour() << " Size: " << rt.get_size() << " Price: " << rt.get_price() << " Quantity: " << rt.get_quantity() << endl;
	}
	*/

}

void UI::print_all_rock_tshirts()
{
	std::vector<Rock_Tshirt> v = this->ctrl.get_repo().get_rock_tshirts();
	if (v.size() == 0)
	{
		cout << "There are no rock t-shirts!" << endl;
		return;
	}
	for (auto rt : v)
		cout << rt.get_ID() << ". Rock band: " << rt.get_formation() << " Colour: " << rt.get_colour() << " Size: " << rt.get_size() << " Price: " << rt.get_price() << " Quantity: " << rt.get_quantity() << endl;
}

void UI::print_user_menu()
{
	cout << "1. Filter the T-shirts by size " << endl;
	cout << "0. Exit" << endl;
}

void UI::print_shop_list_menu()
{
	cout << "1. Next T-shirt" << endl;
	cout << "2. Add the T-shirt to the shopping list" << endl;
	cout << "3. See the shopping list" << endl;
	cout << "0. Exit" << endl;
}

void UI::shop_list_ui()
{
	std::vector<Rock_Tshirt> v = this->filter_by_size_ui();
	this->ctrl.sh->set_tshirts(v);
	Rock_Tshirt rt = this->ctrl.sh->get_current_tshirt();
	this->print_shop_list_menu();
	cout << rt.get_ID() << ". Rock band: " << rt.get_formation() << " Colour: " << rt.get_colour() << " Size: " << rt.get_size() << " Price: " << rt.get_price() << endl;
	rt.display();
	int total_price = 0;
	while (true)
	{
		int command = 0;
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 1)
		{
			rt = this->ctrl.sh->next();
			this->print_shop_list_menu();
			cout << rt.get_ID() << ". Rock band: " << rt.get_formation() << " Colour: " << rt.get_colour() << " Size: " << rt.get_size() << " Price: " << rt.get_price() << endl;
		}
		if (command == 2)
		{
			this->ctrl.sh->add_chosen_tshirt(rt);
			total_price += rt.get_price();
			int q = rt.get_quantity();
			q--;
			this->ctrl.update_rock_thsirt_quantity_ctrl(rt.get_ID(), q);
			cout << "Total price: " << total_price << endl;
			this->print_shop_list_menu();
		}
		if (command == 3)
		{
			//for (auto i : this->ctrl.sh->get_chosen_tshirts())
				//cout << i.get_ID() << ". Rock band: " << i.get_formation() << " Colour: " << i.get_colour() << " Size: " << i.get_size() << " Price: " << i.get_price() << " Quantity: " << i.get_quantity() << endl;
			//cout << "Total price: " << total_price << endl;
			this->ctrl.sh->write_to_file();
			this->ctrl.sh->display_shop_list();
			this->print_shop_list_menu();
		}
		if (command == 0)
			break;
	}



}

void UI::start()
{
	while (true)
	{
		try {
			UI::print_menu();
			int command{ 0 };
			cout << "Input the command: ";
			cin >> command;
			cin.ignore();
			if (command == 0)
				break;
			if (command == 1)
			{
				while (true)
				{
					UI::print_administrator_menu();
					int command_adm{ 0 };
					cout << "Input the command: ";
					cin >> command_adm;
					if (command_adm == 0)
						break;
					if (command_adm == 1)
					{
						int res = this->add_rock_tshirt_ui();
						if (res == 1)
							cout << "Succesfully added" << endl;
						else
							cout << "It already exists!" << endl;
					}
					if (command_adm == 2)
					{
						int res = this->delete_rock_thsirt_ui();
						if (res == 1)
							cout << "Succesfully removed" << endl;
						else
							cout << "It does not exist!" << endl;
					}
					if (command_adm == 3)
					{
						int res = this->update_rock_thsirt_size_ui();
						if (res == 1)
							cout << "Succesfully updated" << endl;
						else
							cout << "It does not exist!" << endl;
					}
					if (command_adm == 4)
					{
						int res = this->update_rock_tshirt_colour_ui();
						if (res == 1)
							cout << "Succesfully updated" << endl;
						else
							cout << "It does not exist!" << endl;
					}
					if (command_adm == 5)
					{
						int res = this->update_rock_thsirt_quantity_ui();
						if (res == 1)
							cout << "Succesfully updated" << endl;
						else
							cout << "It does not exist!" << endl;
					}
					if (command_adm == 6)
					{
						int res = this->update_rock_thsirt_price_ui();
						if (res == 1)
							cout << "Succesfully updated" << endl;
						else
							cout << "It does not exist!" << endl;
					}
					if (command_adm == 7)
					{
						int res = this->update_rock_thsirt_photo_ui();
						if (res == 1)
							cout << "Succesfully updated" << endl;
						else
							cout << "It does not exist!" << endl;
					}
					if (command_adm == 8)
						this->print_all_rock_tshirts();
				}
			}
				if (command == 2)
				{
					while (true)
					{
						this->print_user_menu();
						int command_user{ 0 };
						cout << "Input the command: ";
						cin >> command_user;
						cin.ignore();
						if (command_user == 1)
							this->shop_list_ui();
						if (command_user == 0)
							break;
					}
				}
		}
		catch (Controller_Error &error)
		{
			cout << error.get_message();
		}
		catch (Rock_Tshirt_Error &error2)
		{
			cout << error2.get_message();
		}

	}
}
