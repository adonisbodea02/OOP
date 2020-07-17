#include "Repo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
function which creates a pointer to a newly created repo;
Input: none;
Output: MedRepo pointer
*/
MedRepo* create_repo() {
	MedRepo* repo = (MedRepo*)malloc(sizeof(MedRepo));
	repo->medications = create_dynamic_array(CAPACITY, &delete_medication);
	
	return repo;
}

/*
function which deletes/frees a repo;
Input: pointer to the repo to be deleted;
Output: none
*/
void delete_repo(MedRepo* repo) {
	if (repo == NULL)
		return;
	destroy_array(repo->medications);
	free(repo);
}

/*
function which searches an element (medication) in the repo based on a name and a concentration;
Input: pointer to the repo;
	   int concentration;
	   char array name;
Output: int type;
more precisely the position if the medication was found and 0 otherwise;
*/
int find_pos_med(MedRepo* repo, char name[], int concentration)
{
	if (repo == NULL)
		return -1;

	for (int i = 0; i < get_length(repo->medications); i++)
		if (strcmp(get_name(get(repo->medications, i)), name) == 0)
			if(get_concentration(get(repo->medications, i)) == concentration)
				return i;
	return -1;
}

/*
function which adds an element (medication) to the repo;
Input: pointer to the repo;
	   pointer to the medication to be added
Output: int type; 
		more precisely 1 if the operation was successful and 0 otherwise;
*/
int add_med_repo(MedRepo* repo, Medication* med) {

	if (repo == NULL)
		return -1;

	int t = find_pos_med(repo, get_name(med), get_concentration(med));

	if (t == -1)
		add(repo->medications, med);
	else
	{
		int q1 = 0;
		q1 = get_quantity(repo->medications->elements[t]);
		int q2 = 0;
		q2 = get_quantity(med);
		q1 += q2;
		set_quantity(repo->medications->elements[t], q1);
		return 0;
	}

	return 1;
}

/*
function which deletes an element (medication) from the repo;
Input: pointer to the repo;
	   char array which represents the name;
	   int which represent concentration
Output: int type;
		more precisely 1 if the operation was successful and 0 otherwise;
*/
int delete_med_repo(MedRepo* repo, char name[], int concentration) {
	
	if (repo == NULL)
		return -1;

	int t = find_pos_med(repo, name, concentration);
	if (t == -1)
		return 0;
	else
	{
		destroy_el(repo->medications, t);
		return 1;
	}
}

/*
function which updates the quantity of an element (medication) from the repo;
Input: pointer to the repo;
	   char array which represents the name;
	   int which represent concentration
	   int which represent the new quantity;
Output: int type;
		more precisely 1 if the operation was successful and 0 otherwise;
*/
int update_med_quantity_repo(MedRepo* repo, char name[], int concentration, int new_quantity) {
	
	if (repo == NULL)
		return -1;

	int t = find_pos_med(repo, name, concentration);

	if (t == -1)
		return 0;
	else
	{
		set_quantity(repo->medications->elements[t], new_quantity);
		return 1;
	}
}

/*
function which updates the price of an element (medication) from the repo;
Input: pointer to the repo;
	   char array which represents the name;
	   int which represent concentration
	   int which represent the new price;
Output: int type;
		more precisely 1 if the operation was successful and 0 otherwise;
*/
int update_med_price_repo(MedRepo* repo, char name[], int concentration, int new_price) {
	
	if (repo == NULL)
		return -1;

	int t = find_pos_med(repo, name, concentration);

	if (t == -1)
		return 0;
	else
	{
		set_price(repo->medications->elements[t], new_price);
		return 1;
	}
}

/*
function which gets the length of a repo;
Input: pointer to the repo;
Output: int type;
*/
int get_length_repo(MedRepo* repo) {

	if (repo == NULL)
		return -1;

	return get_length(repo->medications);
}

void test_add() {
	MedRepo* repo = create_repo();
	Medication* medication;
	medication = create_medication("Nurofen", 12, 5, 7);
	assert(get_length_repo(repo) == 0);
	assert(add_med_repo(repo, medication) == 1);
	assert(get_length_repo(repo) == 1);
	assert(add_med_repo(repo, medication) == 0);
	assert(get_length_repo(repo) == 1);
	assert(get_quantity(get(repo->medications, 0)) == 10);
	delete_repo(repo);
}

void test_delete() {
	MedRepo* repo = create_repo();
	Medication* medication;
	medication = create_medication("Nurofen", 12, 5, 7);
	add_med_repo(repo, medication);
	assert(delete_med_repo(repo, "Nurofen", 13) == 0);
	assert(delete_med_repo(repo, "Nurof", 12) == 0);
	assert(delete_med_repo(repo, "Nurofen", 12) == 1);
	assert(get_length_repo(repo) == 0);
	delete_repo(repo);
}

void test_update_quantity() {
	MedRepo* repo = create_repo();
	Medication* medication;
	medication = create_medication("Nurofen", 12, 5, 7);
	add_med_repo(repo, medication);
	assert(update_med_quantity_repo(repo, "Nurofen", 13, 56) == 0);
	assert(update_med_quantity_repo(repo, "Nurof", 12, 47) == 0);
	assert(update_med_quantity_repo(repo, "Nurofen", 12, 70) == 1);
	assert(get_quantity(get(repo->medications, 0)) == 70);
	delete_repo(repo);
}

void test_update_price() {
	MedRepo* repo = create_repo();
	Medication* medication;
	medication = create_medication("Nurofen", 12, 5, 7);
	add_med_repo(repo, medication);
	assert(update_med_price_repo(repo, "Nurofen", 13, 56) == 0);
	assert(update_med_price_repo(repo, "Nurof", 12, 47) == 0);
	assert(update_med_price_repo(repo, "Nurofen", 12, 70) == 1);
	assert(get_price(get(repo->medications, 0)) == 70);
	delete_repo(repo);
}

void tests_repo() {
	test_add();
	test_delete();
	test_update_quantity();
	test_update_price();
}