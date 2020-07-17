#include "UI.h"
#include <string>


void UI::print_menu()
{
	std::cout << "\n";
	std::cout << "1.Add an offer." << "\n";
	std::cout << "2.Delete an offer." << "\n";
	std::cout << "3.Update an offer's price." << "\n";
	std::cout << "4.Update an offer's type." << "\n";
	std::cout << "5.Filter offers by string." << "\n";
	std::cout << "0.Exit." << "\n";
}

int UI::add_offer_ui()
{
	std::cout << "Please give a type: ";
	std::string type;
	getline(std::cin, type);
	std::cout << "Please give an address: ";
	std::string address;
	getline(std::cin, address);
	std::cout << "Please give a price: ";
	int price;
	std::cin >> price;
	std::cin.ignore();
	std::cout << "Please give a type: ";
	int surface;
	std::cin >> surface;
	std::cin.ignore();
	Offer o{ type, address, surface, price };
	return this->ctrl.add_offer_ctrl(o);
}

int UI::delete_offer_ui()
{
	std::cout << "Please give an address: ";
	std::string address;
	getline(std::cin, address);
	return this->ctrl.delete_offer_ctrl(address);
}

int UI::update_offer_price_ui()
{
	std::cout << "Please give an address: ";
	std::string address;
	getline(std::cin, address);
	std::cout << "Please give a price: ";
	int price;
	std::cin >> price;
	std::cin.ignore();
	return this->ctrl.update_price_offer_ctrl(address, price);
}
int UI::update_offer_type_ui()
{
	std::cout << "Please give an address: ";
	std::string address;
	getline(std::cin, address);
	std::cout << "Please give an type: ";
	std::string type;
	getline(std::cin, type);
	return this->ctrl.update_type_offer_ctrl(address, type);
}
void UI::filter_by_string_ui()
{
	std::cout << "Please give a string: ";
	std::string s;
	getline(std::cin, s);
	std::vector<Offer> v;
	if (s.length() == 0)
		v = this->ctrl.get_repo().get_vector();
	else
		v = this->ctrl.filter_by_string_ctrl(s);
	this->print_offers(v);

}
void UI::print_offers(std::vector<Offer> v)
{
	for (auto i : v)
		std::cout << "Type: " << i.get_type() << " Address: " << i.get_address() << " Surface: " << i.get_surface() << " Price: " << i.get_price() << "\n";

}

void UI::start()
{
	while(true)
	{
		UI::print_menu();
		int command{ 0 };
		std::cout << "Input command: ";
		std::cin >> command;
		std::cin.ignore();
		if (command == 0)
			break;
		if (command == 1)
		{
			int res = this->add_offer_ui();
			if (res == 1)
				std::cout << "Succesfully added!" << "\n";
			else
				std::cout << "It already exists!" << "\n";

		}
		if (command == 2)
		{
			int res = this->delete_offer_ui();
			if (res == 1)
				std::cout << "Succesfully deleted!" << "\n";
			else
				std::cout << "It does not exist such an element!" << "\n";

		}
		if (command == 3)
		{
			int res = this->update_offer_price_ui();
			if (res == 1)
				std::cout << "Succesfully updated!" << "\n";
			else
				std::cout << "It does not exist such an element!" << "\n";

		}
		if (command == 4)
		{
			int res = this->update_offer_type_ui();
			if (res == 1)
				std::cout << "Succesfully updated!" << "\n";
			else
				std::cout << "It does not exist such an element!" << "\n";

		}
		if (command == 5)
			this->filter_by_string_ui();
	}
}