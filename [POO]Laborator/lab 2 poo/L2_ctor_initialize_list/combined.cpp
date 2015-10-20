#include <iostream>
using namespace std;

class A 
{
  int i;
public:
  A(int ii) : i(ii) {}
  ~A() {/*cout << "Dtor A"<<endl;*/}
  void f() const {}
};

class B 
{
  int i;
public:
  B(int ii) : i(ii) 
  { 
	  /*cout <<"i=.."<<i<<endl; */
	  cout << "Initializez valoarea lui i ininate de a apela constructorul B" << endl; 
  }
  ~B() {/*cout << "Dtor B"<<endl;*/}
  void f() const {}
};

class C : public B 
{
  A a;
public:
  C(int ii) : B(ii), a(ii) {cout << "Apelez constructorul B inainte de constructorul C" <<endl;} 
  ~C() {cout << "Dtor C"<<endl;} // Destructorul C invoca  ~A() si ~B()
  void f() const 
  {  // functie redefinita
    a.f();
    B::f();
  }
};

int main() {
  C c(47);
}