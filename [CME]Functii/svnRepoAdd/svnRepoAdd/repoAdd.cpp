#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

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


void svnRepoAdd(char* name,char* useradmin,char* descriere)
{
     FILE *fisier;
     time_t azi;
     char c[12], *nume, *prenume, *username;
     int i;
	 fisier=fopen("db.txt", "w");
	 if(!fisier)
	 {
		 printf("eroare la deschiderea fisierului\n");
		 exit(1);
	 }
     azi=time(NULL);
     strftime(c,12,"%d %b %Y",localtime(&azi));
     fprintf(fisier,"NumeRepo:%s;DataCreat:%s;Detinator:%s;Descriere:%s",name,c,useradmin,descriere);
     fclose(fisier);
	 fisier=fopen("users.txt", "w");
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
	if(!(username=(char*)malloc(30*sizeof(char))))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}
	 printf("Introduceti numele adminului: ");
	 gets(nume);
	 printf("Introduceti prenumele adminului: ");
	 gets(prenume);
	 printf("Introduceti usernameul: ");
	 gets(username);
	 fprintf(fisier,"1;%s;%s;%s",username,nume,prenume);
	 fclose(fisier);
	 
	 for(i=0;i<2;i++)
	     {printf("Introduceti numele asociatului: ");
	     gets(nume);
	     printf("Introduceti prenumele asociatului: ");
	     gets(prenume);
	     printf("Introduceti usernameul asociatului: ");
	     gets(username);
	     svnUserAdd(username,nume,prenume);
         }
	 
	 
	 
 	 free(nume);
   	 free(prenume);
	 free(username);
	 
}
         



int main ()
{
	char *name,*useradmin,*descriere;
	if(!(name=(char*)malloc(30*sizeof(char))))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}
	if(!(useradmin=(char*)malloc(50*sizeof(char))))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}
	if(!(descriere=(char*)malloc(300*sizeof(char))))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}
	printf("Introduceti numele repositorului: ");
	gets(name);
	printf("Introduceti utilizatorul: ");
	gets(useradmin);
	printf("Introduceti descrierea: ");
	gets(descriere);
	svnRepoAdd(name,useradmin,descriere);

	free(name);
	free(useradmin);
	free(descriere);

	system("pause");
	return 0;
}
