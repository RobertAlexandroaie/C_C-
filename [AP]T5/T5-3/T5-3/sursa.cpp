#include<stdio.h>
#include<iostream>

int n,s,x[100],m,suma,q,y;

typedef struct moneda
{
	int valoare;
	int numar;
}moneda;

moneda a[100];

int valid(int k)
{
	int i,nr=0,j;

	for(i=1;i<=k;i++)
		if(x[i]==x[k])
			nr++;
	
	for(i=1;i<=n;i++)
		if(x[k]==a[i].valoare)
			j=i;

	if(nr>a[j].numar)
		return 0;
	if(k>1)
		for(i=1;i<=k;i++)
			if(x[i]>x[k])
				return 0;
	if(x[k]+suma<=s)
		suma=suma+x[k];
	else
		return 0;
	
	return 1;
}

void back(int k)
{
	if(s==suma)
	{
		int i;
		for(i=1;i<k;i++)
			printf("%d ",x[i]);
		printf("\n");
	}
	else 
	{
		int i;
		for(i=1;i<=n;i++)
		{
			x[k]=a[i].valoare;
			if(valid(k)==1)
			{
				back(k+1);
				suma=suma-x[k];
			}
		}
	}
}

int main()
{
	int i;
	printf("Introduceti suma de bani:");
	scanf("%d",&s);

	printf("Introduceti numarul de tipuri de bancnote:");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		printf("Introduceti valoarea bancnotei de tipul [%d]:",i);
		scanf("%d",&a[i].valoare);

		printf("Introduceti numarul de bancnote de tipul [%d]:",i);
		scanf("%d",&a[i].numar);

		printf("-------------------------------------------------\n");
	}
	back(1);

	system("pause");
	return 0;
}

                  
                  
