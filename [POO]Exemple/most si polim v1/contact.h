#ifndef CONTACT_H
#define CONTACT_H
#include <string>

using namespace std;

class Contact
{
public:
	Contact(char *newName = "", char *newNo = "")
	{
		name = string(newName);
		phoneNo = string(newNo);
	}

public:
	string toString()
	{
		return string("Contact:\n") + 
		       string("Nume: ") + name + string("\n") +
		       string("Numar: ") + phoneNo + string("\n");
	}
protected:
	string name;
protected:
	string phoneNo;
};

class Acquiantance : public Contact
{
public:
	Acquiantance(char *newName = "", char *newNo = "", char *newOccupation = "")
		: Contact(newName, newNo)
	{
		occupation = string(newOccupation);
	}
public:
	string toString()
	{
		return Contact::toString() +
		       string("Occupation: ") + occupation + string("\n");
	}
protected:
	string occupation;
};

class Friend : public Contact
{
public:
	Friend(char *newName = "", char *newNo = "", char *newBirthdate = "")
		: Contact(newName, newNo)
	{
		birthdate = string(newBirthdate);
	}
public:
	string toString()
	{
		return Contact::toString() +
		       string("Birthdate: ") + birthdate + string("\n");
	}
protected:
	string birthdate;
};

#endif
