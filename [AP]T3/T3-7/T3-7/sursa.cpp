/*

7.  Fie două stive S1 şi S2. Implementaţi un algoritm care foloseşte doar aceste două stive pentru a  
    simula o coadă. 

*/

#include<iostream>
#include<stdio.h>

typedef struct st
{
	int val;
	st *prec;
}st;

typedef struct stiva
{
	st *top;
}stiva;

stiva S1,S2,*pS1,*pS2;

void coadaVida(stiva *a, stiva *b)
{
	a->top=NULL;
	b->top=NULL;
}	

int lungq(stiva a)
{
	st *p;
	int l=0;
	for(p=a.top;p!=NULL;p=p->prec)
		l++;
	return l;
}

void initS2()
{
	st *p,*q,*t=S1.top;
	p=t;
	q=(st *)malloc(sizeof(st));
	q->val=p->val;
	q->prec=NULL;
	S2.top=q;
	t=t->prec;
	for(p=t;p!=NULL;p=p->prec)
	{
		q=(st*)malloc(sizeof(st));
		q->val=p->val;
		q->prec=S2.top;
		S2.top=q;
	}
}

void insereaza(int v)
{
	st *p;
	p=(st *)malloc(sizeof(st));
	p->val=v;
	p->prec=S1.top;
	S1.top=p;
}

int citeste()
{
	return S2.top->val;
}

void elimina()
{
	initS2();

	st *p,*q;
	p=S2.top;
	S2.top=S2.top->prec;
	free(p);

	S1.top=NULL;

	p=S2.top;
	q=(st *)malloc(sizeof(st));
	q->val=p->val;
	q->prec=NULL;
	S1.top=q;

	for(p=p->prec;p!=NULL;p=p->prec)
	{
		q=(st *)malloc(sizeof(st));
		q->val=p->val;
		q->prec=S1.top;
		S1.top=q;
	}

}

void citire()
{
	int n,e,i;
	printf("Introduceti numarul de valori: ");
	scanf("%d",&n);

	coadaVida(&S1,&S2);
	for(i=1;i<=n;i++)
	{
		printf("e%d=",i);
		scanf("%d",&e);
		insereaza(e);
	}
	initS2();
}

void afisare()
{
	st *p;
	printf("\n");
	for(p=S1.top;p!=NULL;p=p->prec)
		printf("%d ",p->val);
	printf("\n");
}

int main()
{
	citire();
	afisare();

	insereaza(9);
	afisare();

	elimina();
	afisare();

	system("pause");
	return 0;
}