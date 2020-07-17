#pragma once
#include "Observer.h"
#include <vector>

class Subject
{
private:
	std::vector<Observer*> os;
public:
	void add(Observer* o);
	void notify();
};

