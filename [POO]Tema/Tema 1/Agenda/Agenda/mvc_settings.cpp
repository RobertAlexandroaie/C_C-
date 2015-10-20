#include<iostream>
#include"contact.h"
#include"lista.h"
#include"mvc_settings.h"
#include"mvc_contacts.h"
#include"mvc_settings.h"

using namespace std;

void ViewS::showContact()
{
	cout<<"***************SETARI*******************\n";
	cout<<"****************************************\n";
	nod->informatie->Afisare();
	cout<<"****************************************\n";
}

char ViewS::getUserOption()
{
	cout << endl;
	cout << "N: Editati nume.\n"; 
	cout << "P: Editati prenume.\n"; 
	cout << "T: Editati numarul de telefon.\n";
	cout << "A: Editati atributul.\n";
	cout << "Q: Iesire\n";

	char c=' '; 

	cout<<"Optiune: ";
	cin >> c;

	return c;
}

void ViewS::getUserData(char *s)
{
	cout<<"Text: ";
	cin.get();
	cin.get(s,50,'\n');
}

void ControllerS::associateModel(Nodc *p)
{
	nod=p;
}

void ControllerS::associateView(IViewS *v)
{
	view=v;
}

bool ControllerS::startSettings()
{
	char c=' ';

	char *s=new char;
	strcpy(s,"");
	bool m=false;

	while ( c != 'q' )
	{
		system("CLS");
		view->showContact();

		while ( ! ( (c=='q') || (c=='t')  || (c=='p') || (c=='n') || (c=='a') ))
			c=view->getUserOption();
		
		
		if ( c == 'q' )
			return m;

		view->getUserData(s);
		m=nod->informatie->Switch(c,s);
	}
	return m;
	delete s;
}