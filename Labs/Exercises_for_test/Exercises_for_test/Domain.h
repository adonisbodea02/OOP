#pragma once
#include <iostream>

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date();

	Date(const int day, const int month, const int year);

	bool operator==(Date& d);

	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }
	
	bool compare_dates(int day, int month, int year);
};

class Material
{
private:
	std::string name;
	std::string supplier;
	int quantity;
	Date expiry_date;

public:
	Material();

	Material(const std::string name, const std::string supplier, const int quantity, const Date& expiry_date);

	bool operator==(Material m);

	std::string get_name() { return name; }
	std::string get_supplier() { return supplier; }
	int get_quantity() { return quantity; }
	Date get_expiry_date() { return expiry_date; }
	void set_quantity(int q) { quantity = q; }

};