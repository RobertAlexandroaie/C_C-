#include<iostream>
#include<stdio.h>

int main()
{
	int a=2;
	int *pa;

	pa=&a;
	++*pa;

	int b;
/*
	_asm
	{
		lea [eax],a;
		add [eax],2;
	}
	*/
	printf("%d ",a);

	system("pause");
	return 0;
}