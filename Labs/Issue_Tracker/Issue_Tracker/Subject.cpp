#include "Subject.h"

void Subject::add(Observer * o)
{
	os.push_back(o);
}

void Subject::notify()
{
	for (auto i : os)
		i->update();
}
