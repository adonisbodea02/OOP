#pragma once
#include "User.h"
#include "Issue.h"
#include <vector>
#include <algorithm>
#include <fstream>

class Repo
{
private:
	std::vector<User> users;
	std::vector<Issue> issues;

public:
	Repo();
	void read();
	void write();
	std::vector<Issue> get_issues() { return issues; }
	std::vector<User> get_users() { return users; }
	void add_issue(std::string description, std::string reporter, std::string type);
	void remove_issue(std::string description, std::string status);
	void update_issue(std::string description, std::string solver);
};

