/* Cand sunt executati contructorii si destructorii ? */
#include <iostream>

using namespace std;

class MyClass
{
public:
	int who;
	MyClass (int ex);
	~MyClass();
} ob1(1), ob2(2);

MyClass::MyClass(int ex)
{
	cout << "Ctor" << ex <<endl;
	who = ex;
}

MyClass::~MyClass()
{
	cout << "Dtor" << who <<endl;
}

int main()
{
	MyClass ob3(3);

	cout << "De ce nu este aceasta prima linie afisata?" << endl;
	MyClass ob4(100);
	return 0;
}