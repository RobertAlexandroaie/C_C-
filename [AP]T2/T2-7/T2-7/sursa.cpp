/*
7.  Scrieţi un program C care citeşte elementele unei matrici pătratice de dimensiune n şi afişează  
    la ieşirea standard şirul format prin parcurgerea acesteia în spirală, pornind din colţul stânga
	sus către dreapta până în centrul matricei. 
	Exemplu: pentru matricea 
	1 2 3 
	4 5 6 
	7 8 9 
	se va afişa şirul 1 2 3 6 9 8 7 4 5.

*/

#include<stdio.h>
#include<iostream>


int main ()
{
	int a[100][100], i, j, k, n;

	printf("Introduceti numarul de linii si coloane: ");
	scanf("%d", &n);

	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
		{
				printf("a[%d][%d]=", i, j);
				scanf("%d", &a[i][j]);
		}

	
	printf("Numerele afisate in spirala sunt: ");
	
	int m=0;
	if(n%2==0)
		m=n/2;
	else
		m=n/2+1;

	for(k=1; k<=m; k++)
	{
		for(i=k; i<=n-k+1; i++)
			printf("%d ", a[k][i]);
		for(i=k+1; i<=n-k+1; i++)
			printf("%d ", a[i][n-k+1]);
		for(i=n-k; i>=k; i--)
			printf("%d ", a[n-k+1][i]);
		for(i=n-k; i>=k+1; i--)
			printf("%d ", a[i][k]);
	}
	printf("\n\n");
	
	system("pause");
	return 0;
}

