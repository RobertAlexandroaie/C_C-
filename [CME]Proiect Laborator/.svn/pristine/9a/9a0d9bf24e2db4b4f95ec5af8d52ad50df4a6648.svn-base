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