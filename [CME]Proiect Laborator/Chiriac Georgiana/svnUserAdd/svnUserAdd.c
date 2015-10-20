#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void svnUserAdd(char* utilizator,char* nume,char* prenume)
{
     FILE *fisier;
     char p;
     int contor=0;
	 fisier=fopen("users.txt", "a+");
	 rewind(fisier);
	 if(!fisier)
	 {
		 printf("eroare la deschiderea fisierului\n");
		 exit(1);
	 }
     while(!feof(fisier))
         {p=fgetc(fisier);
         if(p=='\n')
              contor++;
         }
     fprintf(fisier,"\n%d;%s;%s;%s",contor+2,utilizator,nume,prenume);
     fclose(fisier);      
}
         



int main ()
{
	char *utilizator,*nume,*prenume;
	if(!(nume=(char*)malloc(30*sizeof(char))))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}
	if(!(prenume=(char*)malloc(30*sizeof(char))))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}
	if(!(utilizator=(char*)malloc(30*sizeof(char))))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}
	printf("Introduceti numele: ");
	gets(nume);
	printf("Introduceti prenumele: ");
	gets(prenume);
	printf("Introduceti utilizator: ");
	gets(utilizator);
	svnUserAdd(utilizator,nume,prenume);

	free(nume);
	free(prenume);
	free(utilizator);
	system("pause");
	return 0;
}
