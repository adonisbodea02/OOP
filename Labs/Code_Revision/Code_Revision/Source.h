#pragma once
#include <string>

class Source
{
public:
	Source(std::string name, std::string status, std::string creator, std::string reviewer);
	~Source();
	std::string get_name() { return name; }
	std::string get_status() { return status; }
	std::string get_creator() { return creator; }
	std::string get_reviewer() { return reviewer; }
	void set_status(std::string status) { this->status = status; }
	void get_reviewer(std::string reviewer) { this->reviewer = reviewer; }
	std::string to_string();

private:
	std::string name;
	std::string status;
	std::string creator;
	std::string reviewer;
};

