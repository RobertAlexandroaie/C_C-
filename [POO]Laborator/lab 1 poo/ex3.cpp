#include <iostream>

using namespace std;

class MyClass
{
	int a, b;
public:
	MyClass(int i) { a=i;}
	void show() { cout << a << endl; }
};

int main()
{
	MyClass obj = 99;
	obj.show();
	return 0;
}