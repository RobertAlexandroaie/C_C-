/*


     1. Să se scrie o funcţie care testează dacă două liste liniare simplu înlănţuite sunt egale. 
        Exemple:  
        Listele 2 → 3 → 7 → Φ şi 2 → 3  → Φ sunt diferite. 
        Listele 1 → Φ şi 1 → Φ sunt egale.  


*/

#include<iostream>
#include<stdio.h>


typedef struct nod
{
	int val;
	nod *suc;
}nod;

typedef struct Llin
{
	nod *prim,*ult;
}Llin;

Llin L1,L2;

Llin listaVida()
{
	Llin L;
	L.prim=NULL;
	L.ult=NULL;
	return L;
}

void citire(Llin *pL)
{
	nod *p=(nod *)malloc(sizeof(nod));
	int n,i=1,x;
	
	printf("Introduceti numarul de elemente: ");
	scanf("%d",&n);

	printf("E%d=",i++);
	scanf("%d",&x);
	p->val=x;
	p->suc=NULL;
	pL->prim=p;
	pL->ult=p;


	for(;i<=n;i++)
	{
		nod *q=(nod *)malloc(sizeof(nod));
		printf("E%d=",i);
		scanf("%d",&x);

		q->val=x;
		p->suc=q;
		q->suc=NULL;
		pL->ult=q;
		p=q;
	}
}

int lung(Llin L)
{
	int l=0;
	nod *p;
	for(p=L.prim;p!=NULL;p=p->suc)
		l++;
	return l;
}

void afisare(Llin L)
{
	nod *p;

	for(p=L.prim;p!=NULL;p=p->suc)
		printf("%d ",p->val);
	printf("\n");
}



void compara(Llin L1, Llin L2)
{
	if(lung(L1)!=lung(L2))
	{
		printf("\nListele sunt diferite!\n");
		return ;
	}

	nod *p;
	nod *q;
	

	for(p=L1.prim,q=L2.prim;p!=NULL;p=p->suc,q=q->suc)
		if(p->val!=q->val)
		{
			printf("\nListele sunt diferite!\n");
			return;
		}
	printf("\nListele sunt identice!\n");
}

int main()
{

	printf("\nCitire prima lista:\n");
	L1=listaVida();
	citire(&L1);
	afisare(L1);

	printf("\nCitire a doua lista:\n");
	L2=listaVida();
	citire(&L2);

	compara(L1,L2);

	system("pause");
	return 0;
}