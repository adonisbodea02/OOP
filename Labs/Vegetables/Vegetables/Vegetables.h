#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Vegetables.h"
#include "File_Repo.h"

namespace Ui {
	class Vegetables;
}

class Vegetables : public QWidget
{
	Q_OBJECT

public:
	Vegetables(File_Repo fr, QWidget *parent = Q_NULLPTR);

private:
	Ui::VegetablesClass ui;
	File_Repo repo;
};
