#include "arbore_binar.h"
#include<iostream>
#include<stdio.h>
#include<string>


char a[]="A(B(D,$),C($,F(G,$)))";
int n=strlen(a);
NodArboreBinar *r;


int main()
{
	r=NULL;
	r=construiesteArb(a,n);

	
	
	//RSD(r);
	//printf("\n\n");

	
	SRD(r);
	printf("\n\n");
	/*
	
	SDR(r);
	printf("\n\n");
	

	BFS(r);
	printf("\n\n");
	
	oglindireArb(r);
	printf("\n\n");

	printf("Numarul de noduri este %d.\n\n",numarNoduriArb(a,n));	

	printf("Numarul de noduri cu un singur fiu este %d.\n\n",nrNoduri_cu_un_singur_fiu(a,n));

	afisareNiv(a,n,2);
	
	
	*/
	afisareKSRD(r,4);
	system("pause");
	return 0;
}