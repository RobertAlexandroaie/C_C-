void svnUpdate(char *fisier)
{
	if(svnCheckDB())
	{
	FILE *fisier1, *fis2;
	fisier1=fopen(fisier, "w");
	fis2=fopen("db.txt", "r");
	if(!fisier1)
	{
		printf("eroare la deschiderea fisierului.\n");
		exit(1);
	}
	if(!fis2)
	{
		printf("eroare la deschiderea fisierului.\n");
		exit(1);
	}
	char *v;
	if(!(v=(char*)malloc(sizeof(char)*500)))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}
	fgets(v, 500, fis2);
	int i, j;
	while(!feof(fis2))
	{
		i=0;
		j=0;
		fgets(v, 500, fis2);
			while(i<4)
			{
				if(v[j]==';')
				i++;
				j++;
			}
			fputs(v+j, fisier1);
	}
	free(v);
	fclose(fisier1);
	fclose(fis2);
	}
else
		printf("Formatul fisierului db.txt este incorect.\n");	
}