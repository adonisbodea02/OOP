#include "UI.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

UI* create_ui(MedCtrl* ctrl) {
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = ctrl;
	return ui;
}

void print_menu()
{
	printf("1. Add a product \n");
	printf("2. Delete a product \n");
	printf("3. Update the price of a product \n");
	printf("4. Update the quantity of a product \n");
	printf("5. Filter the products by string \n");
	printf("6. Filter the products by price \n");
	printf("7. List 'short supply' products \n");
	printf("8. List all products \n");
	printf("9. Undo the last operation \n");
	printf("10. Redo the last undo \n");
	printf("11. Filter by medication name \n");
	printf("0. Exit \n");
}

int valid_command(int command)
{
	if (command >= 0 && command <= 11)
		return 1;
	return 0;
}

int read_integer_number(const char* message) {
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;
	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);
		r = sscanf(s, "%d", &res);
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number! \n");
	}
	return res;
}

int add_med_ui(UI* ui) {
	char name[50];
	int concentration = 0, price = 0, quantity = 0;
	printf("Please give a name: ");
	scanf("%s", name);
	concentration = read_integer_number("Please give a concentration : ");
	quantity = read_integer_number("Please give a quantity : ");
	price = read_integer_number("Please give a price : ");

	Medication* med;
	med = create_medication(name, concentration, quantity, price);

	int res = add_med_ctrl(ui->ctrl, med);
	if (res == 0)
		free(med);
	return res;
}

int del_med_ui(UI* ui) {
	char name[50];
	int concentration = 0;
	printf("Please give a name: ");
	scanf("%s", name);
	concentration = read_integer_number("Please give a concentration : ");

	return delete_med_ctrl(ui->ctrl, name, concentration);
}

int update_med_quantity_ui(UI* ui) {
	char name[50];
	int concentration = 0, quantity = 0;
	printf("Please give a name: ");
	scanf("%s", name);
	concentration = read_integer_number("Please give a concentration : ");
	quantity = read_integer_number("Please give a quantity : ");

	return update_med_quantity_ctrl(ui->ctrl, name, concentration, quantity);
}

int update_med_price_ui(UI* ui) {
	char name[50];
	int concentration = 0, price = 0;
	printf("Please give a name: ");
	scanf("%s", name);
	concentration = read_integer_number("Please give a concentration : ");
	price = read_integer_number("Please give a price : ");

	return update_med_price_ctrl(ui->ctrl, name, concentration, price);
}

void filter_ui(UI* ui) {
	char String[255];
	printf("Please give a string: ");
	char c;
	int i = 0;
	getchar();
	while(c = getchar())
	{
		if (c == '\n')
			break;
		else
		{
			String[i] = c;
			i++;
		}
	}
	String[i] = 0;
	
	int kind = read_integer_number("Choose the type of sorting, 1 - for ascending alphabetically, 2 - for descending based on concentration: ");
	while (kind != 1 && kind != 2)
	{
		printf("Please choose a valid option!\n");
		kind = read_integer_number("Choose the type of sorting, 1 - for ascending, 2 - for descending: ");
	}

	Dynamic_Array* temp_array = filter(ui->ctrl, String, kind);

	if (get_length(temp_array) > 0)
		for (int i = 0; i < get_length(temp_array); i++)
			printf("%s - concentration: %d quantity: %d price: %d\n", get_name(temp_array->elements[i]), get_concentration(temp_array->elements[i]), get_quantity(temp_array->elements[i]), get_price(temp_array->elements[i]));
	else
		printf("No products with this string in them!\n");

	free(temp_array->elements);
	free(temp_array);
}

void filter_medication(UI* ui) {
	char String[255];
	printf("Please give a string: ");
	char c;
	int i = 0;
	getchar();
	while (c = getchar())
	{
		if (c == '\n')
			break;
		else
		{
			String[i] = c;
			i++;
		}
	}
	String[i] = 0;

	Dynamic_Array* temp_array = filter_medication_ctrl(ui->ctrl, String);

	if (get_length(temp_array) > 0)
		for (int i = 0; i < get_length(temp_array); i++)
			printf("%s - concentration: %d quantity: %d price: %d\n", get_name(temp_array->elements[i]), get_concentration(temp_array->elements[i]), get_quantity(temp_array->elements[i]), get_price(temp_array->elements[i]));
	else
		printf("No products with this name!\n");

	free(temp_array->elements);
	free(temp_array);
}

