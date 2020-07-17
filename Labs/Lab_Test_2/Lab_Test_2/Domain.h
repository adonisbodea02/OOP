#pragma once
#include <iostream>
#include <string>

class Dwelling
{
protected:
	std::string type;
	double price;
	bool is_profitable;

public:

	Dwelling() {};

	Dwelling(const std::string type, const double price, const bool is_profitable);

	bool get_is_profitable() { return is_profitable; };
	std::string get_type() { return type; };
	double get_price() { return price; };

	double normal_bank_rate() { return price / 1000; };
	double large_bank_rate() { return price / 100; };

};

class Client
{
protected:
	std::string name;
	double salary;

public:

	Client() {};

	Client(const std::string name, const double salary);

	std::string get_name() { return name; };
	double get_salary() { return salary; };

	virtual double total_income() = 0;
	virtual std::string to_string() = 0;
	virtual bool is_interested(Dwelling d) = 0;
};

class Normal_Client : public Client
{
public:

	Normal_Client(const std::string name, const double salary);
	double total_income() override;
	std::string to_string() override;
	bool is_interested(Dwelling d) override;
};

class Wealthy_Client : public Client
{
private:
	double money_invs;

public:
	Wealthy_Client(const std::string name, const double salary, const double money_invs);
	double total_income() override;
	std::string to_string() override;
	bool is_interested(Dwelling d) override;
};