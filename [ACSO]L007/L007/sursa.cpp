/*
Sa se scrie în limbaj de asamblare o functie definita astfel: 

void minor(int *src,int *dst,int dim,int x,int y); 

unde src si dst reprezinta adresele de început ale unor matrici patratice, de dimensiuni dim × dim., 
respectiv (dim - 1) × (dim - 1). 
Functia depune în matricea dst elementele submatricii obtinute din matricea src prin 
eliminarea liniei x si a coloanei y. 
*/

#include<stdio.h>
#include<iostream>

void minor(int *src,int *dst,int dim,int x,int y)
{
	int i,j,l,c;
	for(i=0;i<dim;i++)
		for(j=0;j<dim;j++)
			if(i!=x&&j!=y)
				
}

int main()
{
	int **m,**min;
	int *src,*dst;
	int n;
	int x,y;

	int i,j;

	printf("Dimensiunea matricii este: n=");
	scanf("%d",&n);

	m=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
	{
		m[i]=(int *)malloc(n*sizeof(int));
	}

	min=(int **)malloc((n-1)*sizeof(int *));
	for(i=0;i<n;i++)
	{
		min[i]=(int *)malloc((n-1)*sizeof(int));
	}

	src=&m[0][0];
	dst=&min[0][0];

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			printf("m[%d][%d]=",i,j);
			scanf("%d",&m[i][j]);
		}

	printf("Se elimina linia: x=");
	scanf("%d",&x);
	
	printf("Se elimina coloana: y=");
	scanf("%d",&y);
	
	minor(src,dst,n,x,y);

	system("pause");
	return 0;
}