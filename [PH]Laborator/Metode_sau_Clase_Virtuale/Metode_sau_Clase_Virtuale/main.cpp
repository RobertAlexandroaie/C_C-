#include<iostream>

using namespace std;

/*
class A
{
	int a;
public:
	virtual void afisare()
	{
		cout<<"a"<<endl;
	}
};

class B:public A
{
	int b;
public:
	void afisare()
	{
		cout<<"b"<<endl;
	}
	
};

class AA
{
public:
	int aa;
	virtual void A1(){ cout<<"a1"<<endl;}
};

class BB
{
public:
	int bb;
	virtual void B1(){cout<<"b1"<<endl;}
};

class AABB:public AA, public BB
{
public:
	int aabb;
	void A1(){cout<<"ab-a"<<endl;}
	void B1(){cout<<"ab-b"<<endl;}
};

void main()
{
	A a;
	B b;
	A *pa;
	
	a.afisare();
	b.afisare();

	pa=&a;
	pa->afisare();
	pa=&b;
	pa->afisare();
	
	system("CLS");
	cout<<"Sizeof b: "<<sizeof(b)<<endl;

	system("CLS");

	_asm
	{
		
		mov eax,pa;//primii 4 octeti-> pointerul la VMT;
		mov ebx,[eax];//adresa de la VMT -> adresa primei metode = B::afisare();
		mov ecx,eax;
		
		//sau
		
		
		lea eax,b;
		mov ebx,[eax];
		mov ecx,eax;
		

		//sau

		lea ecx,b;
		mov ebx,[ecx];

		call dword ptr [ebx];//apelare functie din ebx -> apelare B::afisare();
	}

	system("CLS");
	
	AA aa;
	BB bb;
	AABB x;
	/*
	_asm
	{
		lea ecx,x;
		mov eax,[ecx];
		mov ebx,[ecx];

		call dword ptr [eax];
		call dword ptr [ebx];
	}
	
	cout<<"Sizeof x="<<sizeof(x)<<" de la "<<&x<<endl;
	cout<<"Sizeof x.aa="<<sizeof(aa)<<" de la "<<&x.aa<<endl;
	cout<<"Sizeof x.bb="<<sizeof(bb)<<" de la "<<&x.bb<<endl;
	cout<<"Sizeof x.aabb="<<sizeof(x)<<" de la "<<&x.aabb<<endl;
	system("pause");
}

*/

//Metode virtuale

class A {public: int a;};
class B:virtual public A {public: int b;};
class C:virtual public A {public: int c;};
class D:public B,public C {public: int d;};
void main()
{
	D d;

	cout<<"Sizeof(d)="<<sizeof(d)<<endl;
	cout<<"&d.a="<<&d.a<<endl;
	cout<<"&d.b="<<&d.b<<endl;
	cout<<"&d.c="<<&d.c<<endl;
	cout<<"&d.d="<<&d.d<<endl;

	D *p;
	int i;
	printf("");+
	system("pause");
}