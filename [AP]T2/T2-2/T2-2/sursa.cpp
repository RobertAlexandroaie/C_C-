/*
2. Se citeşte un tablou de numere întregi. Să se determine, printr-o singură parcurgere a sa, 
poziţia de început şi lungimea celei mai lungi secvenţe de elemente egale. Dacă există mai 
multe secvente de lungimi egale, se va determina secventa cu pozitia de început minimă.
Exemplu: pentru tabloul (1, 2, 3, 3, 3, 2, 1, 5, 5, 5), se vor determina poziţia 2 şi lungimea 3.
*/

#include<stdio.h>
#include<iostream>

int main()
{
	int n,a[100],i=0,j=0,poz=0,secv=1,secv_max=0;

	printf("Introduceti numarul de valori: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}

	i=0;
	do
	{
		j=i+1;
		secv=2;
		while(a[i]==a[j])
		{
			j++;
			secv++;
		}
		if(secv>secv_max)
		{
			secv_max=secv;
			poz=i;
		}
		i=j;
	}while(i<n-1);

	secv_max--;

	printf("Pozitia este: %d. Secventa are lungimea: %d.\n",poz,secv_max);
	system("pause");
	return 0;
}