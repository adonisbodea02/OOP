#include "Test3.h"
#include "File_Repo.h"
#include "Equation.h"
#include <string>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	File_Repo repo("input.txt");
	QApplication a(argc, argv);
	Test3 w(repo);
	w.show();
	return a.exec();
}
