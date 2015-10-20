/*

     6.  Scrieţi un program C care citeşte elementele unei matrici pătratice şi interschimbă liniile şi  
         coloanele acesteia astfel încât, în matricea finală, elementele de pe diagonala principală să fie  
         în ordine descrescătoare. Să se afişeze matricea iniţială şi matricea după fiecare operaţie. 
         Exemplu: pentru matricea 
         1 4 
         3 2 
         se vor afişa, pe rând, matricile 
         1 4    4 1    2 3 
         3 2    2 3    4 1.

*/

#include<iostream>
#include<stdio.h>

int a[100][100],n;

void citiremp(int a[][100], int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
}

void afisaremp(int a[][100], int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}

void interschimbal(int i, int j)
{
	int aux;
	for(int k=0;k<n;k++)
	{
		aux=a[i][k];
		a[i][k]=a[j][k];
		a[j][k]=aux;
	}
}

void interschimbac(int i,int j)
{
	int aux;
	for(int k=0;k<n;k++)
	{
		aux=a[k][i];
		a[k][i]=a[k][j];
		a[k][j]=aux;
	}
}

int main()
{
	printf("Introduceti numarul de linii si coloane: ");
	scanf("%d", &n);

	citiremp(a,n);
	afisaremp(a,n);
	printf("\n\n");

	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if((a[i][i])<a[j][j])
			{
				interschimbac(i,j);
				afisaremp(a,n);
				printf("\n");

				interschimbal(i,j);
				afisaremp(a,n);
				printf("\n");
			}

	
	system("pause");
	return 0;
}