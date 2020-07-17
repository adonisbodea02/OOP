#pragma once
#define CAPACITY 10

typedef void* TElement;
typedef void(*destroy_element_function_type)(void*);

typedef struct
{
	TElement* elements;
	int length;
	int capacity;
	destroy_element_function_type destroy_elem_fct;
}Dynamic_Array;

Dynamic_Array* create_dynamic_array(int capacity, destroy_element_function_type destroy_elem_fct);

void destroy_array(Dynamic_Array* arr);

int resize(Dynamic_Array* arr);

void add(Dynamic_Array* arr, TElement t);

void destroy_el(Dynamic_Array* arr, int pos);

int get_length(Dynamic_Array* arr);

TElement get(Dynamic_Array* arr, int pos);

void test_dynamic_array();





