#include <stdio.h>
int suma_pare_vector (int *, int )
{
	_asm
	{
		mov ebx, [ebp+8]
		mov eax, 0
		mov ecx, [ebp+12]
		mov esi, 0
bucla:
		cmp esi, ecx
		je end_bucla
		push eax
		mov eax, [ebx+4*esi]
		mov edi, dword ptr 2
		div edi
		cmp edx, 0
			je incrementare
			pop eax
			add eax, [ebx+4*esi]
		inc esi
			jmp bucla
incrementare:
		pop eax
			inc esi
			jmp bucla
end_bucla:
	}
}
void main()
{
	int v[5]={5,1,2,3,6};
	int *p=v;
	int s;
	_asm{
	push 5
		push p
		call suma_pare_vector
		add esp, 8
		mov s, eax
	}
	printf("Suma: %d", s);
}
