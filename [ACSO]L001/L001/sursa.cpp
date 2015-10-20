/*

#include <stdio.h>

//Sa se scrie codul in limbaj de asamblare care inverseaza bitii  unui numar

void main(){
	char number;
	number = 140;

	_asm{
		 Completati 
	}
	if( number != 49)
		printf("Failed! Your result is %d\n",number);
	else
		printf("OK!");	
}

*/

#include<stdio.h>
#include<iostream>

void main()
{
	char number;
	number = 140;

	_asm
	{
		mov bh,number
		mov bl,bh
		shr bl,7
		mov al,bl

		mov bl,bh
		and bl,64
		shr bl,5
		or al,bl

		mov bl,bh
		and bl,32
		shr bl,3
		or al,bl

		mov bl, bh
		and bl,16;
		shr bl,1
		or al,bl

		mov bl,bh
		and bl,8
		shl bl,1
		or al,bl

		mov bl,bh
		and bl,4
		shl bl,3
		or al,bl

		mov bl,bh
		and bl,2
		shl bl,5
		or al,bl

		mov bl,bh
		and bl,1
		shl bl,7
		or al,bl

		mov number,al

	}

	if( number != 49)
		printf("Failed! Your result is %d\n",number);
	else
		printf("OK!");

	system("pause");
}
