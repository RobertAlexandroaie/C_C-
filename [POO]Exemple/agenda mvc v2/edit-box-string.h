#ifndef EDIT_BOX_SRING_H
#define EDIT_BOX_SRING_H
#include <iostream>
#include <string>

using namespace std;

class EditBoxString
{
private:
	string label;
public:
	EditBoxString(char *newLabel = "")
	{
		label = newLabel;
	}
	void setLabel(string newLabel)
	{
		label = newLabel;
	}
	string getValue()
	{
		char buffer[80];
		cout << label.c_str() << ":  ";
		cin >> buffer;
		return string(buffer);
	}
};

#endif
