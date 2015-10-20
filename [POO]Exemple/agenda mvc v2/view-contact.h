#ifndef VIEW_CONTACT_H
#define VIEW_CONTACT_H
#include "model-contact.h"
#include "menu.h"
#include "display-box-string.h"
#include <iostream>

using namespace std;

class ControllerContact;

class ViewContact
{
private:
	ControllerContact *controller;
	Contact *model;
	Menu menu;
	DisplayBoxString dbName;
	DisplayBoxString dbNo;
public:
	ViewContact(ControllerContact *newController, Contact *newModel)
	{
		controller = newController;
		model = newModel;
		menu.addOption("1. Modifica");
		menu.addOption("0. Exit");
		dbName.setLabel("Nume");
		dbName.setValue(model->getName());
		dbNo.setLabel("Numar");
		dbNo.setValue(model->getPhoneNo());
	}
public:
	void display()
	{
		cout << endl << "*** Contact view ***" << endl;
		cout << "Contact: "; 
		dbName.display();
		dbNo.display();
		menu.display();
	}
public:
	int getUserAction()
	{
		return menu.getOption();
	}
};
#endif
