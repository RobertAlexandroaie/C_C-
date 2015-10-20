#ifndef MVC_CONTACTS_H
#define MVC_CONTACTS_H
#include"lista.h";

class IViewC
{
public:
	virtual char getUserOption()=0;
	virtual void showContacte(int pozitie)=0;
};

class ControllerC
{
	Listac *agenda;
	IViewC *view;

public:
	void associateModel(Listac *);
	void associateView(IViewC *);	
	void startContacte();

	void Filtreaza();

	void Cauta();

	void SaltMVCSettings();
};

class ViewC:public IViewC
{
	Listac *agenda;
	ControllerC *controller;
	
public:
	
	ViewC(Listac *a, ControllerC *c): agenda(a), controller(c)
	{	
		controller->associateModel(agenda);
		controller->associateView(this);
	}
	
	void showContacte(int pozitie);

	char getUserOption();
	void AfisareContacte(int );
};

#endif