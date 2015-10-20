#include <fstream>
#include <iostream>
#include"mvc_contacts.h";
#include"mvc_owners.h";
#include"mvc_settings.h";
#include"lista.h";
#include"contact.h";

using namespace std;

char ViewC::getUserOption()
{ 
	cout << endl;
	cout << "w: Selectati contactul precedent.\n"; 
	cout << "s: Selectati contactul urmatoar.\n"; 
	cout << "e: Afisati optiunile contactului.\n";
	cout << "f: Filtrati dupa <criteriu>.\n";
	cout << "r: Cautati dupa <criteriu>.\n";
	cout << "n: Adaugati un contact nou.\n";
	cout << "d: Stergeti contactul.\n";
	cout << "q: Iesire\n";

	char c=' '; 
	
	cout<<"Optiune: ";
	cin >> c;
	cin.ignore(256,'\n'); 
	cin.clear();

	return c;
}

void ViewC::AfisareContacte(int pozitie)
{
	if(agenda->EsteVida())
	{
		cout<<"Nu aveti contacte in agenda!\n";
		return;
	}

	int i;
	Nodc *p;

	if(pozitie<=3)
		for(p=agenda->primul,i=0;p!=NULL&&i<5;i++,p=p->urmator)
		{
			if(i+1==pozitie) cout<<"o->";
			else cout<<"   ";
			if(p!=NULL)
			{
				cout<<"("<<p->getTip()<<")"<<p->informatie->getAtribut()<<"\n   "<<p->informatie->getNume()<<" "<<p->informatie->getPrenume()<<"\n   "<<p->informatie->getNrTel()<<"\n";
			}
			cout<<"\n";
		}
	else
		if(pozitie>3&&pozitie<=agenda->Lungime()-2)
		{
			for(p=agenda->primul,i=1;i<pozitie&&p!=NULL;i++) p=p->urmator;
			cout<<"   "; cout<<"("<<p->precedent->precedent->getTip()<<")"<<p->precedent->precedent->informatie->getAtribut()<<"\n   "<<p->precedent->precedent->informatie->getNume()<<" "<<p->precedent->precedent->informatie->getPrenume()<<"\n   "<<p->precedent->precedent->informatie->getNrTel()<<"\n\n";
			cout<<"   "; cout<<"("<<p->precedent->getTip()<<")"<<p->precedent->informatie->getAtribut()<<"\n   "<<p->precedent->informatie->getNume()<<" "<<p->precedent->informatie->getPrenume()<<"\n   "<<p->precedent->informatie->getNrTel()<<"\n\n";			
			cout<<"o->"; cout<<"("<<p->getTip()<<")"<<p->informatie->getAtribut()<<"\n   "<<p->informatie->getNume()<<" "<<p->informatie->getPrenume()<<"\n   "<<p->informatie->getNrTel()<<"\n\n";
			cout<<"   "; cout<<"("<<p->urmator->getTip()<<")"<<p->urmator->informatie->getAtribut()<<"\n   "<<p->urmator->informatie->getNume()<<" "<<p->urmator->informatie->getPrenume()<<"\n   "<<p->urmator->informatie->getNrTel()<<"\n\n";
			cout<<"   "; cout<<"("<<p->urmator->urmator->getTip()<<")"<<p->urmator->urmator->informatie->getAtribut()<<"\n   "<<p->urmator->urmator->informatie->getNume()<<" "<<p->urmator->urmator->informatie->getPrenume()<<"\n   "<<p->urmator->urmator->informatie->getNrTel()<<"\n\n";
		}
	else
		if(pozitie==agenda->Lungime()-1)
		{
			for(p=agenda->primul,i=1;i<pozitie&&p!=NULL;i++,p=p->urmator);
			cout<<"   "; cout<<"("<<p->precedent->precedent->precedent->getTip()<<")"<<p->precedent->precedent->precedent->informatie->getAtribut()<<"\n   "<<p->precedent->precedent->precedent->informatie->getNume()<<" "<<p->precedent->precedent->precedent->informatie->getPrenume()<<"\n   "<<p->precedent->precedent->precedent->informatie->getNrTel()<<"\n\n";
			cout<<"   "; cout<<"("<<p->precedent->precedent->getTip()<<")"<<p->precedent->precedent->informatie->getAtribut()<<"\n   "<<p->precedent->precedent->informatie->getNume()<<" "<<p->precedent->precedent->informatie->getPrenume()<<"\n   "<<p->precedent->precedent->informatie->getNrTel()<<"\n\n";
			cout<<"   "; cout<<"("<<p->precedent->getTip()<<")"<<p->precedent->informatie->getAtribut()<<"\n   "<<p->precedent->informatie->getNume()<<" "<<p->precedent->informatie->getPrenume()<<"\n   "<<p->precedent->informatie->getNrTel()<<"\n\n";			
			cout<<"o->"; cout<<"("<<p->getTip()<<")"<<p->informatie->getAtribut()<<"\n   "<<p->informatie->getNume()<<" "<<p->informatie->getPrenume()<<"\n   "<<p->informatie->getNrTel()<<"\n\n";
			cout<<"   "; cout<<"("<<p->urmator->getTip()<<")"<<p->urmator->informatie->getAtribut()<<"\n   "<<p->urmator->informatie->getNume()<<" "<<p->urmator->informatie->getPrenume()<<"\n   "<<p->urmator->informatie->getNrTel()<<"\n\n";
		}
		else
			if(pozitie==agenda->Lungime())
			{
				for(p=agenda->primul,i=1;i<pozitie&&p!=NULL;i++,p=p->urmator);
				cout<<"   "; cout<<"("<<p->precedent->precedent->precedent->precedent->getTip()<<")"<<p->precedent->precedent->precedent->precedent->informatie->getAtribut()<<"\n   "<<p->precedent->precedent->precedent->precedent->informatie->getNume()<<" "<<p->precedent->precedent->precedent->precedent->informatie->getPrenume()<<"\n   "<<p->precedent->precedent->precedent->precedent->informatie->getNrTel()<<"\n\n";
				cout<<"   "; cout<<"("<<p->precedent->precedent->precedent->getTip()<<")"<<p->precedent->precedent->precedent->informatie->getAtribut()<<"\n   "<<p->precedent->precedent->precedent->informatie->getNume()<<" "<<p->precedent->precedent->precedent->informatie->getPrenume()<<"\n   "<<p->precedent->precedent->precedent->informatie->getNrTel()<<"\n\n";
				cout<<"   "; cout<<"("<<p->precedent->precedent->getTip()<<")"<<p->precedent->precedent->informatie->getAtribut()<<"\n   "<<p->precedent->precedent->informatie->getNume()<<" "<<p->precedent->precedent->informatie->getPrenume()<<"\n   "<<p->precedent->precedent->informatie->getNrTel()<<"\n\n";
				cout<<"   "; cout<<"("<<p->precedent->getTip()<<")"<<p->precedent->informatie->getAtribut()<<"\n   "<<p->precedent->informatie->getNume()<<" "<<p->precedent->informatie->getPrenume()<<"\n   "<<p->precedent->informatie->getNrTel()<<"\n\n";			
				cout<<"o->"; cout<<"("<<p->getTip()<<")"<<p->informatie->getAtribut()<<"\n   "<<p->informatie->getNume()<<" "<<p->informatie->getPrenume()<<"\n   "<<p->informatie->getNrTel()<<"\n\n";
			}
}

