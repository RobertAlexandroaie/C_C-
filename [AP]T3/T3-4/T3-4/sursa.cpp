/*

4.  Fie A un alfabet. Presupunem că şirurile peste A sunt reprezentate prin liste liniare simplu  
   înlănţuite. Să se scrie funcţii pentru operaţiile de mai jos: 

    - Fiind dat un şir w = a1 ... an, determină oglinditul său w’ = an ... a1, fără a utiliza spaţiu  
    suplimentar de memorie (de dimensiunea listei). 
    Exemple: 
    Pentru şirul cazac, se va determina acelaşi şir cazac. 
    Pentru şirul mississippi, se va determina ippississim. 

    - Fiind dat un şir u, decide dacă există un şir w astfel încât u = ww . 
    Exemple: 
    Pentru şirul mississippiippississim, se va decide că da. 
    Pentru şirul mississippippississim, se va decide că nu. 

    - Fiind date 2 şiruri u1 şi u2, decide dacă u1 <= u2 (în ordinea lexicografică). 
    Exemple: 
    Pentru şirurile u1 = abcd şi u2 = abc, se decide că nu. 
    Pentru şirurile u1 = abcd şi u2 = abce, se decide că da. 
    Pentru şirurile u1 = aedfi şi u2 = z, se decide că da. 


*/


#include<iostream>
#include<stdio.h>

typedef struct nod
{
	char val;
	nod *suc;
}nod;

typedef struct Llin
{
	nod *prim, *ultim;
}Llin;

int n;
Llin L,*pL;

Llin listaVida()
{
	Llin l;
	l.prim=NULL;
	l.ultim=NULL;
	return l;
}

int lung(Llin L)
{
	nod *p;
	int l=0;
	for(p=L.prim;p!=NULL;p=p->suc)
		l++;
	return l;
}

void citire(Llin *pL)
{	
	char e;
	int i=1;
	nod *p;
	printf("Introduceti numarul de valori:");
	scanf("%d",&n);
		
	p=(nod*)malloc(sizeof(nod));

	fflush(stdin);
	printf("e[%d]=",i++);
	scanf("%c",&e);

	p->val=e;
	p->suc=NULL;
	pL->prim=p;
	pL->ultim=p;
	

	for(;i<=n;)
	{
		fflush(stdin);
		printf("e[%d]=",i++);
		scanf("%c",&e);
		
		nod *q=(nod *)malloc(sizeof(nod));
		q->val=e;
		q->suc=NULL;
		p->suc=q;
		pL->ultim=q;
		p=q;
	}
}

void afisare(Llin L)
{
	nod *p;
	if(lung(L)==0) printf("\nLista este vida!!\n\n");
	else
		for(p=L.prim;p!=NULL;p=p->suc)
			printf("%c ",p->val);
}

void oglindeste(Llin *pL)
{
	nod *p,*u,*q;
	char aux;
	int i,l=lung(*pL);

	u=pL->ultim;
	for(i=1,p=pL->prim;i<=n/2;i++,p=p->suc)
	{
		for(q=pL->prim;q->suc!=u;q=q->suc);
		aux=u->val;
		u->val=p->val;
		p->val=aux;
		u=q;
	}
}

void npo(Llin L)
{
	nod *p,*q,*r;
	int i, l=lung(L);
	Llin aux=L;

	if(lung(L)%2!=0)
	{
		printf("\nNU, lista NU reprezinta un sir de forma dorita!\n");
		return;
	}
	
	oglindeste(&aux);
	
	for(p=L.prim,q=aux.prim;q!=NULL;p=p->suc,q=q->suc)
		if(p->val!=q->val)
		{
			printf("\nNU, lista NU reprezinta un sir de forma dorita!\n");
			return;	
		}

	printf("\nDA, lista reprezinta un sir de forma dorita!\n"); 	
}

void compara(Llin L1, Llin L2)
{
	nod *p1,*p2;
	for(p1=L1.prim,p2=L2.prim;p1!=NULL&&p2!=NULL;p1=p1->suc,p2=p2->suc)
		if(p1->val>p2->val)
		{
			printf("NU!");
			return;
		}
	
	if(p1==NULL&&p2!=NULL)
	{
		printf("DA!");
		return;
	}
	
	if(p1!=NULL&&p2==NULL)
	{
		printf("NU!");
		return;
	}

	printf("DA!");
}

int main()
{
	/*
	L=listaVida();
	citire(&L);
	npo(L);
	*/

	Llin L1,L2;
	L1=listaVida();
	L2=listaVida();

	citire(&L1);
	citire(&L2);

	compara(L1,L2);
	
	system("pause");
	return 0;
}
