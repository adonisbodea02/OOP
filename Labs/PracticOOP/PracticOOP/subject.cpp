#include "subject.h"

void subject::add(observer * o)
{
	os.push_back(o);
}

void subject::notify()
{
	for (auto i : os)
		i->update();
}
