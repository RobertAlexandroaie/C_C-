#include<iostream>
#include<stdio.h>
#include<string.h>


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

void svnViewStatus()
{
	if(svnCheckDB())
	{
		FILE *fisier;
		fisier=fopen("db.txt", "r");

		if(!fisier)
		{
			printf("eroare la alocarea memoriei.\n");
			exit(1);
		}

		char *v;
		if(!(v=(char*)malloc(501*sizeof(char))))
		{
			printf("eroare la alocarea memoriei.\n");
			exit(1);
		}

		char *u;
		if(!(u=(char*)malloc(sizeof(char)*3)))
		{
			printf("eroare la alocarea memoriei.\n");
			exit(1);
		}

		int i, j;
		fgets(v, 500, fisier);

		while(!feof(fisier))
		{
			fgets(v, 500, fisier);
			i=0;
			while(v[i]!=';')
				i++;
			v[i]='\0';
			strcpy(u, v);
		}
		printf("numar ordine: %s\n", u);
		free(u);

		fseek(fisier, 0, SEEK_SET);
		fgets(v, 500, fisier);
		fgets(v, 500, fisier);
		i=0;
		j=0;

		while(j<2)
		{
			if(v[i]==';')
				j++;
			i++;
		}

		printf("prima operatiune: ");
		while(v[i]!=';')
		{
			printf("%c", v[i]);
			i++;
		}

		printf("\n");
		FILE *fisier2;
		fisier2=fopen("users.txt", "r");
		if(!fisier2)
		{
			printf("eroare la deschiderea fisierului.\n");
			exit(1);
		}

		if(!(u=(char*)malloc(sizeof(char)*101)))
		{
			printf("eroare la alocarea memoriei.\n");
			exit(1);
		}

		int k, nr_apr;
		while(!feof(fisier2))
		{
			fgets(u, 100, fisier2);
			i=0;
			//j=0;
			while(u[i]!=';')
			{
				i++;
			}
			j=i+1;
			i++;
			while(u[i]!=';')
				i++;
			u[i]='\0';
			fseek(fisier, 0, SEEK_SET);
			nr_apr=0;
			while(!feof(fisier))
			{
				fgets(v, 500, fisier);
				k=0;
				while(v[k]!=';')
					k++;
				k++;
				i=k;
				while(v[k]!=';')
					k++;
				v[k]='\0';
				if(!strcmp(u+j, v+i))
					nr_apr++;
			}
			if(nr_apr)
				printf("Utilizator %s: %d\n", u+j, nr_apr);
		}
	free(u);
	free(v);
	fclose(fisier2);
	fclose(fisier);
	}
	else
		printf("formatul fisierului este incorect\n");
}

int main()
{
	svnViewStatus();

	system("pause");
	return 0;
}