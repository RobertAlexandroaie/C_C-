/* A class that counts its objects
   making use of a static variable
*/
#include <fstream>
#include <string>
using namespace std;
ofstream out("HowMany.out");

class HowMany 
{
  static int objectCount;
public:
  HowMany() { objectCount++; } // The constructor increments no of objects
  static void print(const string& msg = "") 
  {
    if(msg.size() != 0) out << msg << ": ";
    out << "objectCount = "
         << objectCount << endl;
  }
  ~HowMany() //The destructor, decrements it
  {
    objectCount--;
    print("~HowMany()"); 
  }
};

int HowMany::objectCount = 0;

// Pass and return BY VALUE:
HowMany f(HowMany x) 
{
  x.print("x argument inside f()");
  return x;
}

int main() 
{
  HowMany h;
  HowMany::print("after construction of h");
  HowMany h2 = f(h);
  HowMany::print("after call to f()");
}
