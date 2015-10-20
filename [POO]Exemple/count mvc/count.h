#ifndef Count_H
#define Count_H
#include <string>
using namespace std;

class Count
{
public:
	Count(char*);
	~Count();
	void deposit(double);
	void draw(double);
	double balance();
private:
	string *owner;
	double sold;
	string countNo;
	void assignCountNo();
	void releaseCountNo();
};

#endif