#ifndef MODEL_CONTACT_H
#define MODEL_CONTACT_H
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
	string getName() {return name;}
public:
	void setName(string newName) 
	{
		name = newName;
	}
public:
	string getPhoneNo() {return phoneNo;}
public:
	void setPhoneNo(string newPhoneNo) 
	{
		phoneNo = newPhoneNo;
	}
private:
	string name;
	string phoneNo;
};

#endif