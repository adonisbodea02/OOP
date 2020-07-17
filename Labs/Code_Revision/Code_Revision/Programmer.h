#pragma once
#include <string>

class Programmer
{
public:
	Programmer(std::string name, int r, int to_r);
	int get_revised() { return revised; }
	int get_to_revise() { return to_revise; }
	std::string get_name() { return name; }
	void set_revised(int revised) { this->revised = revised; }
	void set_to_revised(int to_revise) { this->to_revise = to_revise; }
	std::string to_string();
	~Programmer();

private:
	std::string name;
	int revised;
	int to_revise;

};

