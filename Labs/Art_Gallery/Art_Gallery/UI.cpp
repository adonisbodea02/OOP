#include "UI.h"
#include <string>

using namespace std;

void UI::print_menu()
{
	cout << "1. Add a painting " << endl;
	cout << "2. Remove a painting " << endl;
	cout << "3. Move a painting " << endl;
	cout << "4. Save to a file " << endl;
	cout << "5. List all " << endl;
	cout << "6. List special " << endl;
}

void UI::add_painting()
{
	int choice;
	cout << "Choose what kind of painting: ";
	cin >> choice;
	cin.ignore();

	string title;
	cout << "Give a title: " << endl;
	getline(cin, title);

	std::string artist;
	cout << "Give an artist: " << endl;
	getline(cin, artist);

	int year;
	cout << "Give a year: ";
	cin >> year;
	cin.ignore();

	if (choice == 1)
	{
		Painting* p = new Painting(title, artist, year);
		this->c.add_painting_ctrl(p);
	}

	if (choice == 2)
	{
		double temperature;
		cout << "Give a temperature: ";
		cin >> temperature;
		cin.ignore();
		Painting *p = new Special_Painting(title, artist, year, temperature);
		this->c.add_painting_ctrl(p);
	}

}

void UI::remove_painting()
{
	string title;
	cout << "Give a title: " << endl;
	getline(cin, title);

	std::string artist;
	cout << "Give an artist: " << endl;
	getline(cin, artist);

	int year;
	cout << "Give a year: ";
	cin >> year;
	cin.ignore();
	
	this->c.delete_painting_ctrl(title, artist, year);
}

void UI::move_painting()
{
	string title;
	cout << "Give a title: " << endl;
	getline(cin, title);

	std::string artist;
	cout << "Give an artist: " << endl;
	getline(cin, artist);

	int year;
	cout << "Give a year: ";
	cin >> year;
	cin.ignore();

	this->c.move(title, artist, year);
}

void UI::save_to_file()
{
	std::string filename;
	cout << "Give a file name: " << endl;
	getline(cin, filename);

	this->c.write_ctrl(filename);
}

void UI::print_all()
{
	std::vector<Painting*> ps;
	ps = this->c.get_all_ctrl();
	for (auto i : ps)
		cout << i->to_string() << endl;
}

void UI::print_special()
{
	std::vector<Painting*> ps;
	ps = this->c.get_all_special();
	for (auto i : ps)
		cout << i->to_string() << endl;
}

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
			this->add_painting();
			break;
		case 2:
			this->remove_painting();
			break;
		case 3:
			this->move_painting();
			break;
		case 4:
			this->save_to_file();
		case 5:
			this->print_all();
			break;
		case 6:
			this->print_special();
			break;

		default:
			keepGoing = false;
			break;
		}
	}
}
