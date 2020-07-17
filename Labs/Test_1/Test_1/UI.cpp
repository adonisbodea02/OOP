#include "UI.h"
#include <string>

using namespace std;

int UI::move_up()
{
	x = this->get_x_ui();
	y = this->get_y_ui();
	x--;
	return this->ctrl.move_robot(x, y);
}

int UI::move_down()
{
	x = this->get_x_ui();
	y = this->get_y_ui();
	x++;
	return this->ctrl.move_robot(x, y);
}

int UI::move_right()
{
	x = this->get_x_ui();
	y = this->get_y_ui();
	y++;
	return this->ctrl.move_robot(x, y);
}

int UI::move_left()
{
	x = this->get_x_ui();
	y = this->get_y_ui();
	y--;
	return this->ctrl.move_robot(x, y);
}

void UI::show_tiles()
{

	for (auto i : this->ctrl.get_tiles_ctrl())
		cout << "x: " << i.get_x() << "  y: " << i.get_y() << "  status: " << i.get_status() <<"\n";

	for (auto i : this->ctrl.filter_cleaned_tiles())
		cout << "x: " << i.get_x() << "  y: " << i.get_y() << "\n";
	cout << this->ctrl.get_percentage() * 100 << "\n";
}

void UI::print_menu()
{
	cout << "1.Give positions for the robot. " << "\n";
	cout << "2.Move the robot. " << "\n";
	cout << "3.Get the cleaned tiles and their percentage from the total. " << "\n";
	cout << "4.Exit. " << "\n";
}

void UI::start()
{
	while (true)
	{
		int command;
		this->print_menu();
		cout << "Please give a command:" << "\n";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		if (command == 1)
		{
			int i = 0;;
			int j = 0;
			cout << "Give i coordinate:" << "\n";
			cin >> i;
			cin.ignore();
			cout << "Give j coordinate:" << "\n";
			cin >> j;
			cin.ignore();
			if (i > 10 || i < 0 || j > 10 || j < 0)
				cout << "The coordinates are not good!" << "\n";
			else
			{
				this->x = i;
				this->y = j;
				cout << "Good coordinates!" << "\n";
			}
		}
		if (command == 2)
		{
			cout << "Please give a direction(1 for up, 2 for down, 3 for left, 4 for right): " << "\n";
			int dir;
			cin >> dir;
			cin.ignore();
			if (dir == 1)
				if (this->move_up() == 1)
				{
					cout << "The tile was cleaned!" << endl;
					int j = this->x;
					//j--;
					//this->x = j;
					cout << "x: " << this->x << "  y: " << this->y << "\n";
				}
				else
					cout << "Invalid move!" << endl;
			if (dir == 2)
				if (this->move_down() == 1)
				{
					cout << "The tile was cleaned!" << endl;
					cout << "x: " << this->x << "  y: " << this->y << "\n";
				}
				else
					cout << "Invalid move!" << endl;
			if (dir == 3)
				if (this->move_left() == 1)
				{
					cout << "The tile was cleaned!" << endl;
					cout << "x: " << this->x << "  y: " << this->y << "\n";
				}
				else
					cout << "Invalid move!" << endl;
			if (dir == 4)
				if (this->move_right() == 1)
				{
					cout << "The tile was cleaned!" << endl;
					cout << "x: " << this->x << "  y: " << this->y << "\n";
				}
				else
					cout << "Invalid move!" << endl;
		}
		if (command == 3)
			this->show_tiles();

	}
}