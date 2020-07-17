#include "Controller.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
function which creates a pointer to a newly created controller;
Input: MedRepo pointer;
Output: MedCtrl pointer;
*/
MedCtrl* create_ctrl(MedRepo* repo, Operation_Stack* undo_st, Operation_Stack* redo_st) {
	MedCtrl* ctrl = (MedCtrl*)malloc(sizeof(MedCtrl));
	ctrl->repo = repo;
	ctrl->undo_stack = undo_st;
	ctrl->redo_stack = redo_st;
	return ctrl;
}

/*
function which deletes/frees a controller;
Input: MedCtrl pointer;
Output: none;
*/
void delete_ctrl(MedCtrl* ctrl) {
	delete_repo(ctrl->repo);
	destroy_stack(ctrl->undo_stack);
	destroy_stack(ctrl->redo_stack);
	free(ctrl);
}

/*
function which adds an element (medication) to the repo of the controller and records it if it was successful for undo;
it also clears the redo stack
Input: pointer to the controller;
pointer to the medication to be added
Output: int type;
more precisely 1 if the operation was successful and 0 otherwise;
*/
int add_med_ctrl(MedCtrl* ctrl, Medication* med) {
	int res = add_med_repo(ctrl->repo, med);
	if (res == 1)
	{
		Operation* oper = create_operation(med, "add");
		push(ctrl->undo_stack, oper);
		destroy_operation(oper);
		while (is_empty(ctrl->redo_stack) != 1)
			destroy_operation(pop(ctrl->redo_stack));
	}
	return res;
}

/*
function which deletes an element (medication) from the repo of the controller and records it if it was successful for undo;
it also clears the redo stack;
Input: pointer to the ctrl;
char array which represents the name;
int which represent concentration
Output: int type;
more precisely 1 if the operation was successful and 0 otherwise;
*/
int delete_med_ctrl(MedCtrl* ctrl, char name[], int concentration) {
	int res = find_pos_med(ctrl->repo, name, concentration);
	if (res > -1)
	{
		Medication* med = copy_med(get(ctrl->repo->medications, res));
		Operation* oper = create_operation(med, "delete");
		push(ctrl->undo_stack, oper);
		destroy_operation(oper);
		delete_medication(med);
		while (is_empty(ctrl->redo_stack) != 1)
			destroy_operation(pop(ctrl->redo_stack));
	}
	return delete_med_repo(ctrl->repo, name, concentration);
}

/*
function which updates an element (medication) from the repo of the controller and records it if it was successful for undo;
it also clears the redo stack;
Input: pointer to the ctrl;
char array which represents the name;
int which represent concentration;
int which represents the new quantity;
Output: int type;
more precisely 1 if the operation was successful and 0 otherwise;
*/
int update_med_quantity_ctrl(MedCtrl* ctrl, char name[], int concentration, int new_quantity) {
	int res = find_pos_med(ctrl->repo, name, concentration);
	if (res > -1)
	{
		Medication* med = copy_med(get(ctrl->repo->medications, res));
		Operation* oper = create_operation(med, "update_quantity");
		push(ctrl->undo_stack, oper);
		destroy_operation(oper);
		delete_medication(med);
		while (is_empty(ctrl->redo_stack) != 1)
			destroy_operation(pop(ctrl->redo_stack));
	}
	return update_med_quantity_repo(ctrl->repo, name, concentration, new_quantity);
}

/*
void undo(int ..){
	please undo
		no bugs
		tree style redo as well
		thanks
		return pwp;
}
*/

/*
function which updates an element (medication) from the repo of the controller and records it if it was successful for undo;
it also clears the redo stack;
Input: pointer to the ctrl;
char array which represents the name;
int which represent concentration;
int which represents the new price;
Output: int type;
more precisely 1 if the operation was successful and 0 otherwise;
*/
int update_med_price_ctrl(MedCtrl* ctrl, char name[], int concentration, int new_price) {
	int res = find_pos_med(ctrl->repo, name, concentration);
	if (res > -1)
	{
		Medication* med = copy_med(get(ctrl->repo->medications, res));
		Operation* oper = create_operation(med, "update_price");
		push(ctrl->undo_stack, oper);
		destroy_operation(oper);
		delete_medication(med);
		while (is_empty(ctrl->redo_stack) != 1)
			destroy_operation(pop(ctrl->redo_stack));
	}
	return update_med_price_repo(ctrl->repo, name, concentration, new_price);
}

