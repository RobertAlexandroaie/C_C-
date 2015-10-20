#ifndef MODEL_AGENDA_H
#define MODEL_AGENDA_H
#include <string>
#include "model-contact.h"

using namespace std;

class Agenda
{
public:
	Agenda(char*);
public:
	~Agenda();
public:
	void display();
public:
	string getOwner();
private:
	string owner;
private:
	Contact contact;
};

#endif