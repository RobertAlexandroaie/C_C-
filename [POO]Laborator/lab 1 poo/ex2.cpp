#include <iostream>

using namespace std;

class MyClass
{
	int a, b;
public:
	MyClass(int i, int j) { a=i; b=j;}
	void show() { cout <<a<<" "<<b<<endl; }
};

int main()
{
	MyClass obj(10, -5);
	obj.show();
	return 0;
}