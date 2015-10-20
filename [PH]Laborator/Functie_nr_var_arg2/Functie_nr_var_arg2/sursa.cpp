#include<iostream>
#include<stdio.h>
#include<stdarg.h>

int suma2(...)
{
	int *p,nr;
	int s=0;
	_asm
	{
		mov ebx,[ebp+4];
		add ebx,2;
		mov al,[ebx];
		shr al,2;
		movzx ecx,al;
		mov nr,ecx;
		mov p,ebp;
		add p,8;
	}

	for(int i=0;i<nr;i++)
		s+=p[i];

	return s;
}

int main()
{
	printf("%d\n",suma2(0,0,1,-476923854,0));
	system("pause");
	return 0;
}