#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>


int doCheckUser(char *utilizator)
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


int main ()
{
	char *utilizator;
	
	if(!(utilizator=(char*)malloc(30*sizeof(char))))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}

	do
		gets(utilizator);
	while(strlen(utilizator)>100);

	if(doCheckUser(utilizator))
		printf("In fisier exista un utilizator cu acest username.\n");
	else
		printf("In fisier NU exista un utilizator cu acest username.\n");

	free(utilizator);

	system("pause");
	return 0;
}