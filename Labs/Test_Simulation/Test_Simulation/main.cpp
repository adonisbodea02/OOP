#include "UI.h"
#include <crtdbg.h>
using namespace std;

int main()
{

	std::string message;
	cout << message.empty();
	{
		Offer o1{ "Penthouse", "Porumbului nr. 1", 1456, 1900 };
		Offer o2{ "Apartment", "Adrian Marino nr. 8A", 2476, 2900 };
		Offer o3{ "House", "Micus nr. 2", 6752, 8000 };
		Offer o4{ "Penthouse", "Teodor Mihali nr. 156", 3200, 1500 };

		Repository r{};

		r.add_offer_repo(o1);
		r.add_offer_repo(o2);
		r.add_offer_repo(o3);
		r.add_offer_repo(o4);

		Controller c{ r };
		UI ui{ c };
		ui.start();
	}
	_CrtDumpMemoryLeaks();
}