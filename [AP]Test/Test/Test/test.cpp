#include<iostream>
#include<stdio.h>

int main()
{
	int a[100], i, *ptr;
	ptr=a;

	for (i=0;i<100;i++)
	{
		*(ptr+i)=1;
	}

	for(i=0;i<100;i++)
	{
		printf("%d ", *(ptr+i));
	}

	system("pause");
	return 0;
}