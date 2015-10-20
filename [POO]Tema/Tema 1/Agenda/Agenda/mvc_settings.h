#ifndef MVCSETTINGS_H
#define MVCSETTINGS_H
#include"contact.h"

class IViewS
{
public:
	virtual char getUserOption()=0;
	virtual void showContact()=0;
	virtual void getUserData(char *s)=0;
};

class ControllerS
{
	Nodc *nod;
	IViewS *view;

public:
	// setarea canalelor de comunicatie
	void associateModel(Nodc *);
	void associateView(IViewS *);

	// bucla de executie
	
	bool startSettings();
};

class ViewS:public IViewS
{
	Nodc *nod;
	ControllerS *controller;
	char *text;
public:
	
	ViewS(Nodc *n, ControllerS *c): nod(n), controller(c)
	{
		controller->associateModel(nod);
		controller->associateView(this);
	}
		
	void showContact();
	char getUserOption();
	void getUserData(char *s);
};

#endif