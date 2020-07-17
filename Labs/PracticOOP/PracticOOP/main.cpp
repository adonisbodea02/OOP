#include "PracticOOP.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Ctrl.h"
#include <assert.h>


void test()
{
	Repository repo;
	try {
		repo.add_source("", "maria");
	}
	catch (std::string& r)
	{
		assert(r == std::string("Invalid"));
	}

	try {
		repo.add_source("main", "maria");
	}
	catch (std::string& msg)
	{
		assert(msg == std::string("Invalid"));
	}

	repo.add_source("papa", std::string("dan"));
	repo.update("controller", "toni");
	repo.update("ui", "cosmi");
	std::vector<Source_File> s = repo.get_sources();
	assert(s[1].get_reviewer() == std::string("toni"));
	assert(s[1].get_status() == std::string("revised"));
	assert(s[0].get_reviewer() == std::string("cosmi"));
	assert(s[0].get_status() == std::string("revised"));
	assert(s[3].get_status() == std::string("not_revised"));
	assert(s[3].get_reviewer() == std::string("none"));
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	test();
	Repository repo;
	Ctrl c(repo);
	for (auto &p : c.get_programmers_ctrl())
	{
		PracticOOP* w = new PracticOOP(&c, p);
		c.add(w);
		w->show();
	}
	return a.exec();
}
