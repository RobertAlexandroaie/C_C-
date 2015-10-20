#include <iostream>

using namespace std;

class MyClass
{
	int a, b;
public:
	void init(int i, int j);
	void show();
};

void MyClass::init(int i, int j)
{
	a=i;
	b=j;
}

void MyClass::show()
{
	cout << a << " " << b << endl;
}

int main()
{
	MyClass c;
	c.init(10, 20);
	c.show();
	return 0;
}