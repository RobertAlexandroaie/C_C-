#ifndef VIEW_AGENDA_H
#define VIEW_AGENDA_H
#include "model-agenda.h"
#include "display-box-string.h"
#include "menu.h"
#include <iostream>

using namespace std;

class ControllerAgenda;

class ViewAgenda
{
private:
	ControllerAgenda *controller;
	Agenda *model;
	DisplayBoxString dbOwner;
	Menu menu;
public:
	ViewAgenda(ControllerAgenda *newController, Agenda *newModel)
	{
		controller = newController;
		model = newModel;
		menu.addOption("1. Afiseaza");
		menu.addOption("0. Exit");
		dbOwner.setLabel("Proprietar");
		dbOwner.setValue(model->getOwner());
	}
public:
	void display()
	{
		cout << endl << "*** Agenda view ***" << endl;
		dbOwner.display();
		menu.display();
	}
public:
	int getUserAction()
	{
		return menu.getOption();
	}
};
#endif
