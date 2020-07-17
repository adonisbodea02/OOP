#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"

/*
function which returns a pointer to a newly created medication;
Input: char pointer - name
	   int pointer - concentration 
	   int pointer - quanity 
	   int pointer - price
Output: medication - pointer
*/
Medication* create_medication(char* name, int* concentration, int* quantity, int* price) {
	Medication *medication = malloc(sizeof(Medication));
	strcpy(medication->name, name);
	(*medication).concentration = concentration;
	(*medication).quantity = quantity;
	(*medication).price = price;
	return medication;
}

/*
function which deletes/frees a medication
Input: medication pointer
Output: none
*/
void delete_medication(Medication *medication) {
	free(medication);
}

/*
function which gets a pointer the name of a medication
Input: medication pointer
Output: char pointer
*/
char* get_name(Medication *medication) {
	return medication->name;
}

/*
function which gets a pointer the concentration of a medication
Input: medication pointer
Output: int pointer
*/
int* get_concentration(Medication *medication) {
	return medication->concentration;
}

/*
function which gets a pointer the quantity of a medication
Input: medication pointer
Output: int pointer
*/
int* get_quantity(Medication *medication) {
	return medication->quantity;
}

/*
function which gets a pointer the price of a medication
Input: medication pointer
Output: int pointer
*/
int* get_price(Medication *medication) {
	return medication->price;
}

int set_quantity(Medication *medication, int quantity) {
	medication->quantity = quantity;
}

int set_price(Medication *medication, int price) {
	medication->price = price;
}

Medication* copy_med(Medication* med) {
	if (med == NULL)
		return NULL;

	Medication* new_med = create_medication(get_name(med), get_concentration(med), get_quantity(med), get_price(med));
	return new_med;
}
