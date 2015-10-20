#include"graf.h"
#include<iostream>
#include<stdio.h>

int main()
{
	Graf gr;
	creeaza(&gr,"graf.in");
	afisare(gr);

	este_arbore(gr);
	system("pause");
	return 0;
}
