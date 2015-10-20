#include "model-contact.h"
#include <iostream>

using namespace std;

Contact::Contact(char *newName, char *newNo)
{
	name = string(newName);
	phoneNo = string(newNo);
}

void Contact::modify()
{
	char buffer[80];
	cout << "Nume: ";
	cin >> buffer;
	name = string(buffer);
	cout << "Numar telefon: ";
	cin >> buffer;
	phoneNo = string(buffer);
}
