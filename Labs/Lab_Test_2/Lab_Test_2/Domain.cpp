#include "Domain.h"

Dwelling::Dwelling(const std::string type, const double price, const bool is_profitable)
{
	this->type = type;
	this->price = price;
	this->is_profitable = is_profitable;
}

Client::Client(const std::string name, const double salary)
{
	this->name = name;
	this->salary = salary;
}

Normal_Client::Normal_Client(const std::string name, const double salary)
{
	this->name = name;
	this->salary = salary;
}

double Normal_Client::total_income()
{
	return salary;
}

std::string Normal_Client::to_string()
{
	std::string s;
	s += name;
	s += ", ";
	s += std::to_string(salary);
	s += ", ";
	s += std::to_string(salary);
	return s;
}

bool Normal_Client::is_interested(Dwelling d)
{
	return d.normal_bank_rate() <= this->total_income();
}

Wealthy_Client::Wealthy_Client(const std::string name, const double salary, const double money_invs)
{
	this->name = name;
	this->salary = salary;
	this->money_invs = money_invs;
}

double Wealthy_Client::total_income()
{
	return salary + money_invs;
}

std::string Wealthy_Client::to_string()
{
	std::string s;
	s += name;
	s += ", ";
	s += std::to_string(salary);
	s += ", ";
	s += std::to_string(money_invs);
	s += ", ";
	s += std::to_string(money_invs + salary);
	return s;
}

bool Wealthy_Client::is_interested(Dwelling d)
{
	return (d.large_bank_rate() <= this->total_income()) && (d.get_is_profitable());
}
