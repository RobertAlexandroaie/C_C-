/*
#include <stdio.h>

//Completati exemplul urmator astfel incat functia max sa returneze maximun dintre a si b

int max(int a, int b){
	int maxim;
	_asm{
		//completati
	}
	return maxim;
}

void main(){
	int a,b;
	printf("a = ");
	scanf("%d",&a);
	printf("b = ");
	scanf("%d",&b);
	printf("MAX(a,b) = %d",max(a,b));
}

*/


#include<iostream>
#include<stdio.h>

int max(int a, int b){
	int maxim;
	_asm{
		mov eax,a;
		mov ebx,b;
		cmp eax,ebx;
		mov maxim,eax;
		jge finish
		mov maxim,ebx;

finish:

	}
	return maxim;
}

void main(){
	int a,b;
	printf("a = ");
	scanf("%d",&a);
	printf("b = ");
	scanf("%d",&b);
	printf("MAX(a,b) = %d\n\n",max(a,b));
	system("pause");
}