#include "Dynamic_Array.h"
#include <stdlib.h>
#include <assert.h>
#include "Domain.h"
#include <string.h>

/*
Function which creates a dynamic array of generic elements, with a given capacity.
Input: int capacity, function pointer, of type destroy_element_function_type, the function that deals with deallocating the elements of the array;
Output: a pointer to the newly created dynamic array
*/
Dynamic_Array* create_dynamic_array(int capacity, destroy_element_function_type destroy_elem_fct) {
	Dynamic_Array* dyn_arr = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	if (dyn_arr == NULL)
		return NULL;

	dyn_arr->capacity = capacity;
	dyn_arr->length = 0;

	dyn_arr->elements = (TElement*)malloc(capacity * sizeof(TElement));
	if (dyn_arr->elements == NULL)
		return NULL;

	dyn_arr->destroy_elem_fct = destroy_elem_fct;

	return dyn_arr;
}

/*
Function which destroys the dynamic array
Input: pointer to the array to be destroyed;
Output: none
*/
void destroy_array(Dynamic_Array* arr) {

	if (arr == NULL)
		return;

	for (int i = 0; i < arr->length; i++)
	{
		arr->destroy_elem_fct(arr->elements[i]);
	}

	free(arr->elements);
	free(arr);
}

/*
Function which reallocates memory if the capacity is reached;
Input: pointer to the array;
Output: 1 if it was done succesfully;
*/
int resize(Dynamic_Array* arr) {

	if (arr == NULL)
		return;

	arr->capacity *= 2;

	TElement* aux = (TElement*)malloc(arr->capacity * sizeof(TElement));
	if (aux == NULL)
		return -1;
	for (int i = 0; i < arr->length; i++)
		aux[i] = arr->elements[i];
	free(arr->elements);
	arr->elements = aux;

	return 0;
}

/*
Adds a generic to the dynamic array
Input: pointer to the dynamic array
		the element to be added;
Output: none
*/
void add(Dynamic_Array* arr, TElement t) {
	if (arr == NULL)
		return;
	if (arr->elements == NULL)
		return;
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elements[arr->length] = t;
	arr->length++;
}

/*
Function which destroys an element of the array;
Input: pointer to the array, int position;
Output: none;
*/
void destroy_el(Dynamic_Array* arr, int pos) {
	if (arr == NULL)
		return;
	if (arr->elements == NULL)
		return;
	if (pos < 0 || pos >= arr->length)
		return;

	arr->destroy_elem_fct(arr->elements[pos]);

	for (int i = pos; i < arr->length - 1; i++)
		arr->elements[i] = arr->elements[i + 1];

	arr->length--;
}

/*
Function which returns the length of the array
Input: pointer to the array
Output: int type length
*/
int get_length(Dynamic_Array* arr) {
	if (arr == NULL)
		return -1;

	return arr->length;
}

/*
Function which returns the element on a certain position
Input: pointer to the array
int pos;
Output: return pointer type of the element;
*/
TElement get(Dynamic_Array* arr, int pos) {
	return arr->elements[pos];
}

void test_dynamic_array()
{
	Dynamic_Array* dyn_arr_meds = create_dynamic_array(2, &delete_medication);
	assert(dyn_arr_meds->capacity == 2);
	assert(dyn_arr_meds->length == 0);

	Medication* medication;
	medication = create_medication("Nurofen", 12, 5, 7);

	Medication* medication2;
	medication2 = create_medication("Ibuprofen", 5, 6, 8);

	Medication* medication3;
	medication3 = create_medication("Xanax", 19, 67, 5);

	add(dyn_arr_meds, medication);
	assert(dyn_arr_meds->length == 1);

	add(dyn_arr_meds, medication2);
	assert(get_length(dyn_arr_meds) == 2);

	add(dyn_arr_meds, medication3);
	assert(get_length(dyn_arr_meds) == 3);
	assert(dyn_arr_meds->capacity == 4);

	destroy_el(dyn_arr_meds, 0);
	Medication* aux = get(dyn_arr_meds, 1);
	assert(strcmp(get_name(aux), "Xanax") == 0);
	assert(get_length(dyn_arr_meds) == 2);

	destroy_array(dyn_arr_meds);
}