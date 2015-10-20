/*

     5.  Se consideră un tablou cu n elemente. Să se decidă dacă există un element majoritar (cu  
         numărul de apariţii mai mare decât n/2). 
         Observaţie: Punctajul maxim va fi acordat soluţiilor cu complexitatea timp O(n). 
         A se consulta şi:  http  ://  infoarena   . ro   / problema   - majoritatii   - votului   /  

*/
#include<iostream>
#include<stdio.h>


int main()
{
    int i,n,a[100],nr_maj,c=0;

	printf("Introduceti numarul de valori: ");
	scanf("%d",&n);

    for (i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d", &a[i]);

        if(c==0)
		{
            nr_maj=a[i];
            c++;
        }
		else
			if(a[i]==nr_maj)
				c++;
			else
				c--;
    }
	
	c=0;
	for (i=0;i<n;i++)
		if(a[i]==nr_maj)
			c++;

    if(c>(n/2))
        printf("Numarul majoritar este: %d.\n", nr_maj);
    else
        printf("Nu avem numar majoritar!\n");



	system("pause");
	return 0;
}