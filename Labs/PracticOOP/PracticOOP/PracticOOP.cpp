#include "PracticOOP.h"
#include "qmessagebox.h"

PracticOOP::PracticOOP(Ctrl* ct, Programmer &pr, QWidget *parent)
	: QWidget(parent), c{ct}, p{pr}
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(p.get_name()));
	this->update();
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, [this]() {
		std::string name = ui.lineEdit->text().toStdString();
		std::string prg = p.get_name();
		try {
			c->add_source_ctrl(name, prg);
		}
		catch (...)
		{
			QMessageBox bx;
			bx.setText("Error occured when adding!");
			bx.exec();
		}
	});

	QObject::connect(ui.listWidget, &QListWidget::clicked, this, [this]() {
		std::string text = ui.listWidget->currentItem()->text().toStdString();
		ui.pushButton_2->setDisabled(true);
		if (text.find("not_revised") != std::string::npos && text.find(p.get_name()) == std::string::npos)
			ui.pushButton_2->setEnabled(true);
		else
			ui.pushButton_2->setDisabled(true);
	});

	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, [this]() {
		std::string text = ui.listWidget->currentItem()->text().toStdString();
		int i;
		for (i = 0; i < text.size(); i++)
			if (text[i] == ' ')
				break;
		std::string name = text.substr(0, i);
		p.set_revised(p.get_revised() + 1);
		p.set_to_revise(p.get_to_revise() - 1);
		c->update_source_ctrl(name, p.get_name());
		//ui.listWidget->currentItem()->setBackgroundColor(Qt::green);
		if (p.get_to_revise() == 0)
		{
			QMessageBox bx;
			bx.setText("Congratulations!");
			bx.exec();
		}
	});
}

void PracticOOP::update()
{
	ui.listWidget->clear();
	auto vec = c->get_sources_ctrl();
	std::sort(vec.begin(), vec.end(), [](Source_File& s1, Source_File& s2) {return s1.get_name() < s2.get_name(); });
	for (auto s : vec)
	{
		QListWidgetItem * item = new QListWidgetItem(QString::fromStdString(s.to_string()));
		if (s.get_status() == "not_revised")
		{
			QFont f;
			f.setBold(true);
			item->setFont(f);
		}
		else
		{
			item->setBackgroundColor(Qt::green);
		}
		ui.listWidget->addItem(item);
	}
	ui.label_3->setText(QString::number(p.get_revised()));
	ui.label_4->setText(QString::number(p.get_to_revise()));
}
