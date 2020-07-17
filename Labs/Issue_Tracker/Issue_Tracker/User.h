#pragma once
#include <string>

class User
{
private:
	std::string name;
	std::string type;

public:
	User(std::string name, std::string type);
	std::string get_name() { return name; }
	std::string get_type() { return type; }
	std::string to_string() { return name + " " + type; }
};

