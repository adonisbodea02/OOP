#pragma once
#include "Source_File.h"
#include "Programmer.h"
#include <vector>
#include <algorithm>
#include <fstream>

class Repository
{
private:
	std::vector<Source_File> sources;
	std::vector<Programmer> pros;

public:
	Repository();
	std::vector<Source_File> get_sources() { return sources; }
	std::vector<Programmer> get_programmers() { return pros; }

	/*
	Function which adds a source to the repository based on the name and the creator;
	Input: std::string name - the name of the file
		   std::string creator - the creator of the file
	Output: none
	The function creates a new source file and pushes it into the vector of sources if the name is not the empty string or one with the same name
	already exists. In that case it throws an error.
	*/
	void add_source(std::string name, std::string creator);

	/*
	Function which updates a source from the repository, changing its status and reviewer;
	Input: std::string name - the name of the file
	std::string reviewer - the reviewer of the file
	Output: none
	The function updates the status and reviewer of a source file based on the name of the file.
	*/
	void update(std::string name, std::string reviewer);
	void read();
	void write();
};

