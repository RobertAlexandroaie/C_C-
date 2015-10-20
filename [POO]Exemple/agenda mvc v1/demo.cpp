// demo.cpp : Defines the entry point for the console application.
//

#include "controller-agenda.h"

using namespace std;

int main()
{
	Agenda *model = new Agenda("Ionescu");
	ControllerAgenda *controller = new ControllerAgenda(model);
	ViewAgenda *view = new ViewAgenda(controller, model);
	controller->setView(view);
	while (true)
	{
		view->display();
		controller->listen();
	}
	

	return 0;
}

