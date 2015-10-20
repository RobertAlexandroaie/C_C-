#include <stdio.h>

//Sa se scrie codul in limbaj de asamblare care oglindeste bitii  unui numar

void main(){
	unsigned int number;
	number = 140;

	_asm{
		/* Completati */
	}
	if( number != 822083584)
		printf("Failed! Your result is %d\n",number);
	else
		printf("OK!");	
}