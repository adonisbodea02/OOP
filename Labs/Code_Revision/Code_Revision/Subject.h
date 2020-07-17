#pragma once
#include "Observer.h"
#include <vector>

class Subject
{
public:
	
	void add(Observer* o) { os.push_back(o); }
	void notify();

private:
	std::vector<Observer*> os;
};

