#include "Vegetables.h"

Vegetables::Vegetables(File_Repo fr, QWidget *parent)
	: repo(fr), QWidget(parent)
{
	ui.setupUi(this);
}
