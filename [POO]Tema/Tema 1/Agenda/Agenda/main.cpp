#include<iostream>
#include<fstream>
#include"contact.h"
#include"lista.h"
#include"mvc_contacts.h"
#include"mvc_owners.h"
#include"mvc_settings.h"

using namespace std;

void Start()
{
	Listao agende;
	Nodo *nod=new Nodo;
	Listac *agenda_std=new Listac;
	agenda_std->Incarca("Numepr1!Prenumepr1.txt");
	nod->informatie=agenda_std;
	agende.primul=nod;
	agende.ultimul=nod;
	agende.setNrOwneri(agende.getNrOwneri()+1);
	//ControllerO ctrl;
	//ViewO v(&agende,&ctrl);
	//ctrl.start();
	cout<<nod->informatie->getContact(1)->informatie->getNume()<<" "<<nod->informatie->getContact(1)->informatie->getPrenume();
}

void main()
{
	Start();
	system("pause");
}
