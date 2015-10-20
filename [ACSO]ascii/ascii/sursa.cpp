#include<iostream>
#include<stdio.h>

void Reverse(char *text)
{
	_asm
	{
		mov eax,[ebp+8];
		mov ebx,0;
bucla:
		cmp [eax+ebx],97;
		jge _lmica1;
		cmp [eax+ebx],65;
		jge _lmare1;
_lmica1:
		cmp [eax+ebx],122;
		jle _lmica;
_lmare1:
		cmp [eax+ebx],90;
		jle _lmare;
_lmica:
		mov ecx,[eax+ebx];
		sub ecx,32;
		mov [eax+ebx],ecx;
		jmp exit;
_lmare:
		mov ecx,[eax+ebx];
		add ecx,32;
		mov [eax+ebx],ecx;

exit:
		cmp [eax+ebx],0;
		inc ebx;
		jnz bucla;
	}
}

int main()
{
	char text[]="a2B5d";
	
	Reverse(text);

	printf("%s ",text);
	system("pause");
	return 0;
}