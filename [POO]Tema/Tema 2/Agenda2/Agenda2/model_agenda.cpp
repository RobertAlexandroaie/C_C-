#include "model_agenda.h"

Type tip;

ModelAgenda::~ModelAgenda()
{
	Contacte.clear();

}

ModelAgenda::ModelAgenda()
{
	Contacte.clear();
}

ModelAgenda::ModelAgenda(ModelAgenda& ag)
{
	nume_proprietar=ag.nume_proprietar;
	prenume_proprietar=ag.prenume_proprietar;
	nr_tel_proprietar=ag.nr_tel_proprietar;

	std::list<ModelContact*>::iterator i;
	i=ag.Contacte.begin();
	for(;i!=ag.Contacte.end();++i)
	{
		Contacte.push_back((*i));
	}
}

ModelAgenda::ModelAgenda(CString nume_fisier)
{
	this->incarcaContacte(nume_fisier);
}

bool ModelAgenda::addContact( ModelContact *contact_de_adaugat)
{
	this->Contacte.push_back(contact_de_adaugat);
	return true;
}

bool ModelAgenda::addContact( const Type& option , CString data[4])
{
	ConcreteContactCreator c(data);
	this->addContact(c.createContact(option));
	return true;
}

bool ModelAgenda::incarcaContacte(CString nume_fisier)
{
	std::ifstream fin(nume_fisier.GetBuffer(nume_fisier.GetLength()));

	if(!fin.is_open())
		return false;

	char linie[100];
	fin.getline(linie,100);

	CString text;
	text=linie;

	CString rezToken[4];
	int curPos = 0;
	
	rezToken[0]= text.Tokenize(_T("|"),curPos);
	int i=0;
	while (rezToken[i] != _T(""))
	{
		++i;
		rezToken[i] = text.Tokenize(_T("|"), curPos);
	}

	this->nume_proprietar=rezToken[0];
	this->prenume_proprietar=rezToken[1];
	this->nr_tel_proprietar=rezToken[2];

	while(fin.getline(linie,100))
	{
		char t=linie[0];
		strcpy(linie,linie+2);
		text=linie;

		CString resToken[5];
		int curPos = 0;
	
		resToken[0]= text.Tokenize(_T("|"),curPos);
		int i=0;
		while (resToken[i] != _T(""))
		{
			++i;
			resToken[i] = text.Tokenize(_T("|"), curPos);
		}
		ConcreteContactCreator c(resToken);

		if(t=='a')
		{
			tip=Acquaintance;
		}
		
		if(t=='c')
		{
			tip=Colleague;
		}

		if(t=='f')
		{
			tip=Friend;
		}

		this->addContact(c.createContact(tip));
	}
	fin.close();

	return true;
}

bool ModelAgenda::incarcaContacte()
{
	CString nume_fisier;
	nume_fisier=nume_proprietar+_T("|")+prenume_proprietar+_T(".txt");

	if(incarcaContacte(nume_fisier))
		return true;
	else
		return false;
}

bool ModelAgenda::salvareContacte()
{
	CString nume_fisier;
	nume_fisier=nume_proprietar+_T("!")+prenume_proprietar+_T(".txt");

	char fisier[200];
	strcpy(fisier,nume_fisier.GetBuffer());
	std::ofstream fout(fisier);

	if(!fout.is_open())
		return false;
	CString lin;
	lin=nume_proprietar+_T("|")+prenume_proprietar+_T("|")+nr_tel_proprietar;
	char linie[200];
	strcpy(linie,lin.GetBuffer());
	fout<<linie<<"\n";
	
	fout.close();
	std::list<ModelContact *>::iterator i;
	for(i=Contacte.begin();i!=Contacte.end();++i)
		(*i)->salvare(nume_fisier);

	return true;
}

CString ModelAgenda::toCStringnp()
{
	CString text;
	text=nume_proprietar+_T(" ")+prenume_proprietar;
	return text;
}