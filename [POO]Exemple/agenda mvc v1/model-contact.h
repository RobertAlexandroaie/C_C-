#ifndef MODEL_CONTACT_H
#define MODEL_CONTACT_H
#include <string>

using namespace std;

class Contact
{
public:
	Contact(char *  = "", char *  = "");
public:
	void modify();
public:
	string getName() {return name;}
public:
	string getPhoneNo() {return phoneNo;}
private:
	string name;
	string phoneNo;
};

#endif
