#ifndef VIEW_AGENDA_H
#define VIEW_AGENDA_H
#include "model-agenda.h"
#include <iostream>

using namespace std;

class ControllerAgenda;

class ViewAgenda
{
private:
	ControllerAgenda *controller;
	Agenda *model;
public:
	ViewAgenda(ControllerAgenda *newController, Agenda *newModel)
	{
		controller = newController;
		model = newModel;
	}
public:
	void display()
	{
		cout << endl << "*** Agenda view ***" << endl;
		cout << "Proprietar: "; model->displayOwner(); cout << endl;
		cout << "Menu:" << endl;
		cout << "1. Afiseaza" << endl;
		cout << "0. Exit" << endl;
	}
public:
	int getUserAction()
	{
		int option;
		cout << "Option: ";
		cin >> option;
		return option;
	}
};
#endif
