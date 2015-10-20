/*

Declarare matrice 2x3, initializare cu el de la 0 la 5;

*/

#include<iostream>
#include<stdio.h>

int main()
{
	int a[2][3]={0,1,2,3,4,5};//a[i][j]={{0,1,2},{3,4,5}}

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
