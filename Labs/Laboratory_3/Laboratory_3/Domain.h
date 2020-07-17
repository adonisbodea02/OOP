#pragma once

typedef struct {
	char name[255];
	int concentration;
	int quantity;
	int price;
} Medication;

Medication* create_medication(char* name, int* concentration, int* quantity, int* price);

void delete_medication(Medication *medication);

char* get_name(Medication *medication);

int* get_concentration(Medication *medication);

int* get_quantity(Medication *medication);

int* get_price(Medication *medication);

int set_quantity(Medication *medication, int concentration);

int set_price(Medication *medication, int price);

Medication* copy_med(Medication* med);

