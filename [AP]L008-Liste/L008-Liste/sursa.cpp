/*
sa se implementeze operatii cu liste
*/


#include<iostream>
#include<stdio.h>


typedef struct nod
{
	int val;
	nod *suc;
};

typedef struct Llin
{
	nod *prim,*ultim;
};

Llin listaVida()
{
	Llin L;
	L.prim=L.ultim=NULL;
	return L;
}

void citire(Llin &L)
{
	L=listaVida();

	int i=1,n,x;
	printf("Introdu numarul de elemente: ");
	scanf("%d",&n);

	
	printf("E%d=", i);
	scanf("%d",&x);
	
	nod *p=new nod;
	p->val=x;
	p->suc=NULL;

	L.prim=p;
	L.ultim=p;

	for(i=2;i<=n;i++)
	{
		printf("E%d=", i);
		scanf("%d",&x);
		
		
		nod *q=new nod;
		p->suc=q;
		q->val=x;
		q->suc=NULL;
		L.ultim=q;
		p=q;
	}
	
}

void inserare(Llin &L, int k, int el)
{
	while(k<0)
	{
		printf("Pozitia introdusa este negativa! Introduceti o valoare pozitiva: ");
		scanf("%d",&k);
	}
	
	nod *p=new nod;
	p->val=el;

	if(k==0||L.prim==NULL)
	{
		p->suc=NULL;
		L.prim=p;
		L.ultim=p;
		return;
	}

	if(k>0)
	{
		int i;
		for(p=L.prim, i=1;i<k&&p->suc!=NULL;i++, p=p->suc);
		if(p->suc==NULL) printf("\nPozitia depaseste numarul de elemente ale listei.\nValoarea se va introduce la sfarsit!!\n");
		nod *q=new nod;
		q->val=el;
		q->suc=p->suc;
		p->suc=q;
		if(q->suc==NULL)
			L.ultim=q;
		return;
	}
}

void afisare(Llin L)
{
	nod *p=new nod;
	for(p=L.prim;p!=NULL;p=p->suc)
		printf("%d ",p->val);
	printf("\n\n");
}

int main()
{
	Llin L;
	
	citire(L);
	afisare(L);

	inserare(L,-2,8);
	afisare(L);

	system("pause");
	return 0;
}
