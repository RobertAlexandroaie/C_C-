/*

 7.  Scrieţi un program C care citeşte elementele unei matrici pătratice de dimensiune n şi afişează  
     la ieşirea standard şirul format prin parcurgerea acesteia în spirală, pornind din colţul stânga  
	 sus către dreapta până în centrul matricei. 
     Exemplu: pentru matricea 
     1 2 3 
     4 5 6 
     7 8 9 
     se va afişa şirul 1 2 3 6 9 8 7 4 5. 
	
	 1  2  3  4
	 12 13 14 5
	 11 16 15 6
	 10 9  8  7

	 4  5  6  7
	 3  14 15 8
	 2  13 16 9
	 1  12 11 10

	 7  8  9  10
	 6  15 16 11
	 5  14 13 12
	 4  3  2  1

	 10 11 12
	 9  16 13
	 8  15 14

	 12 13 14
	 11 16 15
	 10 9  8

	 14 15
	 13 16

	 15 16
	 14 13

	 16


*/
#include<iostream>
#include<stdio.h>


int a[100][100], aux[100][100], n;

void citiremp(int a[][100], int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d", &a[i][j]);
		}
}


void rastoarnamp(int a[][100], int n)
{
	int i,j,l,c;
	for(i=0,c=n-1; i<n; i++,c--)
		for(j=0,l=0; j<n; j++,l++)
			aux[i][j]=a[l][c];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=aux[i][j];
}


void afisarel()
{
	for(int j=1;j<n;j++)
		if(a[0][j]!=0)
			printf("%d ",a[0][j]);
}

void afisaremp(int a[][100], int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}

int main()
{
	printf("Introduceti numarul de linii si coloane: ");
	scanf("%d",&n);

	int c;
	citiremp(a,n);
	
	printf("\n%d ",a[0][0]);
	//printf("\n");
	afisarel();
	//printf("\n");
	c=1;
	int m=3;
	while(n>1)
	{
		if(c<m)
		{
			//printf("\n");
			//if(c==0) afisarel(); 
			rastoarnamp(a,n);
			//afisaremp(a,n);
			afisarel();		
			c++;
			//printf("\n");
		}
		else
			if(m==1&&c==1)
			{
				rastoarnamp(a,n);
				afisarel();
				n--;
			}
			else
			{
				rastoarnamp(a,n);
				n--;
				afisarel();
				c=1;
				m--;
			}
	}
	printf("\n\n");
	system("pause");
	return 0;
}