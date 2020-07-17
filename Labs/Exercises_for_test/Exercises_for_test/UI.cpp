#include "UI.h"
#include <string>
#include <algorithm>

using namespace std;

void UI::print_menu()
{
	cout << endl;
	cout << "1.Add a material. " << endl;
	cout << "2.Delete a material. " << endl;
	cout << "3.Update a material's quantity. " << endl;
	cout << "4.Print all materials. " << endl;
	cout << "5.Filter by string. " << endl;
	cout << "0.Exit " << endl;
}

int UI::add_material_ui()
{
	cout << "Please give a name: " << endl;
	std::string name;
	getline(cin, name);
	cout << "Please give a supplier: " << endl;
	std::string supplier;
	getline(cin, supplier);
	cout << "Please give a quantity: " << endl;
	int quantity;
	cin >> quantity;
	cin.ignore();
	cout << "Please give a day: " << endl;
	int day;
	cin >> day;
	cin.ignore();
	cout << "Please give a month: " << endl;
	int month;
	cin >> month;
	cin.ignore();
	cout << "Please give a year: " << endl;
	int year;
	cin >> year;
	cin.ignore();
	Date d{ day, month, year };
	Material m{ name, supplier, quantity, d };
	return this->ctrl.add_material(m);
}

int UI::delete_material_ui()
{
	cout << "Please give a name: " << endl;
	std::string name;
	getline(cin, name);
	cout << "Please give a supplier: " << endl;
	std::string supplier;
	getline(cin, supplier);
	cout << "Please give a day: " << endl;
	int day;
	cin >> day;
	cin.ignore();
	cout << "Please give a month: " << endl;
	int month;
	cin >> month;
	cin.ignore();
	int year;
	cout << "Please give a year: " << endl;
	cin >> year;
	cin.ignore();
	Date d{ day, month, year };
	return this->ctrl.delete_material(name, supplier, d);
}
int UI::update_quantity_ui()
{
	cout << "Please give a name: " << endl;
	std::string name;
	getline(cin, name);
	cout << "Please give a supplier: " << endl;
	std::string supplier;
	getline(cin, supplier);
	cout << "Please give a day: " << endl;
	int day;
	cin >> day;
	cin.ignore();
	cout << "Please give a month: " << endl;
	int month;
	cin >> month;
	cin.ignore();
	cout << "Please give a year: " << endl;
	int year;
	cin >> year;
	cin.ignore();
	cout << "Please give a new quantity: " << endl;
	int quantity;
	cin >> quantity;
	cin.ignore();
	Date d{ day, month, year };
	return this->ctrl.update_material_quantity(name, supplier, d, quantity);
}

void print_material(Material m)
{
	cout << "Name: " << m.get_name() << "  Supplier: " << m.get_supplier() << "  Quantity: " << m.get_quantity() << "  Date: " << m.get_expiry_date().get_day() << "/" << m.get_expiry_date().get_month() << "/" << m.get_expiry_date().get_year() << "\n";
}

void UI::print_materials()
{
	std::vector<Material> v = this->ctrl.get_repo().get_materials_repo();
	//for (int i = 0; i < v.size(); i++)
		//cout << "Name: " << v[i].get_name() << "  Supplier: " << v[i].get_supplier() << "  Quantity: " << v[i].get_quantity() << "  Date: " << v[i].get_expiry_date().get_day() << "/" << v[i].get_expiry_date().get_month() << "/" << v[i].get_expiry_date().get_year() << "/ \n";
	//std::for_each(v.begin(), v.end(), print_material);
	for (auto i : v)
		cout << "Name: " << i.get_name() << "  Supplier: " << i.get_supplier() << "  Quantity: " << i.get_quantity() << "  Date: " << i.get_expiry_date().get_day() << "/" << i.get_expiry_date().get_month() << "/" << i.get_expiry_date().get_year() << "\n";
}

void UI::filter_by_string_ui()
{
	cout << "Please give a string: " << endl;
	std::string name;
	getline(cin, name);
	std::vector<Material> v;
	if (name.length() == 0)
		v = this->ctrl.filter_by_expiry_date(this->ctrl.get_repo().get_materials_repo());
	else
		v = this->ctrl.filter_by_expiry_date(this->ctrl.filter_by_string(name));
	for (auto i : v)
		cout << "Name: " << i.get_name() << "  Supplier: " << i.get_supplier() << "  Quantity: " << i.get_quantity() << "  Date: " << i.get_expiry_date().get_day() << "/" << i.get_expiry_date().get_month() << "/" << i.get_expiry_date().get_year() << "\n";
}

void UI::start()
{
	while (true)
	{
		UI::print_menu();
		int command{ 0 };
		cout << "Input command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		if (command == 1)
		{
			int res = this->add_material_ui();
			if (res == 1)
				cout << "Succesfully added!" << endl;
			else
				cout << "It already exists but its quantity modified!" << endl;

		}
		if (command == 2)
		{
			int res = this->delete_material_ui();
			if (res == 1)
				cout << "Succesfully deleted!" << endl;
			else
				cout << "It does not exist such an element!" << endl;

		}
		if (command == 3)
		{
			int res = this->update_quantity_ui();
			if (res == 1)
				cout << "Succesfully updated!" << endl;
			else
				cout << "It does not exist such an element!" << endl;

		}
		if (command == 4)
			this->print_materials();
		if (command == 5)
			this->filter_by_string_ui();
	}
}