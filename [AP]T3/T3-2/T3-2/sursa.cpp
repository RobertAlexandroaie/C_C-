/*
2.  Se dau L1 şi L2, două liste liniare simplu înlănţuite de numere întregi, ordonate crescător. Să se  
        scrie o funcţie care returnează lista formată din elementele lui L1 şi ale lui L2 ordonate crescător. 
        Exemple:  
        Pentru listele L1 = 2 → 2 → 7 → Φ şi L2 = 1 → 2 → 8 → Φ, se va returna lista cu elementele în  
        ordine crescătoare 1 → 2 → 2 → 2 → 7 → 8 → Φ. 
        Pentru listele L1 = 3 → Φ şi L2 = Φ, lista returnată va fi 3 → Φ. 
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

Llin L1,L2,*pL1,*pL2;

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

void adauga(Llin *pL, int el)
{
	nod *p=(nod *)malloc(sizeof(nod));
	p->val=el;
	pL->ult->suc=p;
	p->suc=NULL;
	pL->ult=p;
}



Llin interclasare(Llin L1,Llin L2)
{
	Llin L3;
	L3=listaVida();

	nod *p,*q,*r;

	p=L1.prim;
	q=L2.prim;

	if(q==NULL&&p==NULL)
	{
		return L3;
	}
	
	while(p!=NULL&&q!=NULL)
	{
		if(p->val<q->val)
		{
			if(L3.prim==NULL)
			{
				r=(nod *)malloc(sizeof(nod));
				L3.prim=r;
				L3.ult=r;
				r->val=p->val;
				r->suc=NULL;
			}
			else
			{
				adauga(&L3,p->val);
			}
			p=p->suc;
		}
		else
		{				
			if(L3.prim==NULL)
			{
				r=(nod *)malloc(sizeof(nod));
				L3.prim=r;
				L3.ult=r;
				r->val=q->val;
				r->suc=NULL;
			}
			else
			{
				adauga(&L3,q->val);
			}
			q=q->suc;
		}
	}

	while(p==NULL&&q!=NULL)
	{
		adauga(&L3,q->val);
		q=q->suc;
	}

	while(q==NULL&&p!=NULL)
	{	
		adauga(&L3,p->val);
		p=p->suc;
	}

	return L3;
}

int main()
{
	Llin L;
	L=listaVida();
	
	L1=listaVida();
	printf("Citeste prima lista:\n");
	citire(&L1);

	
	L2=listaVida();
	printf("\nCiteste a doua lista\n");
	citire(&L2);
		
	
	L=interclasare(L1,L2);

	printf("Lista formata din cele doua liste este:\n");
	afisare(L);

	system("pause");
	return 0;
}