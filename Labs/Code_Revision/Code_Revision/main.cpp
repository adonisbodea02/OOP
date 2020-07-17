#include "Code_Revision.h"
#include <QtWidgets/QApplication>
#include "Controller.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repo r;
	Controller ctrl(r);
	for (auto &p : ctrl.get_programmers_ctrl())
	{
		Code_Revision * w = new Code_Revision(&ctrl, p);
		ctrl.add(w);
		w->show();
	}
	return a.exec();
}
