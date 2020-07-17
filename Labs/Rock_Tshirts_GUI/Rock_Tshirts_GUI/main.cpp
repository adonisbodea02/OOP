#include "Rock_Tshirts_GUI.h"
#include <QtWidgets/QApplication>
#include "HTML_Shoplist.h"
#include "CVS_ShopList.h"
#include "Repository.h"
#include "Controller.h"
#include "User_GUI.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QMessageBox msg_box{};
	msg_box.setWindowTitle("Choose mode");
	msg_box.setText("Type mode(admin/user)");
	QPushButton* button1 = msg_box.addButton("Administrator mode", QMessageBox::ActionRole);
	QPushButton* button2 = msg_box.addButton("User mode", QMessageBox::AcceptRole);

	msg_box.exec();
	if (msg_box.clickedButton() == button1)
	{
		File_Shop_list* sh = new CVS_Shop_list{ "ado.txt" };
		Validator v;
		File_Repo repo{ "in.txt" };
		Controller ctrl{ repo, sh };
		Rock_Tshirts_GUI w{ ctrl };
		w.show();
		return a.exec();
	}
	else
	{
		QMessageBox msg_box_user{};
		msg_box_user.setWindowTitle("Choose type of file");
		msg_box_user.setText("Type of fyle(CSV/HTML)");
		QPushButton* button1_user = msg_box_user.addButton("CSV File", QMessageBox::ActionRole);
		QPushButton* button2_user = msg_box_user.addButton("HTML File", QMessageBox::AcceptRole);

		msg_box_user.exec();
		if (msg_box_user.clickedButton() == button1_user)
		{
			File_Shop_list* sh = new CVS_Shop_list{ "ado.txt" };
			Validator v;
			File_Repo repo{ "in.txt" };
			Controller ctrl{ repo, sh };
			User_GUI w{ ctrl };
			w.show();
			return a.exec();
		}
		else
		{
			File_Shop_list* sh = new HTML_Shop_list{ "adonis.html" };
			Validator v;
			File_Repo repo{ "in.txt" };
			Controller ctrl{ repo, sh };
			User_GUI w{ ctrl };
			w.show();
			return a.exec();
		}
	}
}
