#include<iostream>
using namespace std;

class A
{
public:
	int a;
	A(){cout<<"A ";}
};

class A2:public A
{
public:
	int a2;
	A2(){cout<<"A2 ";}
};

class B
{
public:
	int b;
	B(){cout<<"B ";}
};

class B2:public B
{
public:
	int b2;
	//A2 a;
	B2(){cout<<"B2 ";}
};

class C:public A2,public B2
{
public:
	int c;
	//B2 b;
	C(){cout<<"C ";}
};

void main()
{
	C x;//observarea constructorilor.
	cout<<"\n";
	
	//observarea dimensiunii si organizarii obiectului x.
	cout.width(10);
	cout<<"x: "<<&x<<" "<<sizeof(x)<<"\n\n";
	cout.width(10);
	cout<<"x.a: "<<&x.a<<" "<<sizeof(x.a)<<"\n";
	cout.width(10);
	cout<<"x.a2: "<<&x.a2<<" "<<sizeof(x.a2)<<"\n";
	cout.width(10);
	cout<<"x.b: "<<&x.b<<" "<<sizeof(x.b)<<"\n";
	cout.width(10);
	cout<<"x.b2: "<<&x.b2<<" "<<sizeof(x.b2)<<"\n";
	cout.width(10);
	cout<<"x.c: "<<&x.c<<" "<<sizeof(x.c)<<"\n";
	
	system("pause");
}