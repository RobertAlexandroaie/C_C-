#include "model-agenda.h"
#include "view-contact.h"
#include "controller-contact.h"

#include <iostream>


using namespace std;

Agenda::Agenda(char *name)
{
	owner = string(name);
	contact = Contact("no contact", "");
}

Agenda::~Agenda()
{
	//nothing
}

void Agenda::display()
{
	ControllerContact controller(&contact);
	ViewContact view(&controller, &contact);
	controller.setView(&view);
	view.display();
	controller.listen();
}




void Agenda::displayOwner()
{
	cout << owner.c_str() << endl;
}	