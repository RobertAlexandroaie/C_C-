/*

suma nr (rang) par, suma nr (rang) impar;

*/

#include<iostream>
#include<stdio.h>

int main()
{
	int a[100], i, n, sp=0,si=0,srp=0,sri=0;

	printf("Introduceti numarul de valori: ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d", &a[i]);

		if(i%2==0) srp+=a[i];
		else sri+=a[i];

		if(a[i]%2==0) sp+=a[i];
		else si+=a[i];
	}

	printf("Suma numerelor pare: %d. Suma numerelor impare: %d.\nSuma de pe pozitii pare: %d. Suma de pe pozitii impare: %d.\n",sp,si,srp,sri);

	system("pause");
	return 0;
}