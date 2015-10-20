#include<iostream>
#include<stdio.h>
#include<ctype.h>

#include<stdio.h>

int x[10];
int n;

void afisare()
{
	int i,j,max=0;


	for(i=1;i<=n;i++)
		if(x[i]>max) max=x[i];

	for(i=1;i<=max;i++)
	{
		fprintf(stdout,"{");
		for(j=1;j<=n;j++)
			if(x[j]==i)
				fprintf(stdout,"%d ",j);
		fprintf(stdout,"\b} ");
	}
	fprintf(stdout,"\n");
}

void back(int k)
{
	int i,max;
	if(k==n+1)
		afisare();
	else
	{
		max=0;
		for(i=1;i<=k-1;i++)
			if(x[i]>max)
				max=x[i];

		for(i=1;i<=max+1;i++)
		{
			x[k]=i;
			back(k+1);
		}
	}
}

int main()
{
	printf("n=");
	scanf("%d",&n);

	if((n>=97&&n<=92)||(n>=65&&n<=90)||(n==0))
	{
		fprintf(stdout,"imposibil\n");
		system("pause");
		return 0;
	}
	
	back(1);

	system("pause");
	return 0;
}