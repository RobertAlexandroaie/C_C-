#include <fstream>
#include <iostream>
#include"contact.h"
#include"lista.h"
#include"mvc_owners.h"
#include"mvc_contacts.h"

using namespace std;

char ViewO::getUserOption() 
{
	cout << endl;
	cout << "w: Selectati optiunea precedenta.\n"; 
	cout << "s: Selectati optiunea urmatoare.\n"; 
	cout << "e: Afisati contactele proprietarului selectat.\n";
	cout << "n: Adaugati un nou proprietar.\n";
	cout << "d: Stergeti proprietarul curent(inclusiv agenda sa).\n";
	cout << "k: Salvati agenda selectata.\n";
	cout << "q: Iesire\n";

	char c=' '; 
	
	cout<<"Optiune: ";
	cin >> c;

	return c;
}

void ViewO::AfisareOwneri(int pozitie)
{
	if(owneri->EsteVida())
	{
		cout<<"Nu aveti agende in memorie!\n";
		return;
	}

	int i;
	Nodo *p;

	if(pozitie<=3)
		for(p=owneri->primul,i=0;p!=NULL&&i<5;i++,p=p->urmator)
		{
			if(i+1==pozitie) cout<<"o->";
			else cout<<"   ";
			if(p!=NULL) cout<<p->informatie->ownerContact.getNume()<<"-"<<p->informatie->ownerContact.getPrenume()<<"\n";
			cout<<"\n";
		}
	else
		if(pozitie>3&&pozitie<=owneri->Lungime()-2)
		{
			for(p=owneri->primul,i=1;i<pozitie&&p!=NULL;i++) p=p->urmator;

			cout<<"   "; cout<<p->precedent->precedent->informatie->ownerContact.getNume()<<"-"<<p->precedent->precedent->informatie->ownerContact.getPrenume()<<"\n";
			cout<<"   "; cout<<p->precedent->informatie->ownerContact.getNume()<<"-"<<p->precedent->informatie->ownerContact.getPrenume()<<"\n";			
			cout<<"o->"; cout<<p->informatie->ownerContact.getNume()<<"-"<<p->informatie->ownerContact.getPrenume()<<"\n";
			cout<<"   "; cout<<p->urmator->informatie->ownerContact.getNume()<<"-"<<p->urmator->informatie->ownerContact.getPrenume()<<"\n";
			cout<<"   "; cout<<p->urmator->urmator->informatie->ownerContact.getNume()<<"-"<<p->urmator->urmator->informatie->ownerContact.getPrenume()<<"\n";
		}
	else
		if(pozitie==owneri->Lungime()-1)
		{
			for(p=owneri->primul,i=1;i<pozitie&&p!=NULL;i++,p=p->urmator);
			cout<<"   "; cout<<p->precedent->precedent->precedent->informatie->ownerContact.getNume()<<"-"<<p->precedent->precedent->precedent->informatie->ownerContact.getPrenume()<<"\n";
			cout<<"   "; cout<<p->precedent->precedent->informatie->ownerContact.getNume()<<"-"<<p->precedent->precedent->informatie->ownerContact.getPrenume()<<"\n";			
			cout<<"   "; cout<<p->precedent->informatie->ownerContact.getNume()<<"-"<<p->precedent->informatie->ownerContact.getPrenume()<<"\n";
			cout<<"o->"; cout<<p->informatie->ownerContact.getNume()<<"-"<<p->urmator->informatie->ownerContact.getPrenume()<<"\n";
			cout<<"   "; cout<<p->urmator->informatie->ownerContact.getNume()<<"-"<<p->urmator->informatie->ownerContact.getPrenume()<<"\n";
		}
		else
			if(pozitie==owneri->Lungime())
			{
				for(p=owneri->primul,i=1;i<pozitie&&p!=NULL;i++,p=p->urmator);
				cout<<"   "; cout<<p->precedent->precedent->precedent->precedent->informatie->ownerContact.getNume()<<"-"<<p->precedent->precedent->precedent->precedent->informatie->ownerContact.getPrenume()<<"\n";
				cout<<"   "; cout<<p->precedent->precedent->precedent->informatie->ownerContact.getNume()<<"-"<<p->precedent->precedent->precedent->informatie->ownerContact.getPrenume()<<"\n";
				cout<<"   "; cout<<p->precedent->precedent->informatie->ownerContact.getNume()<<"-"<<p->precedent->precedent->informatie->ownerContact.getPrenume()<<"\n";			
				cout<<"   "; cout<<p->precedent->informatie->ownerContact.getNume()<<"-"<<p->precedent->informatie->ownerContact.getPrenume()<<"\n";
				cout<<"o->"; cout<<p->informatie->ownerContact.getNume()<<"-"<<p->urmator->informatie->ownerContact.getPrenume()<<"\n";
			}
}

void ViewO::showOwneri(int pozitie)
{
	cout<<"****************PROPRIETARI*************\n";
	cout<<"****************************************\n";
	cout<<owneri->getPoz()<<" din "<<owneri->getNrOwneri()<<"\n";
	cout<<"****************************************\n";
	AfisareOwneri(pozitie);
	cout<<"****************************************\n";
}

void ControllerO::associateModel(Listao *o )
{ 
	owneri = o; 
}

void ControllerO::associateView(IViewO* v )
{ 
	view = v;
}

void ControllerO::saltMVCContact()
{
	ControllerC ctr;
	ViewC view(this->owneri->getOwner(owneri->getPoz()),&ctr);
	ctr.startContacte();
}

void ControllerO::start()
{
	char c=' ';
	while ( c != 'q' )
	{
		system("CLS");
		view->showOwneri(owneri->getPoz());

		while ( ! ( (c=='q') || (c=='s') || (c=='w') || (c=='e') || (c=='n') || (c=='d') ) )
		{
			c = view->getUserOption();
		}

		if ( c == 'q' )
			return;

		switch(c) 
		{
			case 'w': owneri->setPoz(owneri->getPoz()-1); break;
			case 's': owneri->setPoz(owneri->getPoz()+1); break;
			case 'n': owneri->AdaugaOwner(); break;
			case 'd': owneri->StergeOwner(); break;
			case 'e': saltMVCContact(); break;
		}
		c = ' ' ;
	} 
	return;
}
