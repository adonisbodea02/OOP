 #include "Issue_Tracker.h"
#include "qmessagebox.h"

Issue_Tracker::Issue_Tracker(Controller* ctrl, User &user, QWidget *parent)
	: c{ ctrl }, u{user}, QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(u.to_string()));
	this->update();
	
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, [this]() {
		std::string text = ui.lineEdit->text().toStdString();
		std::string full = this->windowTitle().toStdString();
		int i;
		for (i = 0; i < full.size(); i++)
			if (full[i] == ' ')
				break;
		std::string name = full.substr(0, i);
		std::string type = full.substr(i + 1, text.size() - 1);
		try {
			c->add_issue_ctrl(text, name, type);
		}
		catch (...)
		{
			QMessageBox bx;
			bx.setText(QString::fromStdString("Error"));
			bx.exec();
		}
	});

	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, [this]() {
		if (ui.listWidget->isItemSelected(ui.listWidget->selectedItems().at(0)))
		{
			QListWidgetItem* selected_item = ui.listWidget->selectedItems().at(0);
			QString text = selected_item->text();
			QStringList split = text.split(" ");
			std::string status = split[1].toStdString();
			std::string des = split[0].toStdString();
			try {
				c->remove_issue_ctrl(des, status);
			}
			catch (...)
			{
				QMessageBox bx;
				bx.setText(QString::fromStdString("Error remove"));
				bx.exec();
			}
		}
	});

	QObject::connect(ui.pushButton_3, &QPushButton::clicked, this, [this]() {
		if (ui.listWidget->isItemSelected(ui.listWidget->selectedItems().at(0)))
		{
			QListWidgetItem* selected_item = ui.listWidget->selectedItems().at(0);
			QString text = selected_item->text();
			QStringList split = text.split(" ");
			std::string des = split[0].toStdString();
			QString text2 = this->windowTitle();
			QStringList split2 = text2.split(" ");
			std::string name = split2[0].toStdString();
			c->update_issue_ctrl(des, name);
		}
	});

	QObject::connect(ui.listWidget, &QListWidget::clicked, this, [this]() {
		QString text = ui.listWidget->currentItem()->text();
		QStringList split = text.split(" ");
		std::string des = split[0].toStdString();
		std::string status = split[1].toStdString();
		QString text2 = this->windowTitle();
		QStringList split2 = text2.split(" ");
		std::string name = split2[0].toStdString();
		std::string type = split2[1].toStdString();
		ui.pushButton_3->setDisabled(true);
		if (status == "open" && type == "Developer")
			ui.pushButton_3->setEnabled(true);
		else
			ui.pushButton_3->setDisabled(true);
	});
}

void Issue_Tracker::update()
{
	ui.listWidget->clear();
	auto vec = c->get_issues_ctrl();
	std::sort(vec.begin(), vec.end(), [](Issue &i1, Issue &i2) {
		if (i1.get_status() == i2.get_status())
			return i1.get_description() < i2.get_description();
		else
			return i1.get_status() < i2.get_status();
	});
	for (auto i : vec)
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(i.to_string()));
		ui.listWidget->addItem(item);
	}
	c->save();
}
