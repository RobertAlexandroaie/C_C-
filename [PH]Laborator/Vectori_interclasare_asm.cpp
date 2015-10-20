#include <stdio.h>
#include <malloc.h>

struct Vector{
	short nr;
	int* v;
};


Vector interclaseaza_v(Vector& n, Vector& m)
{
	_asm{
			;luam cele doua dimensiuni
			mov esi, [ebp+8]
			movzx esi, word ptr[esi]
			mov edi, [ebp+12]
			movzx edi, word ptr [edi]
			;Adunam dimensiunile si alocam spatiu pentru vectorul de returnat
			mov eax,esi
			add eax,edi
			shl eax,2
			push eax
			call dword ptr malloc	;aveti grija ca urmatorii registri se modifica: eax, ecx si edx
			add esp, 4
			;pointerul returnat trebuie pus in edx
			mov edx,eax
			;luam pointerii celor doi vectori
			mov eax,[ebp+8]
			mov eax,[eax+4]
			mov ebx,[ebp+12]
			mov ebx,[ebx+4]
			;stabilim care dintre cei doi vectori este mai mare (interschimbam nr de elemnte si cei doi ptr daca nu e cum dorim)
			cmp esi,edi
			jl ordered
			mov ecx,esi
			mov esi,edi
			mov edi,ecx
			mov ecx,eax
			mov eax,ebx
			mov ebx,ecx
	ordered:
			;vectorul cu dimensiunea in esi si pointerul in eax are mai putine elemente decat cel cu
			;dimensiunea in edi si pointerul in ebx. Printr-un singura parcurgere copiem din ambii vectori
			;in vectorul de returnat, esi elemente.
			mov ecx,0		;contor de bucla
			push edi		;salvam edi pe stiva, pentru ca il vom utiliza in procesul de copiere  a informatiei
	copiere_comun:					
			cmp ecx,esi
			jge final_copiere_comun
			mov edi,[eax+4*ecx]
			mov [edx+8*ecx],edi
			mov edi,[ebx+4*ecx]
			mov [edx+8*ecx+4],edi
			inc ecx
			jmp copiere_comun
	final_copiere_comun:
			;Recuperam numarul de elemente din vectorul al carui ptr este in ebx (cu dimensiune mai mare)
			pop edi			
			;Calculam adresa elementului cu indexul esi, din vectorul de returnat 
			;(deoarece elementul de pe pozitia esi+k din vectorul cu ptr in ebx va trebui copiat pe pozitia
			;2*esi+k in vectorul final)
			lea edx,[edx+4*esi]
			;copiez restul de elemente din vectorul cu ptr in ebx. ecx va lua pe rand valorile: 
			;esi+0, esi+1, ..., esi+edi-1, iar dupa aceea se realizeaza un salt la final_copiere_rest
	copiere_rest:
			cmp ecx,edi
			jae final_copiere_rest
			mov eax,[ebx+4*ecx]
			mov [edx+4*ecx],eax
			inc ecx
			jmp copiere_rest
	final_copiere_rest:
			;punem in ax rezultatul sumei dintre si si di
			mov ax,si
			add ax,di
			shl esi,2
			sub edx,esi
	}
}

void main()
{
	Vector v1;
	Vector v2;

	v1.nr = 2;
	v1.v = (int*) new int[2];
	v1.v[0] = 1;
	v1.v[1] = 2;
	
	v2.nr = 5;
	v2.v = (int*) new int[5];
	v2.v[0] = 3;
	v2.v[1] = 4;
	v2.v[2] = 5;
	v2.v[3] = 6;
	v2.v[4] = 7;

	Vector r1v = interclaseaza_v(v1,v2);

	for (int i=0;i<r1v.nr;i++)
		printf(" %d ",*(r1v.v+i));
}