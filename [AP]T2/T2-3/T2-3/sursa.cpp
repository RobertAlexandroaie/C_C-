/*

     3.  Se dă un vector de numere întregi. Să se determine subsecvenţa pentru care suma elementelor  
         componente este maximă. Dacă există mai multe subsecvenţe cu această proprietate, se va  
         determina ultima subsecventă găsită. 
         Exemplu: pentru tabloul (2, 3, -4, -2, 9, -2, 1, 7, -3), subsecvenţa este (9, -2, 1, 7) 
         Observatie: Punctajul maxim va fi acordat solutiilor cu complexitatea timp O(n). 

*/

#include <iostream>
#include<stdio.h>
#include<limits.h>

 

int main()

{	
	int n,val,v[100],i=0,poz=0,sol,smax=0,st=0,dr=0;
	
	printf("Introduceti numarul de valori: ");
	scanf ("%d", &n);

	sol=INT_MIN;

	printf("Indroduceti valoare: ");
	for (i=0; i<n; ++i)
	{	
		printf("val=");
		scanf ("%d", &val);
		v[i]=val;
		if (smax<0)
		{
			smax=val;
			poz=i;
		}
		else
			smax+=val;
		if(smax>sol)
		{
			sol=smax;
			st=poz;
			dr=i;
		}
	}

	printf ("Suma maxima = %d.\nNumerele sunt:\n", sol);
	for(i=st; i<=dr; i++)
		printf("%d ",v[i]);

	system("pause");
	return 0;
}