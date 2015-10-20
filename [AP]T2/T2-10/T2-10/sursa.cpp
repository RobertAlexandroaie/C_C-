/*

10.Să se definească un tip Multime ce conţine elemente numere întregi de la 0 la 31. Să se  
   definească funcţiile de reuniune, intersecţie, diferenţă şi complementara unei mulţimi, utilizand  
   operatii pe biţi. Prototipurile acestor funcţii sunt: 

   Multime reuniune(Multime X, Multime Y);  
   Multime intersectie(Multime X, Multime Y);  
   Multime diferenta(Multime X, Multime Y);  
   Multime complementara(Multime X); 

   Exemplu: pentru mulţimile care conţin numerele întregi A(5, 7, 31) şi, respectiv, B(3, 7),  
   reuniunea este (3, 5, 7, 31), intersecţia este (7), diferenţa A-B este (5, 31), iar complementara  
   lui A este (0 … 4, 6, 8 … 30). 


*/
#include<iostream>
#include<stdio.h>


typedef unsigned Multime;
Multime X,Y,M;

void af(Multime A)
{
     int i,j;
     printf("{ ");
     for(i=0,j=0;i<=31;i++)
		 if(A&1<<i)
		 {
			 j++;            
			 if(i<=31&&j>1)
				 printf(", ");
			 printf("%d ",i);   			 
		 }
	printf("}");
}

void intersectie(Multime X,Multime Y)
{
	M=X&Y;
	af(M);
}

void reuniune(Multime X,Multime Y)
{
	M=X|Y;
	af(M);
}

void diferenta(Multime X,Multime Y)
{
	M=(X^Y)&X;
	af(M);
}

void complementara(Multime X)
{
	af(~X);
}
     
int main()
{
	int nr,n;

	printf("Introduceti numarul de elemente ale multimii X: ");
	scanf("%d", n);

    printf("Introduceti elementele multimii X:");	
	do
	{
		scanf("%d",&nr);
		X=X|(1<<nr);
		n--;
	}while(nr>=0&&nr<=31&&n>0);
	


	printf("Introduceti numarul de elemente ale multimii Y: ");
	scanf("%d", n);
	printf("\n\nIntroduceti elementele multimii Y:");
	
	do
	{
		scanf("%d",&nr);
		Y=Y|(1<<nr);
		n--;
	}while(nr>=0&&nr<=31&&n>0);
     
	printf("\n\n\nReuniunea multimilor este: ");
	reuniune(X,Y);
	printf("\n\n");

	printf("Intersectia multimilor este: ");
	intersectie(X,Y);
	printf("\n\n");

	printf("Diferenta dintre multimea X si multimea Y este: ");
	diferenta(X,Y);
	printf("\n\n");

	printf("Diferenta dintre multimea Y si multimea X este: ");
	diferenta(Y,X);
	printf("\n\n");

	printf("Complementara multimii X este: ");
	complementara(X);
	printf("\n\n");

	printf("Complementara multimii Y este: ");
	complementara(Y);
	printf("\n\n");

	system("pause");
	return 0;
}


