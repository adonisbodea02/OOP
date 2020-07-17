#pragma once

#include <QtWidgets/QWidget>
#include "ui_PracticOOP.h"
#include "observer.h"
#include "Ctrl.h"

class PracticOOP : public QWidget, public observer
{
	Q_OBJECT

public:
	PracticOOP(Ctrl* ct, Programmer &pr, QWidget *parent = Q_NULLPTR);
	void update() override;

private:
	Ui::PracticOOPClass ui;
	Ctrl* c;
	Programmer p;
};
