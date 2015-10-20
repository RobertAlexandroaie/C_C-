/*

     2.  Scrieţi un program, care, pentru o lună şi un an date, calculează numărul de zile din luna  
        respectivă (folosiţi o funcţie separată care verifică dacă un an este bisect). 
        Exemplu: pentru luna februarie din anul 2004, numărul de zile este 29. 

*/

#include<stdio.h>
#include<iostream>
#include<ctype.h>


int bisect(int an)
{
	if(((an%4==0)&&(an%100!=0))||(an%400==0)) return 1;
	else return 0;
}

int main()
{
	int an,l;
	char luna[15];
	
	printf("OBSERVATIE:Luna trebuie introdusa cu numele complet, cu litere mici!!!\nIntroduceti luna: ");
	scanf_s("%14s", luna,15);


	printf("Introduceti anul: ");
	scanf("%d", &an);
	
			
	l=0;

	if(strcmp(luna,"ianuarie")==0) l=1;
	if(strcmp(luna,"februarie")==0) l=2;
	if(strcmp(luna,"martie")==0) l=3;
	if(strcmp(luna,"aprilie")==0) l=4;
	if(strcmp(luna,"mai")==0) l=5;
	if(strcmp(luna,"iunie")==0) l=6;
	if(strcmp(luna,"iulie")==0) l=7;
	if(strcmp(luna,"august")==0) l=8;
	if(strcmp(luna,"septembrie")==0) l=9;
	if(strcmp(luna,"octombrie")==0) l=10;
	if(strcmp(luna,"noiembrie")==0) l=11;
	if(strcmp(luna,"decembrie")==0) l=12;


	if(l==2)
		if(bisect(an))
			printf("\nLuna are 29 zile.\n");
		else printf("\nLuna are 28 zile.\n");
	if(l<=7&&l!=2)
		if(l%2==0) printf("\nLuna are 30 zile.\n");
		else printf("\nLuna are 31 zile.\n");
	if(l>7)
		if(l%2==0) printf("\nLuna are 31 zile.\n");
		else printf("\nLuna are 30 zile.\n");

	
	system("pause");
	return 0;
}