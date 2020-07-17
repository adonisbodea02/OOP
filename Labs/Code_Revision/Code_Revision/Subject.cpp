#include "Subject.h"

void Subject::notify()
{
	for (auto i : os)
		i->update();
}
