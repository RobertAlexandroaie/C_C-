#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void viewHistory(char *nume)
{
     FILE *fisier;
     char *sir;
     fisier=fopen("db.txt","r");
     if(!fisier)
     {   
         printf("eroare la deschiderea fisierului.\n");
         exit(1);
     }

     if(!(sir=(char*)malloc(301*sizeof(char))))
     {   
         printf("eroare la alocarea memoriei\n");
	     exit(1);
     }

      fgets(sir,300,fisier);
      while(!feof(fisier) )
      {
         int i=0,ok=1,j=0,k;
         fgets(sir,300,fisier);
         while(sir[i]!=';')
             i++;
            i++;
          k=i;   
         while(sir[i]!=';' && ok==1)
         {
             if(sir[i]==nume[j])
             {
                i++;
                j++;
             }
             else 
             {
                ok=0;
             }
         }
         if((ok==1) && (strlen(nume)==(i-k)))
         {
             i++;
             printf("%s \n",sir+i);
         }
      }
      free(sir);
      fclose(fisier);
}

int main()
{ 
    char *nume;
    if(!(nume=(char*)malloc(31*sizeof(char))))
	{   
        printf("eroare la alocarea memoriei\n");
		exit(1);
	}
    printf("Dati numele :");
    gets(nume);
    printf("\n\n");
    viewHistory(nume);
    system("pause");
    return 0;
}                         	
