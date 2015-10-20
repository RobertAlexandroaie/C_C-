#pragma once
#include "Agenda2Dlg.h"
#include "Agenda2.h"
#include "model_agenda.h"
#include "model_contact.h"
#include "Lista_Agende.h"
#include "adaugaAgenda.h"
#include "stergeAgenda.h"


class AgendeSingleton;
class CAgenda2Dlg;

class ControllerPrincipal 
{
protected:

	AgendeSingleton* model;	
	CAgenda2Dlg* view;		

public:
	
	void Asociaza(AgendeSingleton *m, CAgenda2Dlg *v);

	void incarcaAgendeInCB();

	void agendaNoua();

	void deschideAgenda();
	
	void salveazaAgendele();

	void salveazaLista();

	void stergeAgendaa();

	void incarcaDetalii();

	void incarcaDetalii(const CString& txt);
};