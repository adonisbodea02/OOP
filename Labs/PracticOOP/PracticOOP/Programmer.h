#pragma once
#include <string>

class Programmer
{
private:
	std::string name;
	int revised;
	int to_revise;

public:
	Programmer(std::string name, int revise, int to_revise);
	int get_revised() { return revised; }
	int get_to_revise() { return to_revise; }
	std::string get_name() { return name; }
	std::string to_string() { return name + " " + std::to_string(revised) + " " + std::to_string(to_revise);}
	void set_revised(int revised) { this->revised = revised; }
	void set_to_revise(int to_revise) { this->to_revise = to_revise; }
};
