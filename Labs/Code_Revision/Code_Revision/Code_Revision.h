#pragma once

#include <QtWidgets/QWidget>
#include "ui_Code_Revision.h"
#include "Controller.h"
#include <qmessagebox.h>

class Code_Revision : public QWidget, public Observer
{
	Q_OBJECT

public:
	Code_Revision(Controller* ctrl, Programmer& pr, QWidget *parent = Q_NULLPTR);
	void update() override;

private:
	Ui::Code_RevisionClass ui;
	Controller* c;
	Programmer p;
};
