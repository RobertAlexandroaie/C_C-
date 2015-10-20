#include<iostream>
using std::cout;
using std::cin;

struct S
{
	int x;
	int y;
	int sum()
	{
		return x+y;
	}
};

struct Punct{
	int x;
	short int y;
	int z;
};

Punct NewPunct(Punct *p)//ebp+12
{
	//sa returneze un Punct p2 care are valorile x,y,z =p->y
	/*
	Punct p2;
	p2.x=p->y;
	p2.y=p->y;
	p2.z=p->y;
	return p2;
	*/
	_asm{
		mov eax,[ebp+12];//adresa lui p
		mov ebx,[ebp+8];//adresa lui p2

		mov cx,[eax+4];//p->y
		movzx edx,cx;

		mov [ebx],edx;//p2.x
		mov [ebx+4],edx;//p2.y
		mov [ebx+8],edx;//p2.z

		mov eax,ebx;
	}
}

int main()
{
	/*
	S a;
	a.x=4;
	a.y=5;

	cout<<a.sum()<<"\n";
	*/

	Punct p1;
	p1.x=1;
	p1.y=2;
	p1.z=3;

	Punct p2;
	p2=NewPunct(&p1);

	cout<<p2.x<<" "<<p2.y<<" "<<p2.z<<"\n";

	system("pause");
	return 0;
}