#include<iostream>

using std::cout;
using std::cin;

class Vector
{
	int n;
	int v[20];

public:
	Vector()
	{
		_asm
		{
			mov eax,[ebp-8];
			mov dword ptr [eax],0;
		}
	}

	void afisare()//c++
	{
		int i;
		for(i=0;i<n;i++)
			cout<<"v["<<i<<"]="<<v[i]<<"\n";
		cout<<"\n\n";
	}
		
	void adauga(int x)//asm
	{
		_asm
		{
			add [ecx],1;
			mov ebx,[ebp+8];

			mov eax,[ecx];

			mov [ecx+4*eax],ebx;
		}
	}

	//var mea <--gresita!!!!
	void add2(...)
	{
		_asm
		{
			mov ebx,[ebp+4];
			add ebx,2;
			mov al,[ebx];
			shr al,2;
			movzx ecx,al;//nr-ul de parametri din functie
			dec ecx;

			mov eax,[ebp+8];//pointerul this
			mov edx,[eax];//nr-ul initial de elemente din vector

			mov esi,eax;//pointerul this
			mov eax,edx;//nr-ul initial de elemente din vector
			
			mov ebx,4;//dimensiunea lui int
			mul ebx;//pun in eax dimensiunea in octeti a nr. initial de elemente din vector

			add esi,eax;//adresa urmatorului element din vector
			
			mov eax,ecx;//nr de elemente ce trebuie adaugate
			mul ebx;//pun in eax dimensiuena in octeti a nr-lui de parametri

			mov ebx,3;//contor
			
_bucla:
			cmp ecx,0;//compar sa vad daca mai am elemente de adaugat
			je _final;


			mov edi,[ebp+4*ebx];//element
			mov [esi],edi;//adaug elementul la sfarsitul vecoturlui
			inc ebx;//cred "ordinul" parametrului
			dec ecx;//scad numarul de elemente ce trebuie adaugate
			add esi,4;//actualizez noul sfarsit al vectorului
			jmp _bucla;
_final:
			mov ebx,[ebp+8];//pointerul this
			mov edx,0;//initializare edx pt impartire
			mov ecx,4;//sizeof(int)
			div ecx;
			dec eax;//actualizez cate elemente am adaugat
			add [ebx],eax;//actualizez nr-ul de elemente din 
		}
	}
	

	//var lui alex
	void adauga2(...)
	{
		int nr;
		_asm
		{
			mov ebx,[ebp+4];
			add ebx,2;
			mov al,[ebx];
			shr al,2;
			movzx ebx,al;
			dec ebx;
			mov nr,ebx;
			//am aflat nr de parametri

			mov ecx,[ebp+8]
			add [ecx],1;
			mov eax,[ecx];
			mov ebx,[ebp+12];
			mov [ecx+eax*4],ebx;
			//am adaugat la vector primul parametru

			mov edi,12;
			dec nr;
			cmp nr,0;
			jne _adauga;
			jmp _stop;

_adauga:
			add edi,4;
			add [ecx],1;
			mov eax,[ecx];
			mov ebx,[ebp+edi];
			mov [ecx+eax*4],ebx;
			dec nr;
			cmp nr,0;
			jne _adauga;
_stop:
		}
	}


	/*
	void sortare()
	{
		_asm
		{
			mov eax,[ecx];//nr de elemente din vector
_do:
			mov esi,0;//pt test
			mov ebx,1;//index pt primul element din vector
_for:
			cmp ebx,eax;
			ja _endfor;
			mov edx,[ecx+4*ebx];
			inc ebx;
			mov edi,[ecx+4*ebx];
			cmp 
		}
	}
	*/
	
	};

int main()
{
	Vector v1;
	int *lung;
	lung=(int *)(&v1);

	int *vect;
	vect=lung+1;

	*lung=5;
	*vect=1;
	*(vect+1)=2;
	*(vect+2)=3;
	*(vect+3)=4;
	*(vect+4)=5;
	
	v1.afisare();
	cout<<"\n\n";
	v1.adauga(6);
	v1.afisare();

	//v1.add2(8,9,10,11,12);
	
	//add 9
	_asm
	{
		push 9;
		lea ecx,v1;
		call Vector::adauga
	}
	v1.afisare();

	//v1.add2 (10,11,12,13);
	
	_asm
	{
		push 13;
		push 12;
		push 11;
		push 10;
		lea ebx,v1;
		push ebx;

		call Vector::adauga2;
		add esp,20;
	}
	v1.afisare();
	
	Vector v2;
	v2.afisare();

	system("pause");
	return 0;
}