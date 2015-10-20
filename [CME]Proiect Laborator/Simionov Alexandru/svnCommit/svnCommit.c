#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int doCheckUser(char *utilizator)//functie preluata de la Radu Butnariu
{
	FILE *fisier;
	fisier=fopen("users.txt", "r");
	if(!fisier)
	{
		printf("eroare la deschiderea fisierului\n");
		exit(1);
	}
	char *u;
	if(!(u=(char*)malloc(101*sizeof(char))))
	{
		printf("eroare la alocarea memoriei\n");
		exit(1);
	}
	int i, j, ok=0;
	while(!feof(fisier))
	{
		j=0;
		fgets(u, 100, fisier);
		while(u[j]!=';')
			j++;
		i=j+1;
		while(u[i]!=';')
			i++;
		u[i]='\0';
		if(!strcmp(utilizator, u+j+1))
			ok++;
	}
	free(u);
	fclose(fisier);
	if(ok)
		return 1;
	return 0;
}

void svnCommit(char* nume,char* autor,char* citat)
{
     FILE *fisier;
     char p,c[12];
     time_t azi;
     int contor=0;
	 fisier=fopen("db.txt", "a+");
	 rewind(fisier);
	 if(!fisier)
	 {
		 printf("eroare la deschiderea fisierului\n");
		 exit(1);
	 }
     if(!doCheckUser(nume))
         {printf("Nu exista un asemenea utilizator! Politia a fost informata de actiunile tale si vor sosi curand!\n");
         return;
         }
     while(!feof(fisier))
         {p=fgetc(fisier);
         if(p=='\n')
              contor++;
         }
     azi=time(NULL);
     strftime(c,12,"%d %b %Y",localtime(&azi));
     fprintf(fisier,"\n%d;%s;%s;%s;%s",contor+1,nume,c,autor,citat);
     fclose(fisier);      
}
         



int main ()
{
	char *nume,*autor,*citat;
	if(!(nume=(char*)malloc(30*sizeof(char))))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}
	if(!(autor=(char*)malloc(50*sizeof(char))))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}
	if(!(citat=(char*)malloc(300*sizeof(char))))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}
	printf("Introduceti numele: ");
	gets(nume);
	printf("Introduceti autorul: ");
	gets(autor);
	printf("Introduceti citatul: ");
	gets(citat);
	svnCommit(nume,autor,citat);

	free(nume);
	free(autor);
	free(citat);
	system("pause");
	return 0;
}
