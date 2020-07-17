#pragma once
#include "observer.h"
#include <vector>

class subject
{
private:
	std::vector<observer*> os;

public:
	void add(observer * o);
	void notify();
};

