/*
#include <stdio.h>

//Calculul factorialului unui numar - iterativ

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

#include <stdio.h>

//Calculul factorialului unui numar - iterativ

unsigned int fact_iter(unsigned int nr){
	_asm{
		mov ebx,[ebp+8];
		mov eax,1;
_bucla:
		mul ebx;
		dec ebx;
		cmp ebx,1;
		ja _bucla;

		/* mai smecher:
		xor eax,eax;
		inc eax;
		mov ecx,[ebp+8];
		test ecx,ecx;
		jz exit;
loopback:
		mul ecx;
		loop loopback;
exit:
		*/

	}
}


void main(){
	int nr,fact;
	printf("nr = ");
	scanf("%u",&nr);
	_asm{
		push nr;
		call fact_iter;
		
		mov fact,eax;
		add esp,4;
	}
	printf("%u! = %u",nr,fact);
}