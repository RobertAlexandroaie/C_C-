/*

Permutare circulara de "p" elemente intr-un tablou de "n" numere.

*/

#include<iostream>
#include<stdio.h>



int main()
{
	int a[100],b[100],i,j,aux,n,p;

	printf("Introduceti numarul de valori: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
		b[i]=0;
	}

	printf("Introduceti numarul de permutari: ");
	scanf("%d",&p);

	for(j=0,i=p;i<n;i++)
		b[j++]=a[i];
	for(i=0;i<p;i++)
		b[j++]=a[i];
	
	printf("Sirul permutat este: ");
	for(i=0;i<n;i++)
		printf("%d",b[i]);
	printf("\n\n\n");

	system("pause");
	return 0;
}