/*
function which undoes the last operation done to the repo of the controller and records it if it was successful for redo;
Input: pointer to the ctrl;
Output: int type;
more precisely 1 if the operation was successful and 0 otherwise;
*/
int undo(MedCtrl* ctrl) {
	if (is_empty(ctrl->undo_stack))
		return 0;

	Operation* oper = pop(ctrl->undo_stack);

	if (strcmp(get_operation_type(oper), "add") == 0)
	{
		Medication* med = get_medication_stack(oper);
		char name[50];
		int concentration = get_concentration(med);
		strcpy(name, get_name(med));
		delete_med_repo(ctrl->repo, name, concentration);
		Operation* oper2 = create_operation(med, "delete");
		push(ctrl->redo_stack, oper2);
		destroy_operation(oper2);

	}
	else
		if (strcmp(get_operation_type(oper), "delete") == 0)
		{
			Medication* med = copy_med(get_medication_stack(oper));
			add_med_repo(ctrl->repo, med);
			Operation* oper2 = create_operation(med, "add");
			push(ctrl->redo_stack, oper2);
			destroy_operation(oper2);
		}
		else
			if (strcmp(get_operation_type(oper), "update_price") == 0)
			{
				//int price = get_price(get(ctrl->repo->medications, find_pos_med(ctrl->repo, get_name(med), get_concentration(med))));
				Medication* med = get_medication_stack(oper);
				int price = get_price(get(ctrl->repo->medications, find_pos_med(ctrl->repo, get_name(med), get_concentration(med))));
				update_med_price_repo(ctrl->repo, get_name(med), get_concentration(med), get_price(med));
				set_price(med, price);
				Operation* oper2 = create_operation(med, "update_price");
				push(ctrl->redo_stack, oper2);
				destroy_operation(oper2);
			}
			else
				if (strcmp(get_operation_type(oper), "update_quantity") == 0)
				{
					Medication* med = get_medication_stack(oper);
					int quantity = get_quantity(get(ctrl->repo->medications, find_pos_med(ctrl->repo, get_name(med), get_concentration(med))));
					update_med_quantity_repo(ctrl->repo, get_name(med), get_concentration(med), get_price(med));
					set_quantity(med, quantity);
					Operation* oper2 = create_operation(med, "update_quanitity");
					push(ctrl->redo_stack, oper2);
					destroy_operation(oper2);
				}

	destroy_operation(oper);
	return 1;
}

int get_length_ctrl(MedCtrl* ctrl) {
	get_length_repo(ctrl->repo);
}

/*
function which redoes the last operation done to the repo of the controller and records it if it was successful for undo;
Input: pointer to the ctrl;
Output: int type;
more precisely 1 if the operation was successful and 0 otherwise;
*/
int redo(MedCtrl* ctrl) {
	if (is_empty(ctrl->redo_stack))
		return 0;

	Operation* oper = pop(ctrl->redo_stack);

	if (strcmp(get_operation_type(oper), "add") == 0)
	{
		Medication* med = get_medication_stack(oper);
		char name[50];
		int concentration = get_concentration(med);
		strcpy(name, get_name(med));
		delete_med_repo(ctrl->repo, name, concentration);
		Operation* oper2 = create_operation(med, "delete");
		push(ctrl->undo_stack, oper2);
		destroy_operation(oper2);

	}
	else
		if (strcmp(get_operation_type(oper), "delete") == 0)
		{
			Medication* med = copy_med(get_medication_stack(oper));
			add_med_repo(ctrl->repo, med);
			Operation* oper2 = create_operation(med, "add");
			push(ctrl->undo_stack, oper2);
			destroy_operation(oper2);
		}
		else
			if (strcmp(get_operation_type(oper), "update_price") == 0)
			{
				//int price = get_price(get(ctrl->repo->medications, find_pos_med(ctrl->repo, get_name(med), get_concentration(med))));
				Medication* med = get_medication_stack(oper);
				int price = get_price(get(ctrl->repo->medications, find_pos_med(ctrl->repo, get_name(med), get_concentration(med))));
				update_med_price_repo(ctrl->repo, get_name(med), get_concentration(med), get_price(med));
				set_price(med, price);
				Operation* oper2 = create_operation(med, "update_price");
				push(ctrl->undo_stack, oper2);
				destroy_operation(oper2);
			}
			else
				if (strcmp(get_operation_type(oper), "update_quantity") == 0)
				{
					Medication* med = get_medication_stack(oper);
					int quantity = get_quantity(get(ctrl->repo->medications, find_pos_med(ctrl->repo, get_name(med), get_concentration(med))));
					update_med_quantity_repo(ctrl->repo, get_name(med), get_concentration(med), get_price(med));
					set_quantity(med, quantity);
					Operation* oper2 = create_operation(med, "update_quanitity");
					push(ctrl->undo_stack, oper2);
					destroy_operation(oper2);
				}

	destroy_operation(oper);
	return 1;
}

