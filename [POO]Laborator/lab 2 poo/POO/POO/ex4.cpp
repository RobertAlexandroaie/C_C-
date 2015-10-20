#include <iostream>

using namespace std;

class MyClass
{
	static int a;  // se declara variabila statica
	int b;
public:
	void init(int i, int j) { a=i; b=j; }
	void show();
};

int MyClass::a; // abia aici se aloca memorie, este definita variabila

void MyClass::show()
{
	cout << "Acesta este a static: " << a;
	cout << "\nAcesta este b ne-static: " << b <<endl;
}

int main()
{
	/* Nu se vor crea copii individuale ale lui a pentru o1 si o2, ci o singura copie */
	MyClass o1, o2,o3;

	o3.init(100,3);

	o1.init(1, 1);
	o1.show();


	o2.init(2,2);
	o2.show();

	o1.show();
	o2.show();
	return 0;
}