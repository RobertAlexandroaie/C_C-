/*

5.  Implementaţi algoritmii pentru operaţiile tipurilor de date Stiva şi Coada. 
    Exemplu: 
    pas              stivă             valoare obţinută 
    iniţial:         [ 
    push(3):         [3 
    push(5):         [3 5 
    push(7)          [3 5 7 
    top()            [3 5 7                     7 
    pop()            [3 5 
    pop()            [3 
    top()            [3                         3 
    push(9)          [3 9 
    pop()            [3  
    pop()            [ 

    Exemplu: 
    pas              coadă             valoare obţinută 
    iniţial:         > > 
    insereaza(3)     > 3 > 
    insereaza(5)     > 5 3 > 
    insereaza(7)     > 7 5 3 > 
    citeste()        > 7 5 3 >                  3 
    elimina()        > 7 5 >  
    citeste()        > 7 5>                     5 
    elimina()        > 7 >  
    insereaza(9)     > 9 7 > 
    elimina()        > 9 > 
    elimina()        > > 

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


typedef struct q
{
	int val;
	q *suc;
}q;

typedef struct coada
{
	q *pr,*ul;
}coada;

stiva S;
coada Q;
int ns,nq;

stiva stivaVida()
{
	stiva S;
	S.top=NULL;
	return S;
}

coada coadaVida()
{
	coada Q;
	Q.pr=NULL;
	Q.ul=NULL;
	return Q;
}	

void push(int v)
{
	st *s;
	s=(st *)malloc(sizeof(st));
	s->val=v;
	s->prec=S.top;
	S.top=s;
}

int top()
{
	return S.top->val; 
}

void pop()
{
	st *p;
	p=(st *)malloc(sizeof(st));
	p=S.top;
	S.top=S.top->prec;
	free(p);
}

int lungq(coada Q)
{
	q *p;
	int l=0;
	for(p=Q.pr;p!=NULL;p=p->suc)
		l++;
	return l;
}

void insereaza(int v)
{
	q *p;
	p=(q *)malloc(sizeof(q));
	p->val=v;
	if(lungq(Q)==0)
	{
		p->suc=NULL;
		Q.ul=p;
	}
	p->suc=Q.pr;
	Q.pr=p;
}

int  citeste()
{
	return Q.ul->val;
}

void elimina()
{
	q *p,*r;
	for(p=Q.pr;p->suc!=Q.ul;p=p->suc);
	r=Q.ul;
	Q.ul=p;
	Q.ul->suc=NULL;
	free(r);
}

void afisares(stiva S)
{
	st *p;
	printf("\n");
	for(p=S.top;p!=NULL;p=p->prec)
		printf("%d\n",p->val);
	printf("\n\n\n");
}

void afisareq(coada Q)
{
	q *p;
	printf("\n");
	for(p=Q.pr;p!=NULL;p=p->suc)
		printf("%d ",p->val);
}

int main()
{
	S=stivaVida();
	Q=coadaVida();
	
	push(3);
	push(5);
	push(7);
	afisares(S);

	printf("\n%d\n",top());
	pop();
	pop();
	afisares(S);

	printf("\n%d\n",top());
	pop();
	afisares(S);
	

	insereaza(3);
	insereaza(5);
	insereaza(7);
	afisareq(Q);

	
	printf("\n%d\n",citeste());
	elimina();
	afisareq(Q);
	
	printf("\n%d\n",citeste());
	elimina();
	afisareq(Q);

	insereaza(9);
	afisareq(Q);

	elimina();
	elimina();
	afisareq(Q);
	

	system("pause");
	return 0;
}