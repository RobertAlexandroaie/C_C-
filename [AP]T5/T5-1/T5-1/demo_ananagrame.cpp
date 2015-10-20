#include<iostream>
#include<stdio.h>
#include<string>
#include<ctype.h>
#include"ananagrame.h"

nodcuv *cuvinte1[20];

int main()
{
	creare_cuvinte(cuvinte1,"scrable.in");
	afisare_cuv(cuvinte1);
	//printf("\n\n\n");

	scrie_ananagrame("scrable.out");

	system("pause");
	return 0;
}