void filter_price_ui(UI* ui) {
	int price = 0;
	price = read_integer_number("Please give a price : ");
	Dynamic_Array* temp_array = filter_price(ui->ctrl, price);

	if (get_length(temp_array) > 0)
		for (int i = 0; i < get_length(temp_array); i++)
			printf("%s - concentration: %d quantity: %d price: %d\n", get_name(temp_array->elements[i]), get_concentration(temp_array->elements[i]), get_quantity(temp_array->elements[i]), get_price(temp_array->elements[i]));
	else
		printf("No products with this price!\n");

	free(temp_array->elements);
	free(temp_array);
}

void short_supply_ui(UI* ui) {
	int quantity = 0;
	quantity = read_integer_number("Please give a quantity : ");

	int kind = read_integer_number("Choose the type of sorting, 1 - for ascending, 2 - for descending: ");
	while (kind != 1 && kind != 2)
	{
		printf("Please choose a valid option!\n");
		kind = read_integer_number("Choose the type of sorting, 1 - for ascending, 2 - for descending: ");
	}
	
	Dynamic_Array* temp_array = short_supply(ui->ctrl, quantity, kind);

	if (get_length(temp_array) > 0)
		for (int i = 0; i < get_length(temp_array); i++)
			printf("%s - concentration: %d quantity: %d price: %d\n", get_name(temp_array->elements[i]), get_concentration(temp_array->elements[i]), get_quantity(temp_array->elements[i]), get_price(temp_array->elements[i]));
	else
		printf("No products with the quantity less than the given one!\n");

	free(temp_array->elements);
	free(temp_array);
}


void print_all(UI* ui) {
	for (int i = 0; i < get_length_ctrl(ui->ctrl); i++)
		printf("%s - concentration: %d quantity: %d price: %d\n", get_name(ui->ctrl->repo->medications->elements[i]), get_concentration(ui->ctrl->repo->medications->elements[i]), get_quantity(ui->ctrl->repo->medications->elements[i]), get_price(ui->ctrl->repo->medications->elements[i]));
}

void delete_ui(UI* ui) {
	delete_ctrl(ui->ctrl);
	free(ui);
}

void start_ui(UI* ui) {
	while (1)
	{
		print_menu();
		int command = -1;
		command = read_integer_number("Give command: ");
		while (valid_command(command) == 0)
		{
			printf("Please give a valid command!\n");
			command = read_integer_number("Give command: ");
		}
		if (command == 0)
			break;
		if (command == 1)
		{
			int res = add_med_ui(ui);
			if (res == 1)
				printf("Product successfully added.\n");
			else
				printf("Product was not added, but its quantity modified! \n");
		}
		if (command == 2)
		{
			int res = del_med_ui(ui);
			if (res == 1)
				printf("Product successfully deleted.\n");
			else
				printf("Such a product does not exist! \n");
		}
		if (command == 4)
		{
			int res = update_med_quantity_ui(ui);
			if (res == 1)
				printf("Product successfully updated.\n");
			else
				printf("Such a product does not exist! \n");
		}
		if (command == 3)
		{
			int res = update_med_price_ui(ui);
			if (res == 1)
				printf("Product successfully updated.\n");
			else
				printf("Such a product does not exist! \n");
		}
		if (command == 5)
			filter_ui(ui);
		if (command == 6)
			filter_price_ui(ui);
		if (command == 7)
			short_supply_ui(ui);
		if (command == 8)
			print_all(ui);
		if (command == 9)
		{
			int res = undo(ui->ctrl);
			if (res == 1)
				printf("Undo was successful. \n");
			else
				printf("No more undos to be made. \n");
		}
		if (command == 10)
		{
			int res = redo(ui->ctrl);
			if (res == 1)
				printf("Redo was successful. \n");
			else
				printf("No more redos to be made. \n");
		}
		if (command == 11)
			filter_medication(ui);
	}

}