#pragma once

#include <cstring>
#include "stdafx.h"
#include <list>
#include "model_contact.h"
#include <fstream>

class ModelAgenda
{
public:
	CString nume_proprietar;
	CString prenume_proprietar;
	CString nr_tel_proprietar;
	std::list<ModelContact*> Contacte;   // lista de contacte

	ModelAgenda();
	ModelAgenda(ModelAgenda& ag);
	ModelAgenda(CString nume_fisier);
	ModelAgenda(CString nume_nou, CString prenume_nou, CString nr_tel_nou) : nume_proprietar(nume_nou), prenume_proprietar(prenume_nou), nr_tel_proprietar(nr_tel_nou) {}
	~ModelAgenda();


	bool addContact( const Type& option , CString data[4]);
	bool addContact( ModelContact *contact_de_adaugat);
	bool incarcaContacte(CString nume_fisier);
	bool incarcaContacte();
	bool salvareContacte();
	ModelContact* searchContact(CString text);
	CString toCStringnp();
};

