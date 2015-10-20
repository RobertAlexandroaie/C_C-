/*

dimensiune p,q

*/

#include<stdio.h>
#include<iostream>

int main()
{
	char p[]="abcdefghi";
	char* q=p;

	printf("Dimensiunea lui p: %d.\n", sizeof(p));
	printf("Dimensiunea lui q: %d.\n",sizeof(q));

	system("pause");
	return 0;
}