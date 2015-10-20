#include "view.h"

int main()
{
	Acquiantance myAcq("Ionescu", "1212121", "afacerist");
	cout << myAcq.toString();
	Friend myFriend("Popescu", "7676767", "12-12-1999");
	cout << myFriend.toString();
	
	View view(&myAcq);
	view.displayContact();
	view.setContact(&myFriend);
	view.displayContact();
/*
	cout << endl << sizeof(Contact)  << endl;
*/
	return 0;
}