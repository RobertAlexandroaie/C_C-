// Simple inheritance
#include "useful.h"
#include <iostream>
using namespace std;

/* !!! Clasa din care se mosteneste(clasa de baza) e precedata de specificatorul 'public'. */
class Y : protected X 
{
  int i; // Diferit de i din clasa X !!
public:
  Y() { i = 0; }
  int change() 
  {
    i = permute(); // Apelez permute() al clasei de baza 
    return i;
  }
  void set(int ii) 
  { // Redefinesc set(), ii dau alt inteles pentru clasa derivata
    i = ii;
    X::set(ii); 
  }
};

int main() 
{
  cout << "sizeof(X) = " << sizeof(X) << endl;
  cout << "sizeof(Y) = "
       << sizeof(Y) << endl;
  Y D;
  D.change();
  // Se vor apela versiunile din X ale functiilor read() si permute() pentru D, obiect de tip Y...
  D.read();
  D.permute();
  // dar vesiunea noua a lui set(), cea redefinita in Y
  D.set(12);

}
