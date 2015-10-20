#include<iostream>

using namespace std;

class Stiva
{
	short nr;
	int v[100];

public:
	Stiva()
	{
		_asm
		{
			mov eax,0;
			mov [ecx],eax;
		}
	}

	void push(int i)
	{
		_asm
		{
			mov eax,[ecx];
			inc eax;
			mov [ecx],eax;
			mov ebx,[ebp+8];
			mov [ecx+4*eax],ebx;
		}
	}

	int pop()
	{
		_asm
		{
			mov ebx,[ecx];
			mov eax,[ecx+4*ebx];
		}
	}

	Stiva intersect(Stiva &st)
	{
		_asm
		{
			mov eax,[ebp+8];
			mov ebx,0;
			mov esi,[ebp+12];

			cmp [ecx],[esi];
			jle _stil2;

_for1:
			inc ebx;
			mov edx,1;
			mov edi,1;
			cmp [ecx+4*ebx],[esi+4*edx];
			je _for1;
_for2:
			inc edx;
			inc edi;
			cmp edi,[esi];
			je _for1;
			cmp [ecx+4*ebx],[esi+4*edx];
			jne _for2;
_stil2:
_for3:
			inc ebx;
			mov edx,1;
			mov edi,1;
			cmp [esi+4*edx],[ecx+4*ebx];
			je _for1;
_for4:
			inc edx;
			inc edi;
			cmp edi,[esi];
			je _for1;
			cmp [ecx+4*ebx],[esi+4*edx];
			jne _for2;
		}
	}

	void afisare()
	{
		if(nr==0)
			cout<<"Stiva vida"<<endl;
		else
			for(int i=nr-1;i>=0;i--)
				cout<<"v["<<i+1<<"]="<<v[i]<<endl;
	}
};

void main()
{
	Stiva st;

	st.push(2);
	st.push(3);
	st.push(5);
	st.afisare();

	cout<<"\n"<<st.pop()<<endl;
	system("pause");
}