/* Cand sunt executati contructorii si destructorii ? */
#include "Stack.h"

Stack::Stack()
{
	stack_size = 0;
}

Stack::Stack( int value )
{
	element = new Element;
	element->info = value;
	element->next = element->prev = NULL;
	stack_size = 1;
}

void Stack::push( int value )
{
	if( stack_size == MAX_SIZE )
		throw "The stack is full";
	if(!stack_size)
		element = new Element;
	else
	{
		element->next = new Element;
		element->next->prev = element;
		element = element->next;
	}
	element->info = value;
	element->next = NULL;
	stack_size++;
}

int Stack::pop()
{
	if( !stack_size )
		throw "The stack is empty";
	int tmp = element->info;
	Element *e = element;
	element = element->prev;
	delete e;
	stack_size--;
	if( stack_size == 1 )
			element->prev = NULL;
	return tmp;
}

int Stack::GetStackSize()
{
	return stack_size;
}

int Stack::top()
{
	if( !stack_size )
		throw "The stack is empty";
	return element->info;
}

Stack::~Stack()
{
	stack_size = 0;
}