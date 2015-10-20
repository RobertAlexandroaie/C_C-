#pragma once
#include "model_agenda.h"
#include "model_contact.h"
#include <list>
#include <fstream>

class AgendeSingleton 
{
private:
	static AgendeSingleton instanta;

	AgendeSingleton(std::list<ModelAgenda*> lista_noua) : Agende(lista_noua) { }

	void operator=(AgendeSingleton&);
	AgendeSingleton(const AgendeSingleton&);

public:
	AgendeSingleton();

	std::list<ModelAgenda*> Agende;

	static AgendeSingleton& instance()
	{
		return instanta;
	}

	bool salveaza();

	bool incarca();

};