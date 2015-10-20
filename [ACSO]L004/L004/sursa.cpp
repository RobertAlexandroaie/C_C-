/*
#include <stdio.h>

//Sa se scrie codul in limbaj de asamblare care oglindeste bitii  unui numar

void main(){
	unsigned int number;
	number = 140;

	_asm{
		/* Completati 
	}
	if( number != 822083584)
		printf("Failed! Your result is %d\n",number);
	else
		printf("OK!");	
}
*/

#include<iostream>
#include<stdio.h>

void main(){
	unsigned int number;
	number = 140;

	_asm{
		mov edx,number;
		xor ebx,ebx;
		mov cl,31;
		
_bucla:
		mov eax,edx;
		and eax,1;
		shl eax,cl;
		or ebx,eax;
		shr dx,1;
		dec cl;
		cmp edx,0;
		ja _bucla;
		mov number,ebx;
	}

	if( number != 822083584)
		printf("Failed! Your result is %d\n",number);
	else
		printf("OK!");	
	system("pause");
}