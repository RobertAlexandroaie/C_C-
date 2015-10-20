#include "Stack.h"

int main()
{
	Stack s;
	int opt,value;
	while( 1 )
	{
		cout<<"1.Push an element on the stack\n";
		cout<<"2.Pop an element from the stack\n";
		cout<<"3.Return the stack top element\n";
		cout<<"4.Return the stack size\n";
		cout<<"5.Exit\n\n";

		cin>>opt;

		switch(opt)
		{
		case 1:
			cout<<"\n\nEnter a value:";
			cin>>value;
			try
			{
				s.push(value);
			}
			catch (char *error)
			{
				cout<<"\nError:"<<error<<endl;
			}

			break;
		case 2:
			try
			{
				s.pop();
			}
			catch (char *error)
			{
				cout<<"\nError:"<<error<<endl;
			}
			break;
		case 3:
			try
			{
				cout<<"The stack top is:"<<s.top()<<endl;
			}
			catch (char *error)
			{
				cout<<"\nError:"<<error<<endl;
			}
			break;
		case 4:
			cout<<"The stack current size is:"<<s.GetStackSize()<<endl;
			break;
		case 5:
			cout<<"\nExit\n";
			exit(0);
			break;
		default:
			cout<<"\nAlegere incorecta\n";
		}
		cin.sync();
		cout<<"\n\nPress Enter to continue";
		cin.get();
		system("cls");
	}
	return 0;
}