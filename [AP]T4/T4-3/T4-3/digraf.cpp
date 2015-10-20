#include"digraf.h"
#include<stdio.h>
#include<iostream>
#include<limits.h>

int suc[50];
int pred[50];

coada *Q;
int lungime_drum,viz[50];

int comp_conexa=1;

void creeaza(Digraf *dig, char *nume_fisier)
{
	FILE *fin;
	fin=fopen(nume_fisier,"r");

	if(!fin)
	{
		printf("Eroare la deschiderea fisierului %s.\n",nume_fisier);
		system("pause");
		exit(1);
	}

	fscanf(fin,"%d ",&dig->numar_noduri);

	int sursa,destinatie;
	
	for(int i=0;i<dig->numar_noduri;i++)
		dig->lista[i]=NULL;

	while(!feof(fin))
	{
		fscanf(fin,"%d %d",&sursa,&destinatie);
		nod *p=(nod*)malloc(sizeof(nod));
		p->info=destinatie;
		p->leg=dig->lista[sursa];
		dig->lista[sursa]=p;
	}
}

void afisare(Digraf dig)
{
	int i=0;
	nod *p;
	while(i<dig.numar_noduri)
	{
		printf("%d: ",i);
		p=dig.lista[i];
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->leg;
		}
		printf("\n");
		i++;
	}
}

int grad_int (Digraf dig, int varf)
{
	int i=0,grad=0;
	nod *p;
	for(i=0;i<dig.numar_noduri;i++)
	{
		p=dig.lista[i];
		while(p!=NULL)
		{
			if(p->info==varf)
				grad++;
			p=p->leg;
		}
	}
	return grad;
}

int grad_ext (Digraf dig, int varf)
{
	int grad=0;
	nod *p=dig.lista[varf];
	while(p!=NULL)
	{
		grad++;
		p=p->leg;
	}
	return grad;
}

void succesori(Digraf dig,int varf)
{
	suc[varf]=comp_conexa;
	nod *p=dig.lista[varf];
	while(p!=NULL)
	{
		if(suc[p->info]==0)
			succesori(dig,p->info);
		p=p->leg;
	}
}

void predecesori(Digraf dig,int varf)
{
	pred[varf]=comp_conexa;
	for(int i=0;i<dig.numar_noduri;i++)
	{
		nod *p=dig.lista[i];
		while(p)
		{
			if(p->info==varf&&pred[i]==0)
				predecesori(dig,i);
			p=p->leg;
		}
	}
}

int este_tare_conex (Digraf digraf)
{
	succesori(digraf,0);
	predecesori(digraf,0);
	for(int i=0;i<digraf.numar_noduri;i++)
		if(suc[i]==0||pred[i]==0)
			return 0;
	return 1;
}



coada *coadaVida()
{
	coada *C=(coada *)malloc(sizeof(coada));
	C->pr=NULL;
	C->ul=NULL;
	return C;
}

void insereaza(coada *queue, int val)
{
	nodq *p=(nodq*)malloc(sizeof(nodq));

	p->element=val;
	p->suc=NULL;
	
	if(queue->pr==NULL)
		queue->pr=p;
	if(queue->ul==NULL)
		queue->ul=p;
	else
	{
		queue->ul->suc=p;
		queue->ul=p;
	}
}

void elimina(coada *queue)
{
	nodq *p=queue->pr;
	queue->pr=queue->pr->suc;
	p->suc=NULL;
	free(p);
}



int varf_groapa(Digraf dig)
{
	int n=dig.numar_noduri-1;
	for(int i=0;i<=n;i++)
		if(grad_int(dig,i)==n&&grad_ext(dig,i)==0)
			return i;
	return -1;
}

int lung_drum_minim(Digraf dig,int varf1, int varf2)
{
	Q=coadaVida();

	insereaza(Q,varf1);
	nodq *r;
	r=Q->pr;

	viz[varf1]=1;
	while(r!=NULL)
	{
		r=Q->pr;
		nod *p=dig.lista[varf1];
		while(p)
		{
			if(viz[p->info]==0)
			{
				insereaza(Q,p->info);
				viz[p->info]=1;

				lungime_drum++;

				if(p->info==varf2)
					return lungime_drum;
			}
			p=p->leg;
		}
		elimina(Q);
	}
	return LONG_MAX;
}

Digraf transpus(Digraf dig)
{
	int i;
	Digraf transpus;

	for(i=0;i<dig.numar_noduri;i++)
		transpus.lista[i]=NULL;

	transpus.numar_noduri=dig.numar_noduri;

	for(i=0;i<dig.numar_noduri;i++)
	{
		nod *p=dig.lista[i];
		while(p)
		{
			nod *t=(nod *)malloc(sizeof(t));
			t->info=i;
			t->leg=transpus.lista[p->info];
			transpus.lista[p->info]=t;
			p=p->leg;
		}
	}

	return transpus;
}

void componente_tare_conexe(Digraf dig)
{
	for(int i=0;i<50;i++)
		suc[i]=pred[i]=0;
	
	comp_conexa=1;
	
	int i,j;
	for(i=0;i<dig.numar_noduri;i++)
		if(suc[i]==0)
		{
			suc[i]=comp_conexa;
			succesori(dig,i);
			predecesori(dig,i);
			for(j=0;j<dig.numar_noduri;j++)
				if(suc[j]!=pred[j])
					suc[j]=pred[j]=0;
			comp_conexa++;
		}

	for(i=1;i<comp_conexa;i++)
	{
		printf("\nComponenta tare conexa #%d: ",i);
		for(j=0;j<dig.numar_noduri;j++)
			if(suc[j]==i)
				printf("%d ",j);
		printf("\n");
	}
}