void ViewC::showContacte(int pozitie)
{
	cout<<"*****************CONTACTE***************\n";
	cout<<"****************************************\n";
	cout<<agenda->ownerContact.getNume()<<" - "<<agenda->ownerContact.getPrenume()<<"\n";
	cout<<"****************************************\n";
	cout<<pozitie<<" din "<<agenda->Lungime()<<"\n";
	cout<<"****************************************\n";
	AfisareContacte(pozitie);
	cout<<"****************************************\n";	
}

void ControllerC::associateModel(Listac *a)
{
	agenda = a;
}

void ControllerC::associateView(IViewC *v)
{
	view = v;
}

void ControllerC::Filtreaza()
{
	ControllerC ctr;
	ViewC view(agenda->Filtrare(),&ctr);
	ctr.startContacte();
}

void ControllerC::SaltMVCSettings()
{
	ControllerS ctrl; 
	ViewS view(this->agenda->getContact(agenda->getP()),&ctrl); 
	agenda->setModificare(ctrl.startSettings());
}

void ControllerC::Cauta()
{
	ControllerC ctrl; 
	ViewC view(agenda->Cautare(),&ctrl);
	ctrl.startContacte();
}

void ControllerC::startContacte()
{
	char c=' ';
	char r=' ';

	while ( c != 'q' )
	{
		system("CLS");
		view->showContacte(agenda->getP());

		while ( ! ( (c=='q') || (c=='s') || (c=='w') || (c=='e') || (c=='d') || (c=='n') || (c=='f') || (c=='r') ) )
		{
			c = view->getUserOption();
		}

		if ( c == 'q' )
		{
			if(agenda->getModificare())
			{
				cout<<"Doriti sa salvati? (d/n)\n";
				cout<<"Raspuns: ";
				cin>>r;
			}
			if(r=='d')
				agenda->Salveaza();
			return;
		}
		
		switch(c) 
		{
			case 'w': agenda->setP(agenda->getP()-1) ; break;
			case 's': agenda->setP(agenda->getP()+1) ; break;
			case 'k': agenda->Salveaza(); break;
			case 'f': Filtreaza(); agenda->setModificare(false); break;
			case 'r': Cauta(); agenda->setModificare(false); break;
			case 'd': agenda->StergeContact(); break;
			case 'n': agenda->AdaugaContact(); break;
			case 'e': SaltMVCSettings(); break;
		}
		c = ' ' ;
	} 
	return;
}