#pragma once
#include <string>

class Source_File
{
private:
	std::string name;
	std::string status;
	std::string creator;
	std::string reviewer;

public:
	Source_File(std::string name, std::string status, std::string creator, std::string reviewer);
	std::string get_status() { return status; }
	std::string get_creator() { return creator; }
	std::string get_name() { return name; }
	std::string get_reviewer() { return reviewer; }
	std::string to_string() { return name + " " + status + " " + creator + " " + reviewer; }
	void set_status(std::string status) { this->status = status; }
	void set_reviewer(std::string reviewer) { this->reviewer = reviewer; }
};

