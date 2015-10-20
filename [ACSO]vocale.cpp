#include <stdio.h>
int lungime(char *)
{
	_asm{
		mov eax, 0
		mov ebx, [ebp+8]
		mov esi, 0
bucla:
		mov ecx, [ebx+esi]
 		cmp ecx, 0
			je end_bucla
			jne checka
checka:
		cmp ecx, 65
			je incc
			jne checke
incc:
		inc eax
			inc esi
			jmp bucla
checke:
		cmp ecx, 69
			je incc
			jne checki
checki:
		cmp ecx, 73
			je incc
			jne checko
checko:
		cmp ecx, 79
			je incc
			jne checku
checku:
		cmp ecx, 85
			je incc
			jne checkaa
checkaa:
		cmp ecx, 97
			je incc
			jne checkee
checkee:
		cmp ecx, 101
			je incc
			jne checkii
checkii:
		cmp ecx, 105
			je incc
			jne checkoo
checkoo:
		cmp ecx, 111
			je incc
			jne checkuu
checkuu:
		cmp ecx, 117
			je incc
			jne inf
inf:
		inc esi
			jmp bucla
end_bucla:
	}
}
void main()
{
	char *sir="oaie";
	int l;
	_asm{
			push sir
			call lungime
			add esp, 4
			mov l, eax
	}
	printf("Numarul de vocale este: %d\n", l);
}
