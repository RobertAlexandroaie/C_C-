#include <iostream>
#include "stack.h"

using namespace std;

void main(void)
{
  Stack s;
  char c='a';
 try {
	// cout << s.top();
    while (true) {
      s.push(c++);
      cout << s.top() << endl;
    }
  }
  catch (char *mes_err) {
    cout << mes_err << endl;
  }

//  Stiva s1;
//  s1.push('a');
//  s1.push('b');
//  Stiva s2;
//  s2 = s1;
//  s2.afiseaza();
//  s2.pop();
//  s1.afiseaza();
//  s2.afiseaza();
}
