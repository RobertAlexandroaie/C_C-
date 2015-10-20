/*Să se scrie o funcție f(int n) ce primește ca parametru variabila int n și returnează rezultatul calculului:
2 + 2*4 + 2*4*6 + 2*4*6*8 + … +2*4*6*8*…*2n.*/

#include<stdio.h>
#include<stdlib.h>
int f(int n);
int f(int n)
{
	/*int suma=0, i, s1=1;
	for(i=1; i<=n; i++)
	{
		s1=s1*2*i;
		suma+=s1;
	}
	return suma;*/
	_asm{
		mov edx, 0//suma
			mov edi, 1//i
			mov eax, 1
			mov ecx, n
			inc ecx
			mov ebx, 2
bucla:
		cmp edi, ecx
			je end_bucla
			push edx
			mul ebx
			mul edi
			pop edx
			add edx, eax
		inc edi
			jmp bucla
			end_bucla:
	}
}
int main ()
{
	int n=4;
	int produs=0;
	_asm{
		push n
			call f
			add esp, 4
			mov produs, edx
	}
	printf("%d\n", produs);
	return 0;
}