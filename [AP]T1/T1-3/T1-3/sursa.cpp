/*

3.  Scrieţi o funcţie care calculează cifra de control a unui numar natural. Cifra de control se obţine  
        calculând suma cifrelor numărului, apoi suma cifrelor numărului obţinut etc., până se ajunge la o  
        singură cifră. 
        Exemplu: 4879 → 28 → 10 → 1.
*/

#include<iostream>
#include<stdio.h>
int main()
{
	int numar,x;
	
	x=0;

	printf("Introduceti numarul: ");
	scanf("%d",&numar);
	
	while(numar>9)
	{
		while(numar>0)
		{
			x=x+numar%10;
			numar=numar/10;
		}
		numar=x;
		x=0;
	}

	printf("Numarul de control este: %d\n", numar);
	system("pause");
	return 0;
}