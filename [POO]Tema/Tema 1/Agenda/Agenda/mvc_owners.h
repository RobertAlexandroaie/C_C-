#ifndef MVC_OWNERS_H
#define MVC_OWNERS_H

class IViewO
{
public:
	virtual char getUserOption()=0;
	virtual void showOwneri(int pozitie)=0;
};

class ControllerO
{
	Listao *owneri;
	IViewO* view;

public:
	void associateModel(Listao *o );

	void associateView(IViewO* v );

	void saltMVCContact();

	void start();
	
};

class ViewO:public IViewO
{
	Listao *owneri;
	ControllerO *controller;

public:
	
	ViewO(Listao *m, ControllerO* c): owneri(m), controller(c)
	{
		controller->associateModel(owneri);
		controller->associateView(this);
	}

	char getUserOption();

	void showOwneri(int pozitie);
	void AfisareOwneri(int pozitie);
};

#endif