#pragma once

#include <QtWidgets/QWidget>
#include "ui_Issue_Tracker.h"
#include "Controller.h"

class Issue_Tracker : public QWidget, public Observer
{
	Q_OBJECT

public:
	Issue_Tracker(Controller* ctrl, User &user, QWidget *parent = Q_NULLPTR);
	void update() override;

private:
	Ui::Issue_TrackerClass ui;
	Controller* c;
	User u;
};
