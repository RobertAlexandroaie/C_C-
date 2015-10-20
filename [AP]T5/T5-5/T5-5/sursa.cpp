#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<iostream>

typedef struct cuvinte
{
    int n;
    int m;
    int k;
    int lungime;
    char cuvn[30][10];
    char cuvm[30][10];
}cuvinte;

cuvinte C;
char sol[60][10];

void scrie()
{
     FILE *fout;
     int i;
     fout=fopen("iesire.out","ab");
	 
     for(i=0;i<C.k;i++)
	 {
		 //printf("%s\n",sol[i]);
		 fprintf(fout,"%s\n",sol[i]);
	 }

     fprintf(fout,"\n");
     fclose(fout);
}

void citeste()
{
     int i=0,j;
     FILE *fin;

     fin=fopen("intrare.in","r");

     if(!fin)
	 {
		printf("eroare la deschiderea fisierului intrare.txt\n");
		exit(1);
     }

     fscanf(fin,"%d", &C.n);
     fscanf(fin,"%d", &C.m);
     fscanf(fin,"%d",&C.k);
     
     for(i=0;i<C.n;i++)
	 {
		 fscanf(fin,"%s",C.cuvn[i]);
		// printf("%s\n",C.cuvn[i]);
	 }

     C.lungime=strlen(C.cuvn[0])-1;

     for(i=0;i<C.m;i++)
	 {
		 fscanf(fin,"%s",C.cuvm[i]);
		 //printf("%s\n",C.cuvm[i]);
	 }

     C.cuvm[C.m-1][C.k]='\n';
     fclose(fin);
}

void back(int poz, char cm1[], char cm2[])
{
     int k=0;
	 while (k<C.n)
	 {
		 if(poz==C.k)
         {
			 scrie();
             return;
		 }
		 else
			 if ((C.cuvn[k][0]==cm1[poz])&&(C.cuvn[k][C.lungime]==cm2[poz]))
			 {
				 strcpy(sol[poz],C.cuvn[k]);
				 back(poz+1,cm1,cm2);
			 }
			 k++;
	 }
}

void scrie_cuvinte()
{
     int i,j;
     for(i=0;i<C.m;i++)
         for(j=0;j<C.m;j++)
			 back(0,C.cuvm[i],C.cuvm[j]);
}


int main()
{
    citeste();
    scrie_cuvinte();
    
    system("pause");
    return 0;
}
