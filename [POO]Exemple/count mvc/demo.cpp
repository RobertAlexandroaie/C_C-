// demo.cpp : Defines the entry point for the console application.
//

#include "controller.h"

using namespace std;

int main()
{
	Count *model = new Count("Ionescu");
	Controller *controller = new Controller(model);
	View *view = new View(controller, model);
	controller->setView(view);
	try {
		while (true)
		{
			view->display();
			controller->listen();
		}
	}
	catch (char *mes_err) 
	{
	   cout << mes_err << endl;
	}

	return 0;
}

