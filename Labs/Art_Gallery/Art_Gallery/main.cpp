#include "UI.h"
#include <crtdbg.h>

int main()
{
	{
		Controller ctrl{};
		UI ui{ ctrl };

		ui.run();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}