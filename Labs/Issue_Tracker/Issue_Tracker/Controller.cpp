#include "Controller.h"

Controller::Controller(Repo & repo)
{
	this->repo = repo;
}

void Controller::add_issue_ctrl(std::string description, std::string reporter, std::string type)
{
	repo.add_issue(description, reporter, type);
	notify();
}

void Controller::remove_issue_ctrl(std::string description, std::string status)
{
	repo.remove_issue(description, status);
	notify();
}

void Controller::update_issue_ctrl(std::string description, std::string status)
{
	repo.update_issue(description, status);
	notify();
}

void Controller::save()
{
	repo.write();
}
