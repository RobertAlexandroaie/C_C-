/*


     6.  Două numere naturale impare consecutive şi prime se numesc numere prime gemene. Folosind  
        testul de primalitate implementat anterior, determinaţi primele n perechi de numere prime  
        gemene. 
        Exemplu: Primele n = 3 perechi de numere prime gemene sunt (3, 5), (5, 7) şi (11, 13). 


*/

#include<iostream>
#include<stdio.h>
#include<math.h>

int prim(int numar)
{
	int div;

	div=3;
	if(numar==2)	return 1;
	if(numar%2==0) return 0;
	else
		if(numar==3) return 1;
		else
			if(numar>3)
				while(div<=sqrt((float)numar))
					if (numar%div==0) return 0;
					else div=div+2;
	return 1;
}

int main()
{
	int i,j,n,x;

	printf("Introduceti numarul de perechi: ");
	scanf("%d", &n);

	if(n==0) 
	{
		printf("Nicio pereche afisata!\n");
		system("pause");
		return 0;
	}

	i=3;
	j=5;
	x=0;

	while(x<n)
	{
		if((prim(i))&&(prim(j))&&((j-i)==2))
		{
			x++;
			printf("Perechea %d: (%d,%d)\n",x,i,j);			
			i=j;
			j+=2;
		}
		else
		{
			i=j;
			j+=2;
		}
	}
	

	system("pause");
	return 0;
}