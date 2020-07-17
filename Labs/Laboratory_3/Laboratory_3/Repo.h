#pragma once
#include "Domain.h"
#include "Dynamic_Array.h"
#include <assert.h>

typedef struct {
	Dynamic_Array* medications;
} MedRepo;

MedRepo* create_repo();

void delete_repo(MedRepo* repo);

int find_pos_med(MedRepo* repo, char name[], int concentration);

int add_med_repo(MedRepo* repo, Medication* med);

int delete_med_repo(MedRepo* repo, char name[], int concentration);

int update_med_quantity_repo(MedRepo* repo, char name[], int concentration, int new_quantity);

int update_med_price_repo(MedRepo* repo, char name[], int concentration, int new_price);

int get_length_repo(MedRepo* repo);

void tests_repo();

void test_add();

void test_delete();

void test_update_price();

void test_update_quantity();