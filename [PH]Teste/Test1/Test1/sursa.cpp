/*
3. Se considera urmatoarea clasa:
class NumarPrim {	
	int *Lista;
public:
	//...
};
Sa se implementeze în limbaj de asamblare metoda:
void Create(int nr);
care creeaza o lista cu primele nr numere prime.
Exemplu :
NumarPrim np;
np.Create(4); // aloca 4 elemente în câmpul Lista si pune în ele numerele [2,3,5,7]
*/

#include<iostream>

using namespace std;

class NumarPrim
{	
public:
	int *Lista;
	void Create(int nr)
	{
		_asm
		{
			mov ebx,ecx;
			movzx eax,[ebp+8];

			cmp eax,0;
			je _iesire;

			shl eax,2;

			push eax;			
			call dword ptr malloc;
			add esp,4;
			
			mov ecx,ebx;
			mov [ecx],eax;

			xor ebx,ebx;
			xor eax,eax;

			mov eax,2;
			movzx ebx,[ebp+8];
			dec ebx;
			xor edx,edx;
			xor esi,esi;
			xor edi,edi;
_bucla:
			cmp esi,ebx;
			jg _iesire;
			mov edi,dword ptr 1;
_for1:
			add edi,1;

			cmp eax,2;
			je _prim;

			cmp edi,eax;
			jge _prim;

			push eax;
			xor edx,edx;
			div edi;
			pop eax;

			cmp edx, dword ptr 0;
			je _compus;

			cmp edx, dword ptr 0;
			jne _for1;
_prim:
			push esi;
			shl esi,2;

			mov edx,[ecx];
			mov [edx+esi],eax;

			pop esi;

			add esi,1;
_compus:
			add eax,1;
			jmp _bucla;
_iesire:
		}
	}
};

void afisare(NumarPrim p)
{
	for(int i=0;p.Lista[i]!=NULL;i++)
		cout<<p.Lista[i]<<endl;
}

void main()
{
	NumarPrim np;
	np.Create(4); // aloca 4 elemente în câmpul Lista si pune în ele numerele [2,3,5,7]

	system("pause");
}