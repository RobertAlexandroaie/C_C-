#include<iostream>
#include<fstream>
#include<string.h>

#include"contact.h"

using namespace std;

Contact::Contact(const Contact &c)
{
	strcpy(this->Nume,c.Nume);
	strcpy(this->Prenume,c.Prenume);
	strcpy(this->NrTel,c.NrTel);
}

Contact::Contact(const char* nume,const char* prenume,const char* nrtel)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	strcpy(Prenume,prenume);
	Prenume[0]=toupper(Prenume[0]);

	strcpy(NrTel,nrtel);
	NrTel[0]=toupper(NrTel[0]);
}

Contact::Contact(const char* nume,const char *prenume)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	strcpy(Prenume,prenume);
	Prenume[0]=toupper(Prenume[0]);

	NrTel[0]=NULL;
}

Contact::Contact(const char* nume)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	Prenume[0]=NULL;
	NrTel[0]=NULL;
}

Contact::Contact()
{
	strcpy(Nume,"");
	strcpy(Prenume,"");
	strcpy(NrTel,"");
}

Contact::~Contact()
{
	cout<<"Destructor contact!";
}

void Contact::Afisare()
{
	if(Nume[0]!=NULL) cout<<Nume;
	if(Prenume[0]!=NULL) cout<<" - "<<Prenume<<"\n";
	if(NrTel[0]!=NULL) cout<<"   "<<NrTel<<"\n";
}

char* Contact::getNume() const
{
	char *nume=new char[21];
	strcpy(nume,Nume);
	return nume;
}

char* Contact::getPrenume() const
{
	char *pren=new char[21];
	strcpy(pren,Prenume);
	return pren;
}

char* Contact::getNrTel() const
{
	char *nr=new char[21];
	strcpy(nr,NrTel);
	return nr;
}

void Contact::setNume(char *nume)
{
	if(nume[0]!=NULL) strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);
}

void Contact::setPrenume(char *prenume)
{
	if(prenume[0]!=NULL) strcpy(Prenume,prenume);
	Prenume[0]=toupper(Prenume[0]);
}

char *Contact::getAtribut()
{
	return "";
}

void Contact::setNrTel(char *nrtel)
{
	if(nrtel[0]!=NULL) strcpy(NrTel,nrtel);
}

void Contact::Salveaza(char *fisier)
{
	ofstream fout(fisier,ios::app);
	fout<<"n|"<<Nume<<"|"<<Prenume<<"|"<<NrTel<<"\n";
}

void Contact::Incarca(char *linie)
{
	char *cuvant;

	cuvant=strtok(linie,"|");
	if(cuvant!=NULL)
		this->setNume(cuvant);

	if(cuvant!=NULL) cuvant=strtok(NULL,"|");
	if(cuvant!=NULL)
		this->setPrenume(cuvant);

	if(cuvant!=NULL) cuvant=strtok(NULL,"|");
	if(cuvant!=NULL)
		this->setNrTel(cuvant);
}

bool Contact::Switch(char &caz,char *s)
{
	switch(caz) 
	{ 
		case 'n' : setNume(s) ; break; 
		case 'p' : setPrenume(s); break; 
		case 't' : setNrTel(s); break;
		case 'a' : cout<<"Contactul nu are alte atribute.\n"; break;
	}
	caz=' ';
	return true;
}

//--------------------------------------------------------------------------------------------------------------------------

Colleague::Colleague(const Contact &c)
{
	strcpy(Nume,c.getNume());
	strcpy(Prenume,c.getPrenume());
	strcpy(NrTel,c.getNrTel());
	Categorie[0]=NULL;
}

Colleague::Colleague(const Colleague &c)
{
	strcpy(Nume,c.getNume());
	strcpy(Prenume,c.getPrenume());
	strcpy(NrTel,c.getNrTel());
	strcpy(Categorie,c.getCategorie());
}

Colleague::Colleague(const char *nume,const char *prenume,const char *nrtel,const char *categorie)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	strcpy(Prenume,prenume);
	Prenume[0]=toupper(Prenume[0]);

	strcpy(NrTel,nrtel);

	strcpy(Categorie,categorie);
	Categorie[0]=toupper(Categorie[0]);
}

Colleague::Colleague(const char *nume,const char *prenume,const char *nrtel)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	strcpy(Prenume,prenume);
	Prenume[0]=toupper(Prenume[0]);

	strcpy(NrTel,nrtel);
	NrTel[0]=toupper(NrTel[0]);
	
	strcpy(Categorie,"");
}

Colleague::Colleague(const char *nume,const char *prenume)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	strcpy(Prenume,prenume);
	Prenume[0]=toupper(Prenume[0]);

	strcpy(NrTel,"");
	strcpy(Categorie,"");
}

