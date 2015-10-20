#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>

using namespace std;

class Menu
{
private:
	string options[25];
private:
	int size;
public:
	Menu::Menu()
	{
		size = 0;
	}
public:
	void addOption(char *newOption)
	{
		options[size++] = string(newOption);
	}
public:
	void display()
	{
		int i;
		cout << "Menu:" << endl;
		for (i = 0; i < size; ++i)
			cout << options[i].c_str() << endl;
	}
public:
	int getOption()
	{
		int option;
		cout << "Option: ";
		cin >> option;
		return option;
	}
};
#endif

