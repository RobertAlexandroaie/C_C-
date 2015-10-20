/*
#include <stdio.h>

//Calculul factorialului unui numar - recursiv

unsigned int fact_iter(unsigned int nr){
	_asm{
		//completati
	}
}


void main(){
	int nr,fact;
	printf("nr = ");
	scanf("%u",&nr);
	_asm{
		//completati
	}
	printf("%u! = %u",nr,fact);
}


*/

#include <iostream>
#include <stdio.h>

//Calculul factorialului unui numar - recursiv

unsigned int fact_rec(unsigned int nr)
{
	_asm
	{
		mov ebx,[ebp+8];

		cmp ebx,0;
		ja _rec;
		
		mov eax,1;
		jz _exit;

		dec ebx;
		call fact_rec;

_rec:
		mul ebx;
_exit:
	}
}


void main(){
	int nr,fact;
	printf("nr = ");
	scanf("%u",&nr);
	_asm
	{
		push nr;
		call fact_rec;
		
		mov fact,eax;
		add esp,4;
	}
	printf("%u! = %u",nr,fact);
}

