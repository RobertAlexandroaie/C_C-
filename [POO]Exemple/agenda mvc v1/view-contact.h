#ifndef VIEW_CONTACT_H
#define VIEW_CONTACT_H
#include "model-contact.h"
#include <iostream>

using namespace std;

class ControllerContact;

class ViewContact
{
private:
	ControllerContact *controller;
	Contact *model;
public:
	ViewContact(ControllerContact *newController, Contact *newModel)
	{
		controller = newController;
		model = newModel;
	}
public:
	void display()
	{
		cout << endl << "*** Contact view ***" << endl;
		cout << "Contact: "; 
		cout << model->getName().c_str() << "  " << model->getPhoneNo().c_str() << endl;
		cout << "Menu:" << endl;
		cout << "1. Modifica" << endl;
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
