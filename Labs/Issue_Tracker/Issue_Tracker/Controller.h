#pragma once
#include "Repo.h"
#include "Subject.h"


class Controller : public Subject
{
private:
	Repo repo;
public:
	Controller(Repo& repo);
	std::vector<User> get_users_ctrl() { return repo.get_users(); }
	std::vector<Issue> get_issues_ctrl() { return repo.get_issues(); }
	void add_issue_ctrl(std::string description, std::string reporter, std::string type);
	void remove_issue_ctrl(std::string description, std::string status);
	void update_issue_ctrl(std::string description, std::string status);
	void save();
};

