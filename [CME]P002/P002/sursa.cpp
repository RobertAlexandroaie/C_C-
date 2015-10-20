/*

Scrieti un program care sa realizeze intersectia a doua multimi a si b introduse prin doi vectori ce au n 
respectiv m elemente numere intregi, distincte.
Datele de intrare se vor citi de la tastatura. Rezultatele se vor afisa pe ecran.

*/

#include<iostream>
#include<stdio.h>

int main()
{
	int n,m,i,a[100],b[100],c[100],j=1,k=0;
	
	printf("Introduceti numarul de elemente ale primei multimi: ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}

	printf("Introduceti numarul de elemente ale celei de-a doua multimi: ");
	scanf("%d",&m);


	for(i=1;i<=m;i++)
	{
		printf("b[%d]=",i);
		scanf("%d",&b[i]);
	}

	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				c[++k]=a[i];

	printf("\n\nIntersectia celor doua multimie este formata din elementele: ");
	for(i=1;i<=k;i++)
		printf("%d ",c[i]);
	printf("\n\n");

	system("pause");
	return 0;
}