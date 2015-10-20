/*

8.	Să se definească un tip pentru reprezentarea datelor calendaristice. Să se scrie o funcţie care  
	primeşte o dată calendaristică şi returnează succesorul acesteia. 
	Exemplu: succesorul datei "31.10.2010" este "1.11.2010". 


*/

#include<stdio.h>
#include<iostream>

typedef struct Date
{
	int luna;
	int an;
	int zi;
} Date;


Date data_suc,data,d;



int bisect(int an)
{
	if(((an%4==0)&&(an%100!=0))||(an%400==0)) return 1;
	else return 0;
}

void citired()
{
	int a,l,z;
	do
	{
		printf("An=");
		scanf("%d", &a);
	}
	while(a<0);
	data.an=a;

	do
	{
		printf("Luna=");
		scanf("%d", &l);
	}
	while(l<0||l>12);
	data.luna=l;

	do
	{
		printf("Zi=");
		scanf("%d", &z);
	}
	while(z<0||z>31);
	data.zi=z;
	printf("\n\n\n");
}


Date dsuc(Date dat)
{
	Date d;
	d.zi=dat.zi+1;
	d.luna=dat.luna;
	d.an=dat.an;
	
	if(d.zi>=31)
	{
		d.zi=1;
		d.luna++;
	}

	if((d.zi>29)&&(d.luna==2)&&(bisect(d.an)==1))
	{
		d.zi=1;
		d.luna++;
	}

	if(d.zi>31&&((d.luna<=7&&d.luna%2==1)||(d.luna>7&&d.luna%2==0)))
	{
		d.zi=1;
		d.luna++;
	}

	if((d.zi>30)&&(((d.luna<=7)&&(d.luna%2==0))||((d.luna>7)&&(d.luna%2==1))))
	{
		d.zi=1;
		d.luna++;
	}
	
	if(d.luna>12)
	{
		d.zi=1;
		d.luna=1;
		d.an++;
	}

	return d;
	//printf("%d-%d-%d",d.zi,d.luna,d.an);
}


int main()
{

	citired();

	//printf("%d-%d-%d",data.zi,data.luna,data.an);
	data_suc=dsuc(data);

	printf("Data urmatoare este: %d.%d.%d.\n\n\n",data_suc.zi,data_suc.luna,data_suc.an); 

	system("pause");
	return 0;
}