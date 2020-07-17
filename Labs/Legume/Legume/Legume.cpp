#include "Legume.h"
#include <string.h>
#include <set>
Legume::Legume(File_Repo fr, QWidget *parent)
	: repo(fr), QWidget(parent)
{
	ui.setupUi(this);
	std::set<std::string> st;
	for (auto i : repo.get_all())
	{
		int ok = 1;
		int poz = ui.listWidget->count() - 1;
		if (poz)
			if (st.find(i.get_family()) != st.end())
				ok = 0;
		if ( ok )
			st.insert(i.get_family());
	}
	for (auto p : st)
		ui.listWidget->addItem(QString::fromStdString(p));

	int j;
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_send_vegie_clicked()));
	//ui.listWidget->setCurrentItem(ui.listWidget->item(0));
	//QObject::connect(, SIGNAL(clicked()), this, SLOT(show_vegs()));
	QObject::connect(ui.listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(show_vegs()));
}

void Legume::on_send_vegie_clicked()
{
	QString text = ui.lineEdit->text();
	std::string txt = text.toStdString();

	
	for (auto i : repo.get_all())
	{
		if (i.get_name() == txt)
		{
			ui.lineEdit_2->setText(QString::fromStdString(i.get_type()));
			int j;
			for (j = 0; j < (ui.listWidget->count()); j++)
			{
				ui.listWidget->item(j)->setBackgroundColor(Qt::white);
			}
			for (j = 0; j < (ui.listWidget->count()); j++)
			{
				if (ui.listWidget->item(j)->text() == QString::fromStdString(i.get_family()))
				{
					ui.listWidget->item(j)->setBackgroundColor(Qt::yellow);
					break;
				}
			}
			break;
		}
	}
	
}

void Legume::show_vegs()
{
	if (ui.listWidget->isItemSelected(ui.listWidget->selectedItems().at(0)))
	{
		std::string text = ui.listWidget->selectedItems().at(0)->text().toStdString();
		std::vector<Vegetable> fam = repo.get_family(text);
		ui.listWidget_2->clear();
		for (auto i : fam)
			ui.listWidget_2->addItem(QString::fromStdString(i.get_name() + " " + i.get_type()));
	}
}
