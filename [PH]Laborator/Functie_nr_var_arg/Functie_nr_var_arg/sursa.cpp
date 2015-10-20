#include<stdio.h>
#include<iostream>
#include<stdarg.h>

int suma(int n_arg,...)
{
	int i,s=0;

	va_list argumente;
	va_start(argumente,n_arg);

	for(i=0;i<n_arg;i++)
		s+=va_arg(argumente,int);

	va_end(argumente);
	return s;
}

int main()
{
	printf("%d\n",suma(3,1,2,3));
	system("pause");
	return 0;
}