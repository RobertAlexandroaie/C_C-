#include"graf.h"
#include<iostream>
#include<stdio.h>

nod *pr[50],*ul[50];

void creeaza(Graf *gr, char *nume_fisier)
{
	FILE *fin;
	fin=fopen(nume_fisier,"r");

	if(!fin)
	{
		printf("Eroare la deschiderea fisierului %s.\n",nume_fisier);
		system("pause");
		exit(1);
	}

	fscanf(fin,"%d ",&gr->numar_noduri);

	int vf1,vf2;
	
	for(int i=0;i<gr->numar_noduri;i++)
		pr[i]=ul[i]=gr->lista[i]=NULL;

	while(!feof(fin))
	{
		fscanf(fin,"%d %d",&vf1,&vf2);

		nod *p=(nod*)malloc(sizeof(nod));
		p->info=vf2;
		p->leg=NULL;
		if(pr[vf1]==NULL)
			pr[vf1]=ul[vf1]=p;
		else
		{
			ul[vf1]->leg=p;
			ul[vf1]=p;
		}
		gr->lista[vf1]=pr[vf1];

		p=(nod*)malloc(sizeof(nod));
		p->info=vf1;
		p->leg=NULL;
		if(pr[vf2]==NULL)
			pr[vf2]=ul[vf2]=p;
		else
		{
			ul[vf2]->leg=p;
			ul[vf2]=p;
		}
		gr->lista[vf2]=pr[vf2];
	}
}

void afisare(Graf gr)
{
	int i=0;
	nod *p;
	while(i<gr.numar_noduri)
	{
		printf("%d: ",i);
		p=gr.lista[i];
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->leg;
		}
		printf("\n");
		i++;
	}
}

int viz[50];
int gasit=0;

void test_arbore(Graf gr,int varf)
{
	viz[varf]=1;
	nod *p=pr[varf];
	
	if(p==NULL)
		return;

	while(p!=NULL)
	{
		pr[p->info]=pr[p->info]->leg;

		if(viz[p->info]==0)
			test_arbore(gr,p->info);
		else gasit=1;

		p=p->leg;
	}
}

void este_arbore(Graf gr)
{
	test_arbore(gr,0);
	int suma=0;
	for(int i=0;i<gr.numar_noduri;i++)
		suma+=viz[i];

	if(suma!=gr.numar_noduri)
		printf("Graful introdus NU este arbore pentru ca nu este conex!\n");
	else
		if(gasit)
			printf("Graful introdus NU este arbore deoarece contine ciclu!\n");
		else
			printf("Graful introdus este arbore.\n");
}