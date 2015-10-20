#ifndef DISPLAY_BOX_SRING_H
#define DISPLAY_BOX_SRING_H
#include <iostream>
#include <string>

using namespace std;

class DisplayBoxString
{
private:
	string label;
private:
	string value;
public:
	DisplayBoxString(char *newLabel = "")
	{
		label = newLabel;
	}
	void setLabel(string newLabel)
	{
		label = newLabel;
	}
	void setValue(string newValue)
	{
		value = newValue;
	}
	void display()
	{
		cout << label.c_str() << ":  " << value.c_str() << endl;
	}
};

#endif
