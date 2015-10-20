#include<iostream>

using std::cout;
using std::cin;

class Punct
{
	int x;
	short int z;
	int y;
	
public:
	void afisare()
	{
		cout<<"x="<<x<<" y="<<y<<" z="<<z<<"\n";
	}

	void set(int a=0,short int b=0,int c=0)
	{
		x=a;
		z=b;
		y=c;
	}
};

/*
void Punct::set(int a,short int b,int c)
{
	_asm{
		//ecx=&p, p fiind obiectul pt cre s-a apelat set()
		mov ebx,a;
		mov [ecx],ebx;

		mov bx,b;
		mov [ecx+4],bx;

		mov ebx,c;
		mov [ecx+8],ebx;
	}
}
*/

int main()
{
	Punct p;

	int *ptr;
	ptr=(int *)(&p);


	p.set(1,2,3);
	
	cout<<"*pp="<<(*ptr)<<"\n";

	p.afisare();

	*(ptr+2)=5;
	p.afisare();

	cout<<"\n"<<sizeof(p)<<"\n";

	system("pause");
	return 0;
}