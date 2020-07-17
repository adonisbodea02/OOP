#pragma once
#include "Domain.h"

template <class TElement>
class dynamic_vector
{
private:
	TElement* elems;
	int size;
	int capacity;

public:
	dynamic_vector(int capacity = 10);

	dynamic_vector(const dynamic_vector& dv);

	~dynamic_vector();

	dynamic_vector& operator=(const dynamic_vector& dv);

	void add(const TElement& e);
	
	void delete_element(int& pos);

	dynamic_vector& operator-(const TElement &e);

	int get_size() const;

	TElement* get_all_elems() const;

	TElement get_element(int pos);

	TElement operator[](int pos);

	void set_element(int pos, const TElement& elem);

private:

	void resize(int factor = 2);
};

template <class TElement>
dynamic_vector<TElement>::dynamic_vector(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->elems = new TElement[this->capacity];
}

template <class TElement>
dynamic_vector<TElement>::dynamic_vector(const dynamic_vector& dv)
{
	this->capacity = dv.capacity;
	this->size = dv.size;
	this->elems = new TElement[dv.capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = dv.elems[i];
}

template <class TElement>
dynamic_vector<TElement>::~dynamic_vector()
{
	delete[] elems;
}

template <class TElement>
dynamic_vector<TElement> &dynamic_vector<TElement>::operator=(const dynamic_vector& dv)
{
	this->capacity = dv.capacity;
	this->size = dv.size;
	if (this != &dv)
	{
		delete[] this->elems;
		this->elems = new TElement[this->capacity];
		for (int i = 0; i < this->size; i++)
			this->elems[i] = dv.elems[i];

	}
	return *this;
}

template <class TElement>
void dynamic_vector<TElement>::add(const TElement& e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <class TElement>
void dynamic_vector<TElement>::delete_element(int& pos)
{
	if(pos < this->size - 1)
		for (int i = pos; i < this->size; i++)
			this->elems[i] = this->elems[i + 1];
	this->size--;
}

template <class TElement>
void dynamic_vector<TElement>::resize(int factor)
{
	this->capacity *= factor;

	TElement* new_elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		new_elems[i] = this->elems[i];

	delete[] this->elems;
	this->elems = new_elems;
}

template <class TElement>
TElement* dynamic_vector<TElement>::get_all_elems() const
{
	return this->elems;
}

template <class TElement>
int dynamic_vector<TElement>::get_size() const
{
	return this->size;
}

template <class TElement>
dynamic_vector<TElement>& dynamic_vector<TElement>::operator-(const TElement& e)
{
	for (int i = 0; i < this->get_size(); i++)
		if (this->elems[i] == e)
			this->delete_element(i);

	return *this;
}

template <class TElement>
TElement dynamic_vector<TElement>::get_element(int pos)
{
	return this->elems[pos];
}

template <class TElement>
TElement dynamic_vector<TElement>::operator[](const int pos)
{
	return this->elems[pos];
}

template <class TElement>
void dynamic_vector<TElement>::set_element(int pos, const TElement& elem)
{
	this->elems[pos] = elem;
}