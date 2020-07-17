#include "Test3.h"

Test3::Test3(File_Repo r, QWidget *parent)
	: repo(r), QWidget(parent)
{
	ui.setupUi(this);
	for (auto i : repo.get_eqs())
	{
		ui.listWidget->addItem(QString::number(i.get_a())  + QString::fromStdString("*x^2+") + QString::number(i.get_b()) + QString::fromStdString("*x+") + QString::number(i.get_c()));
	}
	QObject::connect(ui.listWidget, &QListWidget::itemClicked, this, &Test3::show_solution);
	//QObject::connect(ui.pushButton_2, SIGNAL(clicked())), this, SLOT(update()));
	//QObject::connect(ui.listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(show_solution()));
}

void Test3::show_solution()
{
	if (ui.listWidget->isItemSelected(ui.listWidget->selectedItems().at(0)))
	{
		ui.lineEdit->setText(ui.listWidget->selectedItems().at(0)->text());
		ui.listWidget_2->addItem(ui.listWidget->selectedItems().at(0)->text());
	}
	//}
	//{
		//std::string text = ui.listWidget->selectedItems().at(0)->text().toStdString();
	//ui.listWidget_2->addItem(ui.listWidget->selectedItems().at(0)->text());
	//}
	
}

void Test3::update()
{
	std::string a1 = ui.lineEdit->text().toStdString();
	std::string b1 = ui.lineEdit_2->text().toStdString();
	std::string c1 = ui.lineEdit_3->text().toStdString();
	double a = std::stod(a1);
	double b = std::stod(b1);
	double c = std::stod(c1);
}


	
