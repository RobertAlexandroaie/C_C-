#include<stdio.h>
#include<string.h>
#include<stdlib.h>  

void svnPropList()
{
     FILE *fisier;
     char v;
     fisier=fopen("db.txt","r");
     while((v=fgetc(fisier))!='\n')
           if(v==';')
               printf("\n");
           else
               putchar(v);
     printf("\n");
	 fclose(fisier);
}

int main ()
{
    svnPropList();

    system("pause");
	return 0;
}
