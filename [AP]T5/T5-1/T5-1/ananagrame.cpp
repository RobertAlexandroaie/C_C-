#include"ananagrame.h"
#include<string>

nodcuv *cuvinte[20];
nodcuv *scrable;
int litere[26];

void init(int *a)
{
	for(int i=0;i<26;i++)
		a[i]=0;
}

void caps(char *cuvant)
{
	for(int i=0;i<strlen(cuvant);i++)
		cuvant[i]=toupper(cuvant[i]);
}

void adauga_cuv(nodcuv **a, char *c)
{
	int l=strlen(c);
	l--;

	nodcuv *p=(nodcuv *)malloc(sizeof(nodcuv));
	char aux[20];
	strcpy(aux,c);
	
	strcpy(p->info,aux);
	p->leg=a[l];
	a[l]=p;
}

void creare_cuvinte(nodcuv **a,char *fisier_in)
{
	int i=0,j=0;
	FILE *fin;
	fin=fopen(fisier_in,"r");
	
	for(i=0;i<20;i++)
		cuvinte[i]=NULL;
	
	char *linie=(char *)malloc(80*sizeof(char));
	char *cuvant=(char *)malloc(sizeof(char)*20);

	while(!feof(fin))
	{
		fscanf(fin,"%s",linie);
		cuvant=strtok(linie," \n");
		
		while(cuvant!=NULL)
		{
			adauga_cuv(cuvinte,cuvant);
			cuvant=strtok(NULL," \n");
		}
	}
	fclose(fin);

}

void afisare_cuv(nodcuv **a)
{
	int i;
	nodcuv *p;
	for(i=0;i<20;i++)
	{
		printf("Cuvinte cu %d litere:  ",i+1);
		if(a[i]!=NULL)
		{
			p=a[i];
			do
			{
				printf("%s ",p->info);
				p=p->leg;			
			}while(p!=NULL);
		}
		else
		{
			printf("0 cuvinte.");
		}
		printf("\n");
	}

}

void set_litere(int *a,char *cuvant)
{
	int i;
	int l=strlen(cuvant);

	char aux[20];
	strcpy(aux,cuvant);

	caps(aux);

	for(i=0;i<l;i++)
		a[(int)(aux[i]-65)]++;
}

void reset_litere(int *a,char *cuvant)
{
	int i;
	int l=strlen(cuvant);
	char aux[20];
	strcpy(aux,cuvant);
	caps(aux);
	
	for(i=0;i<l;i++)
		a[(int)(aux[i])-65]--;
}

int e_ananagrama(int *a)
{
	int i;
	for(i=0;i<26;i++)
		if(a[i]!=0)
			return 1;
	return 0;
}

void ad_ananagrama(char *cuvant)
{
	if(cuvant!="xxxxxxxxxx")
	{
		nodcuv *p=(nodcuv *)malloc(sizeof(nodcuv));
		strcpy(p->info,cuvant);
		p->leg=scrable;
		scrable=p;
	}
}

void ananagrame(nodcuv **a)
{
	int i;
	int ok;

	nodcuv *q,*r;

	for(i=0;i<20;i++)
	{
		q=a[i];
		if(q!=NULL)
		{
			for(;q->leg!=NULL;q=q->leg)
			{
				ok=1;
				if(strcmp(q->info,"xxxxxxxxxx")!=0)
				{
					for(r=q->leg;r!=NULL;r=r->leg)
					{
						if(strcmp(r->info,"xxxxxxxxxx"))
						{
							init(litere);
							set_litere(litere,q->info);
							reset_litere(litere,r->info);

							if(!e_ananagrama(litere))
							{
								ok=0;
								//printf("%s %s\n",q->info,r->info);
								strcpy(r->info,"xxxxxxxxxx");
							}
						}
					}
					if(ok==1)
						if(strcmp(q->info,"xxxxxxxxxx")!=0)
							ad_ananagrama(q->info);
				}
			}
			if(strcmp(q->info,"xxxxxxxxxx")!=0)
				ad_ananagrama(q->info);
		}
	}	
}

void sort_ananagrame(nodcuv *x)
{
	int ok;
	int i;
	nodcuv *p;
	char aux[20];

	do
	{
		ok=1;
		for(p=x;p->leg!=NULL;p=p->leg)
		if(strcmp(p->info,p->leg->info)>0)
		{
			strcpy(aux,p->info);
			strcpy(p->info,p->leg->info);
			strcpy(p->leg->info,aux);
			ok=0;
		}
	}while(ok!=1);
}

void scrie_ananagrame(char *fisier_out)
{
	ananagrame(cuvinte);
	sort_ananagrame(scrable);

	FILE *fout;
	fout=fopen(fisier_out,"a");

	for(nodcuv *p=scrable;p!=NULL;p=p->leg)
	{
		if(p->info!="xxxxxxxxxx")
			fprintf(fout,"%s\n",p->info);
	}
}