Colleague::Colleague(const char *nume)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);
	
	strcpy(Prenume,"");
	strcpy(NrTel,"");
	strcpy(Categorie,"");
}

Colleague::Colleague()
{
	strcpy(Nume,"");
	strcpy(Prenume,"");
	strcpy(NrTel,"");
	strcpy(Categorie,"");
}

char *Colleague::getCategorie() const
{
	char *categorie=new char;
	strcpy(categorie,Categorie);
	return categorie;	
}

char* Colleague::getAtribut()
{
	return Categorie;
}

void Colleague::Afisare()
{
	cout<<"(c)";
	if(Categorie[0]!=NULL) cout<<Categorie<<"\n";
	if(Nume[0]!=NULL) cout<<Nume;
	if(Prenume[0]!=NULL) cout<<" "<<Prenume<<"\n";
	if(NrTel[0]!=NULL) cout<<" "<<NrTel<<"\n";
}

void Colleague::setCategorie(const char *categorie)
{
	if(categorie[0]!=NULL) strcpy(Categorie,categorie);
	Categorie[0]=toupper(Categorie[0]);
}

void Colleague::Salveaza(char *fisier)
{
	ofstream fout(fisier,ios::app);
	fout<<"c|"<<Nume<<"|"<<Prenume<<"|"<<NrTel<<"|"<<Categorie<<"\n";
}

void Colleague::Incarca(char *linie)
{
	char *cuvant;

	cuvant=strtok(linie,"|");
	if(cuvant!=NULL)
		this->setNume(cuvant);

	if(cuvant!=NULL) cuvant=strtok(NULL,"|");
	if(cuvant!=NULL)
		this->setPrenume(cuvant);

	if(cuvant!=NULL) cuvant=strtok(NULL,"|");
	if(cuvant!=NULL)
		this->setNrTel(cuvant);

	if(cuvant!=NULL) cuvant=strtok(NULL,"|");
	if(cuvant!=NULL)
		this->setCategorie(cuvant);
}

bool Colleague::Switch(char &caz,char *s)
{
	switch(caz)
	{ 
		case 'n' : setNume(s); break; 
		case 'p' : setPrenume(s); break; 
		case 't' : setNrTel(s); break;
		case 'a' : setCategorie(s); break;
	}
	caz=' ';
	return true;
}

//----------------------------------------------------------------------------------------------------------------------------

Friend::Friend(const Contact &c)
{
	strcpy(Nume,c.getNume());
	strcpy(Prenume,c.getPrenume());
	strcpy(NrTel,c.getNrTel());
	Data[0]=NULL;
}

Friend::Friend(const Friend &f)
{
	strcpy(Nume,f.getNume());
	strcpy(Prenume,f.getPrenume());
	strcpy(NrTel,f.getNrTel());
	strcpy(Data,f.getData());
}

Friend::Friend(char *nume,char *prenume,char *nrtel,char *data)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	strcpy(Prenume,prenume);
	Prenume[0]=toupper(Prenume[0]);

	strcpy(NrTel,nrtel);

	strcpy(Data,data);
}

Friend::Friend(char *nume,char *prenume,char *nrtel)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	strcpy(Prenume,prenume);
	Prenume[0]=toupper(Prenume[0]);

	strcpy(NrTel,nrtel);
	
	strcpy(Data,"");
}

Friend::Friend(char *nume,char *prenume)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	strcpy(Prenume,prenume);
	Prenume[0]=toupper(Prenume[0]);
	
	strcpy(NrTel,"");
	strcpy(Data,"");
}

Friend::Friend(char *nume)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	strcpy(Prenume,"");
	strcpy(NrTel,"");
	strcpy(Data,"");
}

Friend::Friend()
{
	strcpy(Nume,"");
	strcpy(Prenume,"");
	strcpy(NrTel,"");
	strcpy(Data,"");
}

void Friend::Afisare()
{
	cout<<"(f)";
	if(Data[0]!=NULL) cout<<Data<<"\n";
	if(Nume[0]!=NULL) cout<<Nume;
	if(Prenume[0]!=NULL) cout<<" "<<Prenume<<"\n";
	if(NrTel[0]!=NULL) cout<<"   "<<NrTel<<"\n";
}

char *Friend::getData() const
{
	char *data=new char;
	strcpy(data,Data);
	return data;
}

char* Friend::getAtribut()
{
	return Data;
}

void Friend::setData(const char *data)
{
	if(data[0]!=NULL) strcpy(Data,data);
}

void Friend::Salveaza(char *fisier)
{
	ofstream fout(fisier,ios::app);
	fout<<"f|"<<Nume<<"|"<<Prenume<<"|"<<NrTel<<"|"<<Data<<"\n";
}

