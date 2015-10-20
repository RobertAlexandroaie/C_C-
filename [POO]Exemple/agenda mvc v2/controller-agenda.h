#ifndef CONTROLLER_AGENDA_H
#define CONTROLLER_AGENDA_H
#include "model-agenda.h" // modelul
#include "view-agenda.h"

using namespace std;

class ControllerAgenda
{
private:
	Agenda *model;
	ViewAgenda *view;
public:
	ControllerAgenda(Agenda *newModel)
	{
		model = newModel;
		
	}
public:
	void setView(ViewAgenda *newView)
	{
		view = newView;
	}
public:
	void listen()
	{
		int option = view->getUserAction();
		switch (option)
		{
			case 0: finish();
				break;
			case 1: 
				model->display();
				break;
			default: exit(1);
		}
	}

public:
	void finish()
	{
		exit(0);
	}
};

#endif 
