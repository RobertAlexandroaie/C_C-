#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>


int svnCheckDB()
{
    FILE *fisier;
    char *v;
    int flag=0,i,nrord=0,nrordflag=0;
    fisier=fopen("db.txt","r");

    if(!fisier)
	{
		printf("eroare la deschiderea fisierului\n");
		exit(1);
	}

	v=(char*)malloc(500*sizeof(char));
	fgets(v,500,fisier);
	while(!feof(fisier))
	{
        fgets(v, 500, fisier);//preia fiecare rand de text
        if(!isdigit(v[0]))//verifica daca apare numarul de ordine
             {flag=1;
             break;
             }
        for(i=0;v[i]!='\n';i++)//verifica numarul de ;
             if(v[i]==';')
                 flag++;
        if(flag!=4)
             {flag=1;
             break;
             }
        i=0;
        while(isdigit(v[i]))
             i++; 
        nrord++;
        nrordflag=0;
        for(flag=0;flag<i;flag++)//verifica formatul corect al numarului de ordine
             {
             nrordflag*=10;
             nrordflag+=v[flag]-48;
             }
        flag=0;
        if(nrordflag!=nrord)
             {flag=1;
             break;
             }
        if(v[i]!=';')
             {flag=1;
             break;
             }
        i++;
        while(isalpha(v[i]))
             i++;
        if(v[i]!=';')//verifica daca numele utilizatorului contine numai litere
             {flag=1;
             break;
             }
        i++;
        if(!isdigit(v[i]))//verifica formatul datei calendaristice
             {flag=1;
             break;
             }
	    while(isdigit(v[i]))
             i++;
        if(v[i]!=' ')
             {flag=1;
             break;
             }
        i++;
        if(!isalpha(v[i]))
             {flag=1;
             break;
             }
        while(isalpha(v[i]))
             i++;
        if(v[i]!=' ')
             {flag=1;
             break;
             }
        i++;
        if(!isdigit(v[i]))
             {flag=1;
             break;
             }
	    while(isdigit(v[i]))
             i++;
        if(v[i]!=';')
             {flag=1;
             break;
             }
        i++;
        if(!isalpha(v[i]))//verifica daca numele autorului incepe cu o litera
             {flag=1;
             break;
             }
        while(v[i]!=';')
             i++;
        i++;
        if(!isalnum(v[i]))//verifica existenta citatului
             {flag=1;
             break;
             }
        }
	 free(v);
	 fclose(fisier);
     if (flag==1)
          return 0;
     else
          return 1;
}     


int main ()
{
    int i;
    i=svnCheckDB();
    if(i==1) printf("e bine");
    else printf("nu e bine");

    system("pause");
	return 0;
}
