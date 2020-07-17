#pragma once
#include <string>

class Issue
{
private:
	std::string description;
	std::string status;
	std::string reporter;
	std::string solver;

public:

	Issue(std::string description, std::string status, std::string reporter, std::string solver);
	std::string get_description() { return description; }
	std::string get_status() { return status; }
	std::string get_reporter() { return reporter; }
	std::string get_solver() { return solver; }
	void set_solver(std::string solver) { this->solver = solver; }
	void set_status(std::string status) { this->status = status; }
	std::string to_string() { return description + " " + status + " " + reporter + " " + solver; }
};

