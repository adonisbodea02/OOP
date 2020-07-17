#pragma once
#include <vector>
#include <algorithm>
#include "Repository.h"
#include <memory>

class Controller
{
private:
	Repository repo_all;
	Repository special_storage;

public:
	void add_painting_ctrl(Painting* p);
	void delete_painting_ctrl(std::string title, std::string artist, int year);
	std::vector<Painting*> get_all_ctrl() { return this->repo_all.get_all(); };
	std::vector<Painting*> get_all_special() { return this->special_storage.get_all(); };
	void move(std::string title, std::string artist, int year);
	void write_ctrl(std::string filename);
};