/*
function which returns a list of medications filtered by a certain string, ordered alphabetically or descendingly based on the concentration;
Input: MedCtrl pointer;
	   char array
	   int kind
Output: MedRepo pointer;
*/
Dynamic_Array* filter(MedCtrl* ctrl, char String[], int kind) {

	Dynamic_Array* temp_array = create_dynamic_array(ctrl->repo->medications->capacity, &delete_medication);
	for (int i = 0; i < get_length_ctrl(ctrl); i++)
		if (strstr(get_name(get(ctrl->repo->medications, i)), String) != NULL)
			add(temp_array, get(ctrl->repo->medications, i));

	int pos = 0;
	Medication* temp;
	if(kind == 1)
		while(pos < get_length(temp_array))
		{
			if (pos == 0 || strcmp(get_name(temp_array->elements[pos]),get_name(temp_array->elements[pos-1])) >= 0)
				pos = pos + 1;
			else
			{
				temp = get(temp_array, pos);
				temp_array->elements[pos] = temp_array->elements[pos - 1];
				temp_array->elements[pos - 1] = temp;

				pos = pos - 1;
			}
		}
	else
		while (pos < get_length(temp_array))
		{
			if (pos == 0 || get_concentration(get(temp_array, pos)) >= get_concentration(get(temp_array, pos-1)))
				pos = pos + 1;
			else
			{
				temp = get(temp_array, pos);
				temp_array->elements[pos] = temp_array->elements[pos - 1];
				temp_array->elements[pos - 1] = temp;

				pos = pos - 1;
			}
		}

	return temp_array;
}

/*
function which returns a list of medications filtered by a certain price;
Input: MedCtrl pointer;
	   int price;
Output: MedRepo pointer;
*/
Dynamic_Array* filter_price(MedCtrl* ctrl, int price) {

	Dynamic_Array* temp_array = create_dynamic_array(ctrl->repo->medications->capacity, &delete_medication);
	for (int i = 0; i < get_length_ctrl(ctrl); i++)
		if (get_price(get(ctrl->repo->medications, i)) == price)
			add(temp_array, get(ctrl->repo->medications, i));

	int pos = 0;
	Medication* temp;

	return temp_array;
}

/*
function which returns a list of medications whose quantities are less than a certain quantity in ascending or descending order;
Input: MedCtrl pointer;
	   int quantity;
	   int kind;
Output: MedRepo pointer;
*/
Dynamic_Array* short_supply(MedCtrl* ctrl, int quantity, int kind) {

	Dynamic_Array* temp_array = create_dynamic_array(ctrl->repo->medications->capacity, &delete_medication);
	for (int i = 0; i < get_length_ctrl(ctrl); i++)
		if (get_quantity(get(ctrl->repo->medications, i)) < quantity)
			add(temp_array, get(ctrl->repo->medications, i));

	int pos = 0;
	Medication* temp;
	if (kind == 1)
		while (pos < get_length(temp_array))
		{
			if (pos == 0 || get_quantity(temp_array->elements[pos]) >= get_quantity(temp_array->elements[pos-1]))
				pos = pos + 1;
			else
			{
				temp = get(temp_array, pos);
				temp_array->elements[pos] = temp_array->elements[pos - 1];
				temp_array->elements[pos - 1] = temp;

				pos = pos - 1;
			}
		}
	else
		while (pos < get_length(temp_array))
		{
			if (pos == 0 || get_quantity(temp_array->elements[pos]) <= get_quantity(temp_array->elements[pos - 1]))
				pos = pos + 1;
			else
			{
				temp = get(temp_array, pos);
				temp_array->elements[pos] = temp_array->elements[pos - 1];
				temp_array->elements[pos - 1] = temp;

				pos = pos - 1;
			}
		}

	return temp_array;
}

