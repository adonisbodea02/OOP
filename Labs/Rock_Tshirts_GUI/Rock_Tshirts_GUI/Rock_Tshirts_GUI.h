#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Rock_Tshirts_GUI.h"
#include "Controller.h"
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qboxlayout.h>
#include <QtWidgets\qwidget.h>
#include <vector>
#include "Domain.h"
#include <QtWidgets\qlistwidget.h>
#include<QtWidgets\qformlayout.h>
#include <QtWidgets\qlineedit.h>
#include <QtWidgets\qlabel.h>
#include <qformlayout.h>
#include <QtWidgets\qmessagebox.h>
#include <stdio.h>
#include <string.h>
#include <qcombobox.h>

class Rock_Tshirts_GUI : public QWidget
{
	Q_OBJECT

public:
	Rock_Tshirts_GUI(Controller c, QWidget *parent = Q_NULLPTR);

private:
	Ui::Rock_Tshirts_GUIClass ui;

	QListWidget * rock_tshirts_list_widget;
	QDialog* add_window = new QDialog;
	QDialog* delete_window = new QDialog;
	QDialog* update_price_window = new QDialog;

	QLineEdit* size_input;
	QLineEdit* colour_input;
	QLineEdit* price_input;
	QLineEdit* quantity_input;
	QLineEdit* photo_input;
	QLineEdit* formation_input;
	QLineEdit* id_input;
	QLineEdit* update_id_input;
	QLineEdit* update_price_input;

	QPushButton* add_button;
	QPushButton* add_button_window;
	QPushButton* delete_button;
	QPushButton* delete_button_window;
	QPushButton* update_price_button;
	QPushButton* update_price_button_window;
	QPushButton* save_button;
	QPushButton* undo_button;
	QPushButton* redo_button;

	QComboBox* show_box;

	std::vector<Rock_Tshirt> rt_list_vector;
	Controller c;
	void init();
	void populate(bool long_format);

	private slots:
		void connect_signals_and_slots();
		void add_new_rt();
		void delete_rt();
		void update_rt();
		void upd_rt();
		void add_rt();
		void display_rt();
		void undo_action();
		void redo_action();










};
