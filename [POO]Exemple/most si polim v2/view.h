#ifndef VIEW_H
#define VIEW_H
#include "contact.h"
#include <iostream>

using namespace std;

class View
{
public:
	View(Contact *newContact = 0)
	{
		contact = newContact;
	}
public:
	void displayContact()
	{
		cout << contact->toString();
	}
public:
	void setContact(Contact *newContact)
	{
		contact = newContact;
	}
private:
	Contact *contact;
};
#endif