/*
function which returns a list of medications filtered by a certain name, ordered ascendingly based on the concentration;
Input: MedCtrl pointer;
char array
Output: dynamic array pointer;
*/
Dynamic_Array* filter_medication_ctrl(MedCtrl* ctrl, char String[]) {

	Dynamic_Array* temp_array = create_dynamic_array(ctrl->repo->medications->capacity, &delete_medication);
	for (int i = 0; i < get_length_ctrl(ctrl); i++)
		if (strcmp(get_name(get(ctrl->repo->medications, i)), String) == 0)
			add(temp_array, get(ctrl->repo->medications, i));

	int pos = 0;
	Medication* temp;
	while (pos < get_length(temp_array))
	{
		if (pos == 0 || get_concentration(get(temp_array, pos)) >= get_concentration(get(temp_array, pos - 1)))
			pos = pos + 1;
		else
		{
			temp = get(temp_array, pos);
			temp_array->elements[pos] = temp_array->elements[pos - 1];
			temp_array->elements[pos - 1] = temp;

			pos = pos - 1;
		}
	}

	return temp_array;
}

void tests_controller() {
	test_filter();
	test_filter_price();
	test_short_supply();
}

void test_filter() {
	MedRepo* repo = create_repo();
	Medication* medication;
	medication = create_medication("Nurofen", 12, 5, 7);
	Medication* medication2;
	medication2 = create_medication("Ibuprofen", 5, 6, 8);
	Medication* medication3;
	medication3 = create_medication("Xanax", 19, 67, 5);
	Medication* medication4;
	medication4 = create_medication("Brufen", 12, 55, 7);
	add_med_repo(repo, medication);
	add_med_repo(repo, medication2);
	add_med_repo(repo, medication3);
	add_med_repo(repo, medication4);
	Operation_Stack* undo_stack = create_stack();
	Operation_Stack* redo_stack = create_stack();
	MedCtrl* ctrl = create_ctrl(repo, undo_stack, redo_stack);
	Dynamic_Array* arr = filter(ctrl, "fen", 1);
	assert(get_length(arr) == 3);
	int i = 0;
	for (i = 1; i < get_length(arr); i++)
		assert(strcmp(get_name(arr->elements[i]), get_name(arr->elements[i - 1])) > 0);

	free(arr->elements);
	free(arr);
	delete_ctrl(ctrl);
}

void test_filter_price() {
	MedRepo* repo = create_repo();
	Medication* medication;
	medication = create_medication("Nurofen", 12, 5, 7);
	Medication* medication2;
	medication2 = create_medication("Ibuprofen", 5, 6, 8);
	Medication* medication3;
	medication3 = create_medication("Xanax", 19, 67, 5);
	Medication* medication4;
	medication4 = create_medication("Brufen", 12, 55, 7);
	add_med_repo(repo, medication);
	add_med_repo(repo, medication2);
	add_med_repo(repo, medication3);
	add_med_repo(repo, medication4);
	Operation_Stack* undo_stack = create_stack();
	Operation_Stack* redo_stack = create_stack();
	MedCtrl* ctrl = create_ctrl(repo, undo_stack, redo_stack);
	Dynamic_Array* arr = filter_price(ctrl, 7);
	assert(get_length(arr) == 2);

	free(arr->elements);
	free(arr);
	delete_ctrl(ctrl);
}

void test_short_supply() {
	MedRepo* repo = create_repo();
	Medication* medication;
	medication = create_medication("Nurofen", 12, 5, 7);
	Medication* medication2;
	medication2 = create_medication("Ibuprofen", 5, 6, 8);
	Medication* medication3;
	medication3 = create_medication("Xanax", 19, 67, 5);
	Medication* medication4;
	medication4 = create_medication("Brufen", 12, 55, 7);
	add_med_repo(repo, medication);
	add_med_repo(repo, medication2);
	add_med_repo(repo, medication3);
	add_med_repo(repo, medication4);
	Operation_Stack* undo_stack = create_stack();
	Operation_Stack* redo_stack = create_stack();
	MedCtrl* ctrl = create_ctrl(repo, undo_stack, redo_stack);
	Dynamic_Array* arr = short_supply(ctrl, 60, 1);
	assert(get_length(arr) == 3);
	int i = 0;
	for (i = 1; i < get_length(arr); i++)
		assert(get_quantity(arr->elements[i]) >= get_quantity(arr->elements[i - 1]));

	free(arr->elements);
	free(arr);

	arr = short_supply(ctrl, 10, 2);
	assert(get_length(arr) == 2);
	for (i = 1; i < get_length(arr); i++)
		assert(get_quantity(arr->elements[i]) <= get_quantity(arr->elements[i - 1]));

	free(arr->elements);
	free(arr);
	delete_ctrl(ctrl);
}