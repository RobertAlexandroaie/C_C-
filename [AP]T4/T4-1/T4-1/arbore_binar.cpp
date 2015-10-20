#include"arbore_binar.h"
#include<iostream>


stiva s;
coada c;
NodArboreBinar *rad;
int v[100];
int ord;


stiva stivaVida()
{
	stiva S;
	S.top=NULL;
	return S;
}

void push(stiva *s, NodArboreBinar *x)
{
	nodst *p=(nodst*)malloc(sizeof(nodst));
	p->element=x;
	p->pred=s->top;
	s->top=p;
}

NodArboreBinar *top(stiva s)
{
	return s.top->element;
}

void pop(stiva *s)
{
	nodst *p=s->top;
	s->top=s->top->pred;
	p->pred=NULL;
}




coada coadaVida()
{
	coada C;
	C.pr=NULL;
	C.ul=NULL;
	return C;
}

void insereaza(coada *C, NodArboreBinar *x)
{
	nodq *p=(nodq*)malloc(sizeof(nodq));

	p->element=x;
	p->suc=NULL;
	
	if(C->pr==NULL)
		C->pr=p;
	if(C->ul==NULL)
		C->ul=p;
	else
	{
		C->ul->suc=p;
		C->ul=p;
	}
}

void citeste(coada C, NodArboreBinar *x)
{
	x=C.pr->element;
}


NodArboreBinar* construiesteArb(char a[], int n)
{
	s=stivaVida();
	rad=(NodArboreBinar *)malloc(sizeof(NodArboreBinar));
	
	
	rad->info=a[0];
	rad->st=NULL;
	rad->dr=NULL;

	push(&s,rad);

	int i;
	i=1;
	while(i<n)
	{
		if((a[i]=='(')||(a[i]==','))
		{
			NodArboreBinar *p=(NodArboreBinar *)malloc(sizeof(NodArboreBinar));
			if(a[i+1]!='$')
				p->info=a[i+1];
			else
				p->info=NULL;
			p->st=NULL;
			p->dr=NULL;
			push(&s,p);
		}
		if(a[i]==')')
		{
			NodArboreBinar *v1=(NodArboreBinar *)malloc(sizeof(NodArboreBinar));
			v1=top(s);
			pop(&s);
			
			NodArboreBinar *v2=(NodArboreBinar *)malloc(sizeof(NodArboreBinar));
			v2=top(s);
			pop(&s);

			NodArboreBinar *v3=(NodArboreBinar *)malloc(sizeof(NodArboreBinar));
			v3=top(s);
			v3->st=v2;
			v3->dr=v1;
			//rad=v3;
		}
		i++;
	}
	return rad;
}

void RSD(NodArboreBinar *radacina)
{
	NodArboreBinar *rad=radacina;
	if (rad == NULL)
		return;
	else
	{
		if(rad->info!=NULL)
			printf("%c ",rad->info);
		RSD(rad->st);
		RSD(rad->dr);
	} 
}

void SRD(NodArboreBinar *radacina)
{
	NodArboreBinar *rad=radacina;
	if (rad == NULL)
		return;
	else
	{
		SRD(rad->st);
		if(rad->info!=NULL)
			printf("%c ",rad->info);
		SRD(rad->dr);
	} 
}

void SDR(NodArboreBinar *radacina)
{
	NodArboreBinar *rad=radacina;
	if (rad == NULL)
		return;
	else
	{
		SDR(rad->st);
		SDR(rad->dr);
		if(rad->info!=NULL)
			printf("%c ",rad->info);
	} 
}

void BFS(NodArboreBinar *radacina)
{
	NodArboreBinar *rad=radacina;
	nodq *v;
	if (rad == NULL)
		return;
	else
	{
		coada C=coadaVida();
		insereaza(&C, rad);
		v=C.pr;
		
		while (v!=NULL)
		{
			if(v->element->info!=NULL)
				printf("%c ",v->element->info);
			if (v->element->st != NULL) insereaza(&C, v->element->st);
			if (v->element->dr != NULL) insereaza(&C, v->element->dr);
			v=v->suc;
		}		  
	} 
}



void oglindireArb(NodArboreBinar *radacina)
{
	nodq *v;
	NodArboreBinar *aux;
	if (radacina == NULL)
		return;
	else
	{
		coada C=coadaVida();
		insereaza(&C, radacina);
		v=C.pr;
		
		while (v!=NULL)
		{
			if(v->element->info!=NULL)
				printf("%c ",v->element->info);

			aux=v->element->st;
			v->element->st=v->element->dr;
			v->element->dr=aux;

			if (v->element->st != NULL) insereaza(&C, v->element->st);
			if (v->element->dr != NULL) insereaza(&C, v->element->dr);
			v=v->suc;
		} 		  
	} 
}

int numarNoduriArb(char a[], int n)
{
	int numar=0,i;
	for(i=0;i<n;i++)
		if(a[i]>='A'&&a[i]<='Z')
			numar++;
	return numar;
}

void afisareNiv(char a[],int n,int nivel)
{
	int paranteze=0,i;
	printf("\nNodurile de pe nivelul %d sunt: ",nivel);
	for(i=0;i<n;i++)
	{
		if(a[i]=='(')
			paranteze++;
		if(a[i]==')')
			paranteze--;
		if(nivel==paranteze)
			if(a[i]>='A'&&a[i]<='Z')
				printf("%c ",a[i]);
	}
	printf("\n");
}

int nrNoduri_cu_un_singur_fiu(char a[],int n)
{
	int nr_noduri=0;
	for(int i=0;i<n;i++)
		if(a[i]=='$')
			nr_noduri++;
	return nr_noduri;
}

void afisareKSRD(NodArboreBinar *radacina, int k)
{
	NodArboreBinar *rad=radacina;
	
	if (rad == NULL)
		return;
	else
	{
		afisareKSRD(rad->st,k);
		if(rad->info!=NULL)
			ord++;
		if(ord==k)
		{
			if(rad->info!=NULL)
				printf("%c ",rad->info);
			system("pause");
			exit(1);
		}
		afisareKSRD(rad->dr,k);
	}
}
