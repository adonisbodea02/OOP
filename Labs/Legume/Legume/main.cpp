#include "Legume.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	File_Repo r("input.txt");
	Legume w(r);
	w.show();
	return a.exec();
}
