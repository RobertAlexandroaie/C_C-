/*
1. Se citeşte un tablou de numere întregi. Scrieţi o funcţie care să determine diferenţa maximă (în 
modul) dintre oricare două elemente ale vectorului.
Exemplu: pentru tabloul (-1, 3, 2, 7, 11, 3, 2), diferenta maximă (în modul) este 12.
Observaţie: Punctajul maxim va fi acordat soluţiilor cu complexitatea timp O(n).

*/


#include<limits.h>
#include<math.h>
#include<iostream>
#include<stdio.h>

int min=INT_MAX, max=INT_MIN;
int n, v[100];

void citire(int a[])
{
	int i;	

	printf("Introduceti numarul maxim de numere: ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{	
		printf("v[%d]=",i);
		scanf("%d", &v[i]);
		if(v[i]>max) max=v[i];
		if(v[i]<min) min=v[i];
	}
}

int difMax(int a[])
{
	int i,dif;

	for(i=0;i<n;i++)
	{	
		if(v[i]>max) max=v[i];
		if(v[i]<min) min=v[i];
	}

	dif=abs(max-min);
	return dif;
}


int main()
{
	citire(v);
	printf("Diferenta maxima este: %d.\n\n", difMax(v));
	system("pause");
	return 0;
}