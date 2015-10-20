/*


9.  Să se determine ecuaţia unei drepte care trece prin două puncte în plan. 
   Exemplu: pentru punctele (2, 1) şi (5, 7), ecuaţia dreptei este 2x – y – 3 = 0. 

*/

#include<iostream>
#include<stdio.h>


int main()
{
	int x1,x2,y1,y2,a,b,c;

	printf("Coordonatele primului punct\n");
	
	printf("Abscisa(x): ");
	scanf("%d", &x1);

	printf("Ordonata(y): ");
	scanf("%d", &y1);
	
	printf("\n\n\nCoordonatele celui de-al doilea punct\n");
	
	printf("Abscisa(x): ");
	scanf("%d", &x2);

	printf("Ordonata(y): ");
	scanf("%d", &y2);

	a=y1-y2;
	b=x2-x1;
	c=x1*y2-x2*y1;

	int max=a>b?a:(b>c?b:c);


	for(int i=2;i<=max;i++)
		if((a%i==0)&&(b%i==0)&&(c%i==0))
		{
			a=a/i;
			b/=i;
			c/=i;
		}
	
	if(a<0)
	{	
		a*=-1;
		b*=-1;
		c*=-1;
	}
	printf("Ecuatia dreptei de tip ax+by+c=0 este: (%d)x+(%d)y+(%d)=0.\n\n\n\n",a,b,c);
	system("pause");
	return 0;

}