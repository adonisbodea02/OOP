#include "File_Repo.h"
#include <fstream>
#include <iostream>

File_Repo::File_Repo(std::string filename)
{
	this->filename = filename;
	std::ifstream f(filename);
	double a;
	double b;
	double c;
	
	while (!f.eof())
	{
		f >> a;
		f >> b;
		f >> c;
		eqs.push_back(Equation(a, b, c));
	}

	std::ofstream g("output.txt");
	for (auto i : eqs)
		g << i.get_a() << " " << i.get_b() << " " << i.get_c() << "\n";
}
