#include "Rock_Tshirts_GUI.h"
#include <sstream>
#include <fstream>
#include "Exception_Class.h"

Rock_Tshirts_GUI::Rock_Tshirts_GUI(Controller c, QWidget *parent) : c(c), QWidget{ parent } {
	this->init();
	this->rt_list_vector = this->c.get_repo().get_rock_tshirts();
	this->populate(true);
}

void Rock_Tshirts_GUI::init()
{
	QHBoxLayout* layout = new QHBoxLayout{ this };
	QWidget* left_widget = new QWidget{};
	QVBoxLayout* left_side = new QVBoxLayout{ left_widget };

	this->rock_tshirts_list_widget = new QListWidget{};
	this->rock_tshirts_list_widget->setSelectionMode(QAbstractItemView::SingleSelection);

	QWidget* rt_data = new QWidget{};
	QFormLayout* form_layout = new QFormLayout{ rt_data };
	this->size_input = new QLineEdit{};
	this->colour_input = new QLineEdit{};
	this->price_input = new QLineEdit{};
	this->quantity_input = new QLineEdit{};
	this->photo_input = new QLineEdit{};
	this->formation_input = new QLineEdit{};
	this->id_input = new QLineEdit{};
	this->update_id_input = new QLineEdit{};
	this->update_price_input = new QLineEdit{};
	show_box = new QComboBox();
	show_box->addItem("Detailed");
	show_box->addItem("Short");

	QWidget* buttons_widget = new QWidget{};
	QGridLayout* grid_layout = new QGridLayout{ buttons_widget };
	this->add_button = new QPushButton("Add");
	this->delete_button = new QPushButton("Delete");
	this->update_price_button = new QPushButton("Update price");
	this->undo_button = new QPushButton("Undo");
	this->redo_button = new QPushButton("Redo");

	grid_layout->addWidget(add_button, 0, 0);
	grid_layout->addWidget(delete_button, 0, 1);
	grid_layout->addWidget(update_price_button, 0, 2);
	grid_layout->addWidget(show_box, 0, 3);
	grid_layout->addWidget(undo_button, 1, 0);
	grid_layout->addWidget(redo_button, 1, 1);

	left_side->addWidget(new QLabel{ "Rock Tshirts" });
	left_side->addWidget(rock_tshirts_list_widget);
	left_side->addWidget(rt_data);
	left_side->addWidget(buttons_widget);

	layout->addWidget(left_widget);

	this->connect_signals_and_slots();

}

void Rock_Tshirts_GUI::populate(bool long_format) {
	if (rock_tshirts_list_widget->count() != 0)
		rock_tshirts_list_widget->clear();
	QString list_it;
	QListWidgetItem* list_item;
	for (auto rt : rt_list_vector)
	{
		if(long_format)
		{
			list_it = QString::fromStdString(rt.to_string());
			list_item = new QListWidgetItem(list_it);
		}
		else
		{
			list_it = QString::fromStdString(rt.to_short_string());
			list_item = new QListWidgetItem(list_it);
		}

		this->rock_tshirts_list_widget->addItem(list_item);
	}
	if (rt_list_vector.size() > 0)
		rock_tshirts_list_widget->setCurrentRow(0);
}

void Rock_Tshirts_GUI::add_new_rt()
{
	this->add_window->setMinimumSize(QSize(320, 320));
	QGridLayout* grid_lay = new QGridLayout(add_window);
	QLabel* id = new QLabel("id");
	QLabel* size = new QLabel("size");
	QLabel* colour = new QLabel("colour");
	QLabel* price = new QLabel("price");
	QLabel* quantity = new QLabel("quantity");
	QLabel* photo = new QLabel("photo");
	QLabel* formation = new QLabel("formation");
	grid_lay->addWidget(id, 0, 0);
	grid_lay->addWidget(size, 1, 0);
	grid_lay->addWidget(colour, 2, 0);
	grid_lay->addWidget(price, 3, 0);
	grid_lay->addWidget(quantity, 4, 0);
	grid_lay->addWidget(photo, 5, 0);
	grid_lay->addWidget(formation, 6, 0);
	grid_lay->addWidget(id_input, 0, 1);
	grid_lay->addWidget(size_input, 1, 1);
	grid_lay->addWidget(colour_input, 2, 1);
	grid_lay->addWidget(price_input, 3, 1);
	grid_lay->addWidget(quantity_input, 4, 1);
	grid_lay->addWidget(photo_input, 5, 1);
	grid_lay->addWidget(formation_input, 6, 1);
	this->add_button_window = new QPushButton("Done");
	grid_lay->addWidget(add_button_window, 7, 1);

	QObject::connect(this->add_button_window, SIGNAL(clicked()), this, SLOT(add_rt()));

	add_window->exec();

	this->rt_list_vector = this->c.get_repo().get_rock_tshirts();
	this->populate(true);

	grid_lay->removeWidget(id);
	grid_lay->removeWidget(size);
	grid_lay->removeWidget(colour);
	grid_lay->removeWidget(price);
	grid_lay->removeWidget(quantity);
	grid_lay->removeWidget(photo);
	grid_lay->removeWidget(formation);
	grid_lay->removeWidget(id_input);
	grid_lay->removeWidget(size_input);
	grid_lay->removeWidget(colour_input);
	grid_lay->removeWidget(price_input);
	grid_lay->removeWidget(quantity_input);
	grid_lay->removeWidget(photo_input);
	grid_lay->removeWidget(formation_input);
	grid_lay->removeWidget(add_button_window);
	id_input->clear();
	size_input->clear();
	colour_input->clear();
	price_input->clear();
	quantity_input->clear();
	photo_input->clear();
	formation_input->clear();

}



