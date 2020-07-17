#include "UI.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Repository r;
	r.create_tiles();
	Controller c(r);
	UI u;
	u.set_controller(c);
	u.start();
}