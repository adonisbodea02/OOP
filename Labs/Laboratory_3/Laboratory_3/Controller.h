#pragma once
#include "Repo.h"
#include "Operations_Stack.h"

typedef struct {
	MedRepo* repo;
	Operation_Stack* undo_stack;
	Operation_Stack* redo_stack;
} MedCtrl;

MedCtrl* create_ctrl(MedRepo* repo, Operation_Stack* undo_st, Operation_Stack* redo_st);

void delete_ctrl(MedCtrl* ctrl);

int add_med_ctrl(MedCtrl* ctrl, Medication* med);

int delete_med_ctrl(MedCtrl* ctrl, char name[], int concentration);

int update_med_quantity_ctrl(MedCtrl* ctrl, char name[], int concentration, int new_quantity);

int update_med_price_ctrl(MedCtrl* ctrl, char name[], int concentration, int new_price);

int get_length_ctrl(MedCtrl* ctrl);

Dynamic_Array* filter(MedCtrl* ctrl, char String[], int kind);

Dynamic_Array* filter_price(MedCtrl* ctrl, int price);

Dynamic_Array* short_supply(MedCtrl* ctrl, int quantity, int kind);

Dynamic_Array* filter_medication_ctrl(MedCtrl* ctrl, char String[]);

int undo(MedCtrl* ctrl);

int redo(MedCtrl* ctrl);

void tests_controller();

void test_filter();

void test_filter_price();

void test_short_supply();

//void test_undo();

//void set_repo(MedCtrl* ctrl, MedRepo* repo);

//void filter(MedCtrl* ctrl, char String[]);