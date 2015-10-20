#include "count.h"
#include <iostream>

Count::Count(char *name)
{
	owner = new string(name);
	sold = 0;
	assignCountNo();
}

Count::~Count()
{
	delete owner;
	releaseCountNo();
}

void Count::deposit(double ammount)
{
	sold += ammount;
}

void Count::draw(double amount)
{
	if(amount > sold) throw "Not enough money.";
	sold -= amount;
}


void Count::assignCountNo()
{
	// de implementat
}


void Count::releaseCountNo()
{
	// de implementat
}

double Count::balance()
{
	return sold;
}