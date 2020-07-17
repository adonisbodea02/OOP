#pragma once
#include <string>
class Vegetable
{
public:
	Vegetable(std::string family, std::string name, std::string type);
	std::string get_family() { return family; };
	std::string get_name() { return name; };
	std::string get_type() { return type; };

private:
	std::string family;
	std::string name;
	std::string type;
};
