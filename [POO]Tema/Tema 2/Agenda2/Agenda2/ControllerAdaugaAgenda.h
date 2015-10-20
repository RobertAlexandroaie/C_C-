#pragma once

#include "Agenda2Dlg.h"
#include "model_agenda.h"
#include "model_contact.h"
#include "Lista_Agende.h"
#include "adaugaAgenda.h"

class AgendeSingleton;
class adaugaAgenda;

class ControllerAdaugaAgenda
{
public:
	AgendeSingleton *model;
	adaugaAgenda *view;		

	ControllerAdaugaAgenda();
	void Asociaza(AgendeSingleton *m, adaugaAgenda*v);
	
	void selectareDinFisier();
	void selectareNou();
	void selectareOK();
};