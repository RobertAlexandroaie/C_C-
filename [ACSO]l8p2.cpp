#include <stdio.h>

//Sa se scrie codul in limbaj de asamblare care inverseaza bitii  unui numar

void main(){
	char number;
	number = 140;

	_asm{
		/* Completati */
	}
	if( number != 49)
		printf("Failed! Your result is %d\n",number);
	else
		printf("OK!");	
}