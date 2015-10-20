#include<iostream>
#include<stdio.h>

using namespace std;

void main()
{
	char s[]="test\n";
	char f[]="%s";
	//printf("%s",s);

	_asm
	{
		lea eax,s;
		push eax;
		lea eax,f;
		push eax;
		call dword ptr [printf];
		add esp,8;
	}
	system("pause");
}