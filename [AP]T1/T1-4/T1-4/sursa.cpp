/*
4.  Spunem că un număr natural este perfect dacă este egal cu suma divizorilor săi strict mai mici  
        decât el. 
             1. Scrieţi o funcţie care verifică dacă un număr este perfect. 
             2.  Să se determine toate numerele perfecte mai mici ca un număr natural n dat. 

        Observaţie: Punctajul maxim va fi acordat soluţiilor cu complexitatea timp O(√n). 
        Exemplu: 28 este un număr perfect, deoarece 28 = 1 + 2 + 4 + 7 + 14. Pentru n = 1000, se vor  
        determina numerele 6, 28, 496.
		
*/
#include<iostream>
#include<stdio.h>
#include<math.h>


int perfect(int numar)
{
	int s, div;
	
	s=0;
	div=1;
	s+=div;
	div++;
	
	while(div<sqrt((float)numar))
		if(numar%div==0)
		{
			s+=div+(numar/div);
			div++;
		}
		else div++;
	
	if(s==numar) return 1;
	else return 0;
}

int main()
{
	int max,i=6,k=1,j=1;

	printf("Afisati numerele perfecte pana la:(introduceti valoare) ");
	scanf("%d", &max);

	for(i=6;i<=max;i=i+k)
		if(perfect(i))
		{
			printf("%d. ",j);
			printf("%d\n",i);
			j++;
			k++;
		}
	

	system("pause");
	return 0;
}