#pragma once

#include "Agenda2Dlg.h"
#include "model_agenda.h"
#include "model_contact.h"
#include "Lista_Agende.h"
#include "adaugaAgenda.h"
#include "adaugaContact.h"
#include "Contact.h"

class ModelContact;
class Contact;

class ControllerContact
{
public:
	ModelContact *model;
	Contact  *view;

	void Asociaza(ModelContact *m, Contact *v);
	void start();
	void selecteazaPrieten();
	void selecteazaColeg();
	void selecteazaCunostinta();
	void selecteazaOk();
};