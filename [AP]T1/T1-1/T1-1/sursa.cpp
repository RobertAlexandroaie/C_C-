/*
1. Să se scrie o funcţie care să testeze dacă un număr este palindrom. 
        Un număr este palindrom dacă citit de la dreapta la stânga este egal cu numărul citit de la  
        stânga la dreapta. 
        Exemple: 36463 este palindrom, dar 2646 nu este palindrom. 
*/

#include<iostream>
#include<stdio.h>

int main()
{
	int numar, oglindit, x;

	printf("Introduceti numarul: ");
	scanf("%d", &numar);

	x=numar;
	oglindit=0;

	while(x>0)
	{
		oglindit=oglindit*10+x%10;
		x=x/10;
	}

	if(oglindit==numar)
		printf("Numarul este palindrom!\n");
	else
		printf("Numarul nu este palindrom!\n");

	
	system("pause");
	return 0;
}