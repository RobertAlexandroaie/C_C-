#include "useful.h"

class Y 
{
  int i;
public:
  X x; // Obiect embedded 
  Y() { i = 0; }
  void f(int ii) { i = ii; }
  int g() const { return i; }
};

int main() 
{
  Y y;
  y.f(47);
  y.x.set(37); // Accessarea functiilor membru ale obiectelor embedded  (a sub-obiectelor) se face ca o noua selectie a unui membru
}
