/*
matrice nxn
pe fiecare linie avem nr coloane=index linie+1;
a[i][j]=i+j;
*/

#include<iostream>
#include<stdio.h>

int a[10][10];

int main()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			a[i][j]=i+j;
		}
	}

	for(int i=0;i<10;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}