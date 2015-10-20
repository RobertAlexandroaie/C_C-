#pragma once

#include "stdafx.h"
#include "CString"
#include "list"
#include "Agenda2.h"
#include "ControllerFilCaut.h"
#include "filtrareCautare.h"
#include "model_agenda.h"
#include "model_contact.h"
#include "Agenda.h"

class ModelAgenda;
class ModelContact;
class filtrareCautare;
class Agenda;

typedef enum Strategie {cautare=0, filtrare};

// strategie pentru creare lista noua in urma unui algoritm de: -cautare sau -filtrare 
class Strategy 
{ 
public:
	ModelAgenda* model;	
	filtrareCautare* view;	
	// setarea canalelor de comunicatie
	void Asociaza( ModelAgenda* m ,  filtrareCautare* v );

public:
	Strategy()  {}
	virtual void ListaNoua () = 0;  // creare lista noua 
};

// algoritm de cautare
class searchStrategy : public Strategy 
{
public:
	searchStrategy() : Strategy() {}

	void ListaNoua ();
	
};


// algoritm de filtrare
class filterStrategy: public Strategy 
{
public:
	filterStrategy() : Strategy() {}

	void ListaNoua ();
	
};

// clasa context stabileste contextul in care sa se execute algoritmul corespunzator
class Context  
{
public:
	Strategie tip;
	Strategy *strt;

	Context(Strategie tip_nou);
	void Asociaza(ModelAgenda* m, filtrareCautare *v);
	void setStrategie(Strategie str);
	void DoStrategy();
};