#pragma once
#include "Domain.h"
#include "Dynamic_Array.h"
#include <string.h>

typedef struct
{
	Medication* med;
	char* Operation_Type;
} Operation;

Operation* create_operation(Medication* med, char* operation_type);
void destroy_operation(Operation* oper);
Operation* copy_operation(Operation* oper);
char* get_operation_type(Operation* oper);
Medication* get_medication_stack(Operation* oper);

typedef struct
{
	Operation* operations[100];
	int length;
} Operation_Stack;

Operation_Stack* create_stack();
void destroy_stack(Operation_Stack* stack);
void push(Operation_Stack* stack, Operation* oper);
Operation* pop(Operation_Stack* stack);
int is_empty(Operation_Stack* stack);
int is_full(Operation_Stack* stack);

void tests_stack();