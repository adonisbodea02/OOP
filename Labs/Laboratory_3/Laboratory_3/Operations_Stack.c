#include "Operations_Stack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Operation* create_operation(Medication* med, char* operation_type) {
	Operation* oper = (Operation*)malloc(sizeof(Operation));
	oper->med = copy_med(med);

	if (operation_type != NULL)
	{
		oper->Operation_Type = (char*)malloc(sizeof(char) * strlen(operation_type) + 1);
		strcpy(oper->Operation_Type, operation_type);
	}
	else
		oper->Operation_Type = NULL;

	return oper;
}

void destroy_operation(Operation* oper) {
	if (oper == NULL)
		return;

	delete_medication(oper->med);
	free(oper->Operation_Type);
	free(oper);
}

Operation* copy_operation(Operation* oper) {
	if (oper == NULL)
		return NULL;

	Operation* new_op = create_operation(oper->med, oper->Operation_Type);
	return new_op;

}

char* get_operation_type(Operation* oper) {
	return oper->Operation_Type;
}
Medication* get_medication_stack(Operation* oper) {
	return oper->med;
}

Operation_Stack* create_stack() {
	Operation_Stack* stack = (Operation_Stack*)malloc(sizeof(Operation_Stack));
	stack->length = 0;

	return stack;
}

void destroy_stack(Operation_Stack* stack) {
	if (stack == NULL)
		return;

	for (int i = 0; i < stack->length; i++)
		destroy_operation(stack->operations[i]);

	free(stack);
}

void push(Operation_Stack* stack, Operation* oper) {
	if (is_full(stack))
		return;
	
	stack->operations[stack->length] = copy_operation(oper);
	stack->length++;
}

Operation* pop(Operation_Stack* stack) {
	if (is_empty(stack))
		return NULL;
	
	stack->length--;
	return stack->operations[stack->length];
}
int is_empty(Operation_Stack* stack) {
	return (stack->length == 0);
}
int is_full(Operation_Stack* stack) {
	return (stack->length == 100);
}

void tests_stack() {
	Operation_Stack* stack = create_stack();
	Medication* medication;
	medication = create_medication("Nurofen", 12, 5, 7);
	Medication* medication2;
	medication2 = create_medication("Ibuprofen", 5, 6, 8);
	
	Operation* o1 = create_operation(medication, "add");
	Operation* o2 = create_operation(medication2, "add");
	Operation* o3 = create_operation(medication, "update");
	Operation* o4 = create_operation(medication, "remove");

	delete_medication(medication);
	delete_medication(medication2);

	push(stack, o1);
	push(stack, o2);
	push(stack, o3);
	push(stack, o4);

	destroy_operation(o1);
	destroy_operation(o2);
	destroy_operation(o3);
	destroy_operation(o4);

	assert(is_full(stack) == 0);
	assert(is_empty(stack) == 0);

	Operation* oper = pop(stack);
	assert(strcmp(oper->Operation_Type, "remove") == 0);
	destroy_operation(oper);

	oper = pop(stack);
	assert(strcmp(oper->Operation_Type, "update") == 0);
	destroy_operation(oper);

	oper = pop(stack);
	assert(strcmp(oper->Operation_Type, "add") == 0);
	destroy_operation(oper);

	oper = pop(stack);
	assert(strcmp(oper->Operation_Type, "add") == 0);
	destroy_operation(oper);

	assert(is_empty(stack) == 1);

	destroy_stack(stack);
}