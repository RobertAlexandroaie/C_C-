/*

     5. Să se testeze dacă un număr este prim. 
        Observaţie: Punctajul maxim va fi acordat soluţiilor cu complexitatea timp O(√n). 
        Exemple: 1000003 este prim, dar 1000002 este compus, deoarece este divizibil şi prin 3. 
*/

#include<iostream>
#include<stdio.h>

int main()
{
	int div,numar;

	printf("Introduceti numarul: ");
	scanf("%d", &numar);

	div=3;
	if(numar==2) 
	{
		printf("Numarul este prim!\n");
		system("pause");
		return 0;
	}
	if(numar%2==0)
	{
		printf("Numarul NU este prim!\n");
		system("pause");
		return 0;
	}
	else
		if(numar==3)
		{
			printf("Numarul este prim!\n");
			system("pause");
			return 0;
		}
		else
			if(numar>3)
				while(div<=sqrt((float)numar))
					if (numar%div==0)
					{
						printf("Numarul NU este prim!\n");
						system("pause");
						return 0;
					}
					else div=div+2;

	printf("Numarul este prim!\n");
	system("pause");
	return 0;
}
