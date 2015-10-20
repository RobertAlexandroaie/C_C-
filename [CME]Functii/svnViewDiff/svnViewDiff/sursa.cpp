/*

svnViewDiff(fisier) – 10p
fisier – variabila de tip fisier
Functionalitate: cauta in fisierul dat ca argument citatele care nu se regasesc in db.txt si le afiseaza
Exemplu: avand fisierele db.txt si citatedepenet.txt apeland functia svnViewDiff(“citatedepenet.txt”), pe ecran se va afisa mesajul
Fisierul argument contine un singur citat care nu se regaseste in db.txt

*/


#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>


void viewDiff(char *fisier)
{
	FILE *fis,*fis_db,*rez;
	fis=fopen(fisier,"r");
	fis_db=fopen("db.txt","r");

	if(!fis)
	{
		printf("Eroare la deschiderea fisierului %s.\n",fisier);
		system("pause");
		exit(1);
	}

	if(!fis_db)
	{
		printf("Eroare la deschiderea fisierului db.txt .\n");
		system("pause");
		exit(1);
	}

	char *linie,*linie_db;

	if(!(linie=(char*)malloc(sizeof(char)*500)))
	{
		printf("Eroare la alocarea memoriei pentru o linie din %s.\n",fisier);
		system("pause");
		exit(1);
	}

	if(!(linie_db=(char*)malloc(sizeof(char)*700)))
	{
		printf("Eroare la alocarea memoriei pentru o linie din db.text.\n");
		system("pause");
		exit(1);
	}

	fgets(linie_db,500,fis_db);

	int ok=0;

	while(!feof(fis))
	{
		fgets(linie,500,fis);
		ok=0;
		
		while(!feof(fis_db)&&!ok)
		{
			fgets(linie_db,700,fis_db);
			if(strstr(linie_db,linie)!=NULL)
				ok=1;
		}
		
		if(ok==0)
			printf("%s\n",linie);

		rewind(fis_db);
		fgets(linie_db,500,fis_db);
	}

	free(linie);
	free(linie_db);
	fclose(fis);
	fclose(fis_db);
}


int main()
{
	char *fisier;

	printf("Introduceti numele fisierului ce contine citate: ");
	if(!(fisier=(char*)malloc(30*sizeof(char))))
	{
		printf("Eroare la alocarea memoriei pentru numele fisierului.\n");
		system("pause");
		return 0;
	}

	do
		gets(fisier);
	while(strlen(fisier)>29);

	printf("\n\nCitatul(-le) care nu sunt in db.txt este(sunt):\n");
	viewDiff(fisier);
	system("pause");
	return 0;
}
