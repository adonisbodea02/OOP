#include "Vegetables.h"
#include <QtWidgets/QApplication>
#include "File_Repo.h"
#include "Vegetable.h"

int main(int argc, char *argv[])
{
	File_Repo f("input.txt");
	QApplication a(argc, argv);
	Vegetables w(f);
	w.show();
	return a.exec();
}
