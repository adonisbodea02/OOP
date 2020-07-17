#include "UI.h"
#include <crtdbg.h>

using namespace std;

int main()
{
	{
		Repository repo{};
		Controller ctrl{ repo };
		UI ui{ ctrl };
		ui.start();
	}
	_CrtDumpMemoryLeaks();
}