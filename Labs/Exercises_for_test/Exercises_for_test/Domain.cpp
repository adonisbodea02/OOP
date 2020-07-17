#include  "Domain.h"

Material::Material(): name(""), supplier(""), quantity(), expiry_date(Date()) {}

Material::Material(const std::string name, const std::string supplier, const int quantity, const Date& expiry_date)
{
	this->name = name;
	this->expiry_date = expiry_date;
	this->supplier = supplier;
	this->quantity = quantity;
}

bool Material::operator==(Material m)
{
	return this->get_name() == m.get_name() && this->get_supplier() == m.get_supplier() && this->expiry_date == m.expiry_date;

}

Date::Date(): day(0), month(0), year(0) {}

Date::Date(const int day, const int month, const int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

bool Date::operator==(Date& d)
{
	return this->get_day() == d.get_day() && this->get_month() == d.get_month() && this->get_year() == d.get_year();
}

bool Date::compare_dates(int day, int month, int year)
{
	if (this->get_year() < year)
		return 1;
	else
	{
		if (this->get_year() == year)
		{
			if (this->get_month() < month)
				return 1;
			else
			{
				if (this->get_month() == month)
				{
					if (this->get_day() < day)
						return 1;
					return 0;
				}
				return 0;
			}
		}
		return 0;
	}
}