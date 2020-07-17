#pragma once

#include <QtWidgets/QWidget>
#include "ui_Test3.h"
#include "File_Repo.h"

class Test3 : public QWidget
{
	Q_OBJECT

public:
	Test3(File_Repo r, QWidget *parent = Q_NULLPTR);

private:
	Ui::Test3Class ui;
	File_Repo repo;
	void show_solution();
	void update();
};
