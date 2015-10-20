#include "stack.h"
#include <iostream>

using namespace std;


Stack::Stack (int nMaxParam)
{
  arr = new char[nMaxParam];
  top_index = -1;
  nMax = nMaxParam;
}

Stack::~Stack()
{
  //nimic
}

void Stack::push(char c) 
{
  if (top_index == nMax-1) 
	  throw "Depasire superioara.";
  arr[++top_index] = c;
}

void Stack::pop() 
{
  if (top_index < 0) 
	  throw "Depasire inferioara.";
  top_index--;
}

char Stack::top()
{
  if (top_index < 0) 
	  throw "Depasire inferioara.";
  return arr[top_index];
}

bool Stack::is_empty()
{ 
	return top_index == -1; 
}

void Stack::display()
{
	for(int i=0; i <= top_index; ++i)
		cout << arr[i] << "; ";
	cout << endl;
}