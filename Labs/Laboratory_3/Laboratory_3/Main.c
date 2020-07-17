#include <stdio.h>
#include <Windows.h>
#include <crtdbg.h>
#include "Domain.h"
#include "Repo.h"
#include "Controller.h"
#include "UI.h"
#include "Dynamic_Array.h"
#include "Operations_Stack.h"

int main()
{
	tests_repo();
	tests_controller();
	test_dynamic_array();
	tests_stack();

	Medication* medication;
	medication = create_medication("Nurofen", 12, 5, 7);

	Medication* medication2;
	medication2 = create_medication("Ibuprofen", 5, 6, 8);

	Medication* medication3;
	medication3 = create_medication("Xanax", 19, 67, 5);

	Medication* medication4;
	medication4 = create_medication("Brufen", 12, 55, 7);
	
	Medication* medication5;
	medication5 = create_medication("Linezolid", 17, 34, 9);

	Medication* medication6;
	medication6 = create_medication("Vancomycin", 8, 49, 15);

	Medication* medication7;
	medication7 = create_medication("Oritavancin", 23, 76, 25);

	Medication* medication8;
	medication8 = create_medication("Tedizolid", 40, 89, 11);

	Medication* medication9;
	medication9 = create_medication("Magainin", 20, 73, 50);

	Medication* medication10;
	medication10 = create_medication("Ketoconazole", 19, 89, 70);
	
	MedRepo* repo = create_repo();

	add_med_repo(repo, medication);
	add_med_repo(repo, medication5);
	add_med_repo(repo, medication6);
	add_med_repo(repo, medication7);
	add_med_repo(repo, medication8);
	add_med_repo(repo, medication9);
	add_med_repo(repo, medication10);
	add_med_repo(repo, medication2);
	add_med_repo(repo, medication3);

	Operation_Stack* undo_stack = create_stack();
	Operation_Stack* redo_stack = create_stack();
	MedCtrl* ctrl = create_ctrl(repo, undo_stack, redo_stack);

	add_med_repo(ctrl->repo, medication4);

	tests_repo();
	tests_controller();
	test_dynamic_array();

	UI* ui = create_ui(ctrl);

	start_ui(ui);

	delete_ui(ui);

	_CrtDumpMemoryLeaks();

}