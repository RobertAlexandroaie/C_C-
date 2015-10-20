#ifndef VIEW_H
#define VIEW_H
#include "count.h"
#include <iostream>

class Controller;

class View
{
private:
	Controller *controller;
	Count *model;
public:
	View(Controller *newController, Count *newCount)
	{
		controller = newController;
		model = newCount;
	}
public:
	void display()
	{
		cout << endl << "New window" << endl;
		cout << "Balanta: " << model->balance() << endl;
		cout << "Commands:" << endl;
		cout << "1. Depune 50" << endl;
		cout << "2. Depune 100" << endl;
		cout << "3. Extrage 50" << endl;
		cout << "4. Extrage 100" << endl;
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
