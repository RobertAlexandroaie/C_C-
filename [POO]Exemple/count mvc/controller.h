#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "count.h" // modelul
#include "view.h"


using namespace std;

class Controller
{
private:
	Count *model;
	View *view;
public:
	Controller(Count *newModel)
	{
		model = newModel;
		
	}
public:
	void setView(View *newView)
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
				model->deposit(50);
				break;
			case 2: 
				model->deposit(100);
				break;
			case 3: 
				model->draw(50);
				break;
			case 4: 
				model->draw(100);
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
