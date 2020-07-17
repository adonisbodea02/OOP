#include "UI.h"
#include <crtdbg.h>

using namespace std;

class Vector {
private:
	int* elems;
	int size;

public:
	Vector() : size{ 0 } { elems = new int[10]; }
	void add(int elem) { elems[size++] = elem; }
	int& operator[](int pos)
	{
		if (pos < 0 || pos>size)
			throw exception("blabla");
		return elems[pos];
	}
	~Vector() { delete[] elems; }
};

int main()
{
	{
		Vector v1;
		v1.add(0);
		v1.add(2);
		Vector v2 = v1;
		try {
			cout << v1[0] << " " << v1[1] << " ";
			cout << v2[0] << " " << v2[1] << " ";
		}
		catch (std::exception& e)
		{
			cout << e.what();
		}
		cout << "cca";
	}
	return 0;
}

/*
int main()
{
	{
		Client* p = new Normal_Client("Gabi", 45);
		Client* p1 = new Wealthy_Client("aLEX", 47, 67);
		std::vector<Client*> v;
		v.push_back(p);
		v.push_back(p1);
		RealEstateAgency r(v);
		UI ui{ r };
		ui.run();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}
*/