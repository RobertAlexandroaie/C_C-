#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void svnViewRevision(int nr)
{FILE *fisier;
fisier=fopen("db.txt","r");
if(!fisier)
	{   printf("eroare la deschiderea fisierului.\n");
		exit(1);
	}
int i=0,k,j;
char *sir;
if(!(sir=(char*)malloc(301*sizeof(char))))
	{   printf("eroare la alocarea memoriei\n");
		exit(1);
	}
fgets(sir,300,fisier);
while(!feof(fisier)  &&i<nr)
   { fgets(sir,300,fisier); i++;
     j=0;k=0;
      while(j<4)
        {k++;
         if(sir[k]==';') j++;
           }
      printf("%s",sir+k+1);          
      printf("\n");}
if(i<nr) printf("Numarul de citate a fost prea mare.Aceastea sunt toate.\n ");       
free(sir);       
fclose(fisier);       
}  


int main()
{int revizie;

printf("Dati numarul ce repezinta numarul de citate :");
scanf("%d",&revizie);

printf("\n\n");
svnViewRevision(revizie);
system("pause");
return 0;}