void Friend::Incarca(char *linie)
{
	char *cuvant;

	cuvant=strtok(linie,"|");
	if(cuvant!=NULL)
		this->setNume(cuvant);

	if(cuvant!=NULL) cuvant=strtok(NULL,"|");
	if(cuvant!=NULL)
		this->setPrenume(cuvant);

	if(cuvant!=NULL) cuvant=strtok(NULL,"|");
	if(cuvant!=NULL)
		this->setNrTel(cuvant);

	if(cuvant!=NULL) cuvant=strtok(NULL,"|");
	if(cuvant!=NULL)
		this->setData(cuvant);
}

bool Friend::Switch(char &caz,char *s)
{
	switch(caz) 
	{ 
		case 'n' : setNume(s); break; 
		case 'p' : setPrenume(s); break; 
		case 't' : setNrTel(s); break;
		case 'a' : setData(s); break;
	}
	caz=' ';
	return true;
}

//----------------------------------------------------------------------------------------------------------------------------

Acquaintance::Acquaintance(const Acquaintance &a)
{
	strcpy(Nume,a.getNume());
	strcpy(Prenume,a.getPrenume());
	strcpy(NrTel,a.getNrTel());
	strcpy(Profesie,a.getProfesie());
}

Acquaintance::Acquaintance(const Contact &c)
{
	strcpy(Nume,c.getNume());
	strcpy(Prenume,c.getPrenume());
	strcpy(NrTel,c.getNrTel());
	Profesie[0]=NULL;
}

Acquaintance::Acquaintance(char *nume,char *prenume,char *nrtel,char *profesie)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	strcpy(Prenume,prenume);
	Prenume[0]=toupper(Prenume[0]);

	strcpy(NrTel,nrtel);

	strcpy(Profesie,profesie);
	Profesie[0]=toupper(Profesie[0]);
}

Acquaintance::Acquaintance(char *nume,char *prenume,char *nrtel)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	strcpy(Prenume,prenume);
	Prenume[0]=toupper(Prenume[0]);

	strcpy(NrTel,nrtel);
	
	strcpy(Profesie,"");
}

Acquaintance::Acquaintance(char *nume,char *prenume)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);

	strcpy(Prenume,prenume);
	Prenume[0]=toupper(Prenume[0]);
	
	strcpy(NrTel,"");
	strcpy(Profesie,"");
}

Acquaintance::Acquaintance(char *nume)
{
	strcpy(Nume,nume);
	Nume[0]=toupper(Nume[0]);
	
	strcpy(Prenume,"");
	strcpy(NrTel,"");
	strcpy(Profesie,"");
}

Acquaintance::Acquaintance()
{
	strcpy(Nume,"");
	strcpy(Prenume,"");
	strcpy(NrTel,"");
	strcpy(Profesie,"");
}

void Acquaintance::Afisare()
{
	cout<<"(a)";
	if(Profesie[0]!=NULL) cout<<Profesie<<"\n";
	if(Nume[0]!=NULL) cout<<Nume;
	if(Prenume[0]!=NULL) cout<<" "<<Prenume<<"\n";
	if(NrTel[0]!=NULL) cout<<"   "<<NrTel<<"\n";
}

void Acquaintance::setProfesie(const char *profesie)
{
	if(profesie[0]!=NULL) strcpy(Profesie,profesie);
	Profesie[0]=toupper(Profesie[0]);
}

char *Acquaintance::getProfesie() const
{
	char *profesie=new char;
	strcpy(profesie,Profesie);
	return profesie;
}

char* Acquaintance::getAtribut()
{
	return Profesie;
}

void Acquaintance::Salveaza(char *fisier)
{
	ofstream fout(fisier,ios::app);
	fout<<"a|"<<Nume<<"|"<<Prenume<<"|"<<NrTel<<"|"<<Profesie<<"\n";
}

void Acquaintance::Incarca(char *linie)
{
	char *cuv=strtok(linie,"|");
	
	if(cuv!=NULL)
		strcpy(Nume,cuv);
	
	if(cuv!=NULL) cuv=strtok(NULL,"|");	
	if(cuv!=NULL)
		strcpy(Prenume,cuv);

	if(cuv!=NULL) cuv=strtok(NULL,"|");
	if(cuv!=NULL)
		strcpy(NrTel,cuv);

	if(cuv!=NULL) cuv=strtok(NULL,"|");
	if(cuv!=NULL)
		strcpy(Profesie,cuv);
}

bool Acquaintance::Switch(char &caz,char *s)
{
	switch(caz) 
	{ 
		case 'n' : setNume(s); break; 
		case 'p' : setPrenume(s); break; 
		case 't' : setNrTel(s); break;
		case 'a' : setProfesie(s); break;
	}
	caz=' ';
	return true;
}
