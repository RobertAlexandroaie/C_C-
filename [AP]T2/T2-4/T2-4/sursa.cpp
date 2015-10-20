/*

     4.  Se citeşte un tablou de numere întregi. Să se rearanjeze elementele astfel încât cele pare sa  
         apară înaintea celor impare. În cadrul subsecvenţei de numere pare, respectiv impare,  
         elementele trebuie sa apară în ordinea în care erau în tabloul iniţial. 
         Exemplu: tabloul (2, 3, -4, -2, 9, -2, 1, 7, -3) va fi rearanjat în (2, -4, -2, -2, 3, 9, 1, 7, -3).
*/

#include<iostream>
#include<stdio.h>

int main()
{
	int n,i,j=0,a[100],b[100];

	printf("Introduceti numarul de elemente: ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("a[%d]=", i);
		scanf("%d", &a[i]);
	}
	
	for(i=0;i<n;i++)
		if(a[i]%2==0) b[j++]=a[i];
	for(i=0;i<n;i++)
		if(a[i]%2!=0) b[j++]=a[i];

	printf("\nSirul final: ");
	for(i=0;i<n;i++) printf("%d, ",b[i]);
	
	printf("\n\n\n");
	system("pause");
	return 0;
}