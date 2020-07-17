#pragma once

#include <QWidget>
//#include "ui_User.h"
#include "Controller.h"
#include "Domain.h"
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qboxlayout.h>
#include <QtWidgets\qwidget.h>
#include <QtWidgets\qlistwidget.h>
#include<QtWidgets\qformlayout.h>
#include <QtWidgets\qlineedit.h>
#include <QtWidgets\qlabel.h>
#include <qformlayout.h>
#include <qmessagebox.h>
#include "Model.h"

class User_GUI : public QWidget
{
	Q_OBJECT

public:
	User_GUI(Controller &c, QWidget *parent = 0);

private:
	Controller &ctrl;
	QDialog* choose_size_window = new QDialog;
	QLineEdit* size_input = new QLineEdit;
	QLineEdit* show_price = new QLineEdit;
	QListWidget * rt_list_widget;
	std::string size;
	int total_price{ 0 };
	void init();
	std::vector<Rock_Tshirt> rt_list_vector;
	QPushButton* add_to_shop_list_button;
	QPushButton* next_button;
	QPushButton* see_shop_list_button;
	QPushButton* start_search_button;
	QPushButton* back;
	QPushButton* view_button;
	Model* my_model;
	//Ui::User ui;
	private slots:
		void add_to_shop_list();
		void next_rt();
		void see_shop_list();
		void start_search();
		void connect_signal_and_slots();
		void mymodel();
};

