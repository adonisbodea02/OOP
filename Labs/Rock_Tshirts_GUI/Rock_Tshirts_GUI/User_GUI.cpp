#include "User_GUI.h"

User_GUI::User_GUI(Controller &c, QWidget* parent) : ctrl(c), QWidget{ parent } {
	this->init();
	this->rt_list_vector = this->ctrl.get_repo().get_rock_tshirts();

}

void User_GUI::init()
{
	QHBoxLayout* layout = new QHBoxLayout{ this };
	QWidget* left_widget = new QWidget{};
	QVBoxLayout* left_side = new QVBoxLayout{ left_widget };

	this->rt_list_widget = new QListWidget{};
	this->rt_list_widget->setSelectionMode(QAbstractItemView::SingleSelection);

	QWidget* buttons_widget = new QWidget{};
	QGridLayout* grid_layout = new QGridLayout{ buttons_widget };
	this->add_to_shop_list_button = new QPushButton("Add to shop list");
	this->next_button = new QPushButton("See next rock T-shirt");
	this->see_shop_list_button = new QPushButton("See shop list");
	this->start_search_button = new QPushButton("Start search");
	this->view_button = new QPushButton("View");

	this->add_to_shop_list_button->setDisabled(true);
	this->next_button->setDisabled(true);

	grid_layout->addWidget(add_to_shop_list_button, 0, 0);
	grid_layout->addWidget(next_button, 0, 1);
	grid_layout->addWidget(see_shop_list_button, 0, 2);
	grid_layout->addWidget(start_search_button, 0, 3);
	grid_layout->addWidget(view_button, 1, 0);


	QWidget* size_data_widget = new QWidget{};
	QFormLayout* size_layout = new QFormLayout{ size_data_widget };
	size_layout->addRow("Size(S/M/L/XL/XXL): ", size_input);
	show_price->setReadOnly(true);
	size_layout->addRow("Total sum: ", show_price);

	left_side->addWidget(new QLabel{ "Current T-shirt" });
	left_side->addWidget(rt_list_widget);
	left_side->addWidget(buttons_widget);
	left_side->addWidget(size_data_widget);

	layout->addWidget(left_widget);
	this->connect_signal_and_slots();

}

void User_GUI::add_to_shop_list()
{
	Rock_Tshirt rt = this->ctrl.sh->get_current_tshirt();
	this->ctrl.sh->add_chosen_tshirt(rt);
	this->total_price += rt.get_price();
	int q = rt.get_quantity();
	q--;
	this->ctrl.update_rock_thsirt_quantity_ctrl(rt.get_ID(), q);
	this->show_price->setText(QString::fromStdString(std::to_string(this->total_price)));
}

void User_GUI::next_rt()
{
	this->rt_list_widget->clear();
	Rock_Tshirt rt = this->ctrl.sh->next();
	QString list_it = QString::fromStdString(rt.to_string());
	QListWidgetItem* list_item = new QListWidgetItem(list_it);
	this->rt_list_widget->addItem(list_item);
}

void User_GUI::see_shop_list()
{
	this->ctrl.sh->write_to_file();
	this->ctrl.sh->display_shop_list();
}

void User_GUI::start_search()
{
	this->rt_list_widget->clear();
	this->size = this->size_input->text().toStdString();
	std::vector<Rock_Tshirt> rt_sh = this->ctrl.filter_by_size(this->size);
	this->ctrl.sh->set_tshirts(rt_sh);
	Rock_Tshirt rt = this->ctrl.sh->get_current_tshirt();
	rt.display();
	QString list_it = QString::fromStdString(rt.to_string());
	QListWidgetItem* list_item = new QListWidgetItem(list_it);
	this->rt_list_widget->addItem(list_item);
	this->add_to_shop_list_button->setDisabled(false);
	this->next_button->setDisabled(false);
}

void User_GUI::connect_signal_and_slots()
{
	QObject::connect(this->add_to_shop_list_button, SIGNAL(clicked()), this, SLOT(add_to_shop_list()));
	QObject::connect(this->next_button, SIGNAL(clicked()), this, SLOT(next_rt()));
	QObject::connect(this->see_shop_list_button, SIGNAL(clicked()), this, SLOT(see_shop_list()));
	QObject::connect(this->start_search_button, SIGNAL(clicked()), this, SLOT(start_search()));
	QObject::connect(this->view_button, SIGNAL(clicked()), this, SLOT(mymodel()));

}

void User_GUI::mymodel()
{
	this->my_model = new Model(nullptr, this->ctrl);
	this->my_model->show();
}
