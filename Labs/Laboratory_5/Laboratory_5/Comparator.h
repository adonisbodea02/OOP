#pragma once
#include "Domain.h"
#include "Dynamic_Vector.h"
template <typename T>
class Comparator
{
public:
	virtual ~Comparator() {}
	virtual bool compare(const Rock_Tshirt& rt1, const Rock_Tshirt& rt2) = 0;
};

template <typename T>
class compare_ascending_price : public Comparator<Rock_Tshirt>
{
public:
	bool compare(const Rock_Tshirt& rt1, const Rock_Tshirt& rt2) { return (rt1.get_price() > rt2.get_price()); }
};

template <typename T>
class compare_descending_band : public Comparator<Rock_Tshirt>
{
public:
	bool compare(const Rock_Tshirt& rt1, const Rock_Tshirt& rt2) { return (rt1.get_formation().compare(rt2.get_formation()) >= 0); }
};

void generic_sort(dynamic_vector<Rock_Tshirt>& dv, Comparator<Rock_Tshirt>& c);