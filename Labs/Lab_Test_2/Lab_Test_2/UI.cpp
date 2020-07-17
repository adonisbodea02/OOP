#include "UI.h"

void UI::run()
{
	bool keepGoing = true;
	while (keepGoing)
	{
		this->print_menu();
		int command{};
		cout << "Input option: ";
		cin >> command;
		cin.ignore();

		switch (command)
		{
		case 1:
			this->remove_client_ui();
			break;
		case 2:
			this->add_dwelling_ui();
			break;
		case 3:
			this->write_to_file_ui();
			break;
		case 4:
			this->show_clients();
			break;

		default:
			keepGoing = false;
			break;
		}
	}
}

void UI::print_menu()
{
	cout << "1.Remove a client " << endl;
	cout << "2. Add a dwelling " << endl;
	cout << "3. Write to file " << endl;
	cout << "4. List clients." << endl;
	cout << "5. List dwellings. " << endl;
}

void UI::add_dwelling_ui()
{
	std::string type;
	cout << "Give title: ";
	getline(cin, type);

	double price;
	cout << "Give price: ";
	cin >> price;
	cin.ignore();

	bool is;
	cout << "Give profitability: ";
	cin >> is;
	cin.ignore();

	Dwelling d;

	d = this->r.add_dwelling(type, price, is);
	std::vector<Client*> c;
	c = this->r.get_interested(d);
	for (auto i : c)
		cout << i->to_string() << endl;
}

void UI::remove_client_ui()
{
	std::string name;
	cout << "Give name: ";
	getline(cin, name);

	this->r.removeClient(name);
}

void UI::write_to_file_ui()
{
	std::string filename;
	cout << "Give filename: ";
	getline(cin, filename);

	this->r.write_to_file(filename);
}

void UI::show_clients()
{
	std::vector<Client*> c;
	c = this->r.get_clients();
	for (auto i : c)
		cout << i->to_string() << endl;
}
