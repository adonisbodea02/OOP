#pragma once

#include <QtWidgets/QWidget>
#include "ui_Legume.h"
#include "File_Repo.h"

class Legume : public QWidget
{
	Q_OBJECT

public:
	Legume(File_Repo fr, QWidget *parent = Q_NULLPTR);

private:
	Ui::LegumeClass ui;
	File_Repo repo;

private slots:
	void on_send_vegie_clicked();
	void show_vegs();
};
