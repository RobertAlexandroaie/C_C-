#pragma once

#include "Agenda2Dlg.h"
#include "model_agenda.h"
#include "model_contact.h"
#include "Lista_Agende.h"
#include "adaugaAgenda.h"
#include "adaugaContact.h"
#include "Contact.h"
#include "stergeContact.h"
#include "filtrareCautare.h"
#include "Strategy.h"

class Agenda;
class ModelAgenda;

class ControllerAgenda
{
protected:
	ModelAgenda* model;	// pointerul la model
	Agenda* view;		// pointer la dialogul  care joaca rol de View

public:

	// setarea canalelor de comunicatie
	void Asociaza(ModelAgenda *m, Agenda *v);
	
	void start();
	void contactNou();
	void editeazaContact();
	void salvareContacte();
	void FilCaut();
	void stergereContact();
	void incarcaDetalii();
	void incarcaDetalii(const CString& txt);
};