#pragma once

#include "Agenda2Dlg.h"
#include "model_agenda.h"
#include "model_contact.h"
#include "Lista_Agende.h"
#include "adaugaAgenda.h"
#include "adaugaContact.h"

class ModelAgenda;
class adaugaContact;

class ControllerAdaugaContact
{
public:
	ModelAgenda *model;
	adaugaContact *view;
	
	void Asociaza(ModelAgenda *m, adaugaContact *v);
	void start();

	void selecteazaPrieten();
	void selecteazaColeg();
	void selecteazaCunostinta();
	void selecteazaOk();
};