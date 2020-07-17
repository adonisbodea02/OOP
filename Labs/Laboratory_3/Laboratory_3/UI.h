#pragma once
#include "Controller.h"

typedef struct {
	MedCtrl* ctrl;
}UI;

UI* create_ui(MedCtrl* ctrl);

void delete_ui(UI* ui);

void start_ui(UI* ui);