#include "Issue_Tracker.h"
#include <QtWidgets/QApplication>
#include "Repo.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repo r;
	Controller ctrl(r);
	for (auto &p : ctrl.get_users_ctrl())
	{
		Issue_Tracker* w = new Issue_Tracker(&ctrl, p);
		ctrl.add(w);
		w->show();
	}
	return a.exec();
}
