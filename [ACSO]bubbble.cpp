#include<stdio.h>
#include<stdlib.h>
/*
do{
schimb=0;
for(i=0; i<nr-1; i++)
if(v[i]>v[i+1])
{
aux=v[i];
v[i]=v[i+1];
v[i+1]=aux;
schimb=1;
}
}while(schimb);
*/
void ordonare(int *, int);
void ordonare(int *, int)
{
	_asm{
		mov ebx, [ebp+8]
		mov esi, [ebp+12]
		dec esi
do_while:
		mov eax, 0
		mov edi, 0
for_i:
		cmp edi, esi
			je end_for_i
			inc edi
			mov edx, [ebx+4*edi]
			dec edi
			cmp [ebx+4*edi], edx
		ja swap
			inc edi
			jmp for_i
swap:
	mov ecx, [ebx+4*edi]
		push eax
			inc edi
			mov eax, [ebx+4*edi]
	mov [ebx+4*edi], ecx
		dec edi
		mov [ebx+4*edi], eax
			pop eax
		inc eax
		inc edi
		jmp for_i
end_for_i:
		cmp eax, 0
			jne do_while
			je end_do_while
end_do_while:
	}
}
int main()
{
	int *vector;
	int nr;
	do{
		printf("Introduceti numarul de elemente.\n");
		scanf("%d", &nr);
	}while(nr<=0 || nr>100);
	if(!(vector=(int *)malloc(sizeof(char)*nr)))
	{
		printf("eroare la alocarea memoriei.\n");
		exit(1);
	}
	int i;
	for(i=0; i<nr; i++)
	do{
		printf("v[%d]=", i+1);
		scanf("%d", &vector[i]);
	}while(vector[i]<=0 || vector[i]>10000);
	_asm{
		push nr
			push vector
			call ordonare
			add esp, 8
	}
	for(i=0; i<nr; i++)
		printf("%d ", vector[i]);
	free(vector);
	return 0;
}