void Rock_Tshirts_GUI::delete_rt() {
	if (rock_tshirts_list_widget->isItemSelected(rock_tshirts_list_widget->selectedItems().at(0)))
	{
		QListWidgetItem* selected_item = rock_tshirts_list_widget->selectedItems().at(0);
		QString text = selected_item->text();
		QStringList split = text.split(" ");
		c.delete_rock_tshirt_ctrl(split[0].toInt());
	}
	this->rt_list_vector = this->c.get_repo().get_rock_tshirts();
	this->populate(true);
}

void Rock_Tshirts_GUI::update_rt()
{
	this->update_price_window->setMinimumSize(QSize(320, 320));
	QGridLayout* grid_lay = new QGridLayout(update_price_window);
	QLabel* id = new QLabel("id");
	QLabel* price = new QLabel("new price");
	grid_lay->addWidget(id, 0, 0);
	grid_lay->addWidget(price, 1, 0);
	grid_lay->addWidget(update_id_input, 0, 1);
	grid_lay->addWidget(update_price_input, 1, 1);
	this->update_price_button_window = new QPushButton("Done");
	grid_lay->addWidget(update_price_button_window, 2, 1);

	QObject::connect(this->update_price_button_window, SIGNAL(clicked()), this, SLOT(upd_rt()));

	update_price_window->exec();

	this->rt_list_vector = this->c.get_repo().get_rock_tshirts();
	this->populate(true);

	grid_lay->removeWidget(id);
	grid_lay->removeWidget(price);
	grid_lay->removeWidget(update_id_input);
	grid_lay->removeWidget(update_price_input);
	grid_lay->removeWidget(update_price_button_window);
	update_id_input->clear();
	size_input->clear();
	colour_input->clear();
	update_price_input->clear();
	quantity_input->clear();
	photo_input->clear();
	formation_input->clear();
}

void Rock_Tshirts_GUI::upd_rt()
{
	const int id = update_id_input->text().toInt();
	const int price = update_price_input->text().toInt();
	c.update_rock_thsirt_price_ctrl(id, price);
	this->rt_list_vector = this->c.get_repo().get_rock_tshirts();
	this->populate(true);
	update_price_window->close();
}

void Rock_Tshirts_GUI::add_rt()
{
	const int id = id_input->text().toInt();
	const std::string size = size_input->text().toStdString();
	const std::string colour = colour_input->text().toStdString();
	const std::string photo = photo_input->text().toStdString();
	const std::string formation = formation_input->text().toStdString();
	const int price = price_input->text().toInt();
	const int quantity = quantity_input->text().toInt();
	try {
		c.add_rock_tshirt_ctrl(id, size, colour, quantity, price, photo, formation);
		this->rt_list_vector = this->c.get_repo().get_rock_tshirts();
		this->populate(true);
	}
	catch (Rock_Tshirt_Error& ex) {
		QMessageBox msg_box;
		msg_box.critical(0, "Error", QString::fromStdString("Invalid Input!"));
	}

	add_window->close();
}

void Rock_Tshirts_GUI::display_rt()
{
	if (this->show_box->currentText() == "Short")
		this->populate(false);
	else
		this->populate(true);
}

void Rock_Tshirts_GUI::undo_action()
{
	this->c.undo();
	this->rt_list_vector = this->c.get_repo().get_rock_tshirts();
	this->populate(true);
}

void Rock_Tshirts_GUI::redo_action()
{
	this->c.redo();
	this->rt_list_vector = this->c.get_repo().get_rock_tshirts();
	this->populate(true);
}

void Rock_Tshirts_GUI::connect_signals_and_slots()
{
	QObject::connect(rock_tshirts_list_widget, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
	QObject::connect(this->add_button, SIGNAL(clicked()), this, SLOT(add_new_rt()));
	QObject::connect(this->delete_button, SIGNAL(clicked()), this, SLOT(delete_rt()));
	QObject::connect(this->update_price_button, SIGNAL(clicked()), this, SLOT(update_rt()));
	QObject::connect(this->show_box, &QComboBox::currentTextChanged, this, [this]() {
		if (this->show_box->currentText() == "Short")
			this->populate(false);
		else
			this->populate(true);
	});
	QObject::connect(this->undo_button, SIGNAL(clicked()), this, SLOT(undo_action()));
	QObject::connect(this->redo_button, SIGNAL(clicked()), this, SLOT(redo_action()));
}

