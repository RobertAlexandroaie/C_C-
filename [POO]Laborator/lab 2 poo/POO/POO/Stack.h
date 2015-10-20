#include <iostream>

using namespace std;

#define MAX_SIZE 512

struct Element
{
	Element *next,*prev;
	int info;
};

class Stack
{
private:
	Element *element;
	int stack_size;
public:
	Stack();
	Stack(int value);
	int pop();
	void push(int);
	int GetStackSize();
	int top();
	~Stack();
};