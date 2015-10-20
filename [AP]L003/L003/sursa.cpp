/*

detectarea erorilor.

*/

#include<iostream>
#include<stdio.h>

int main()
{
	char p[]="abcdefghi";
	char* q=p;
	

	for(;*q;++q)
		printf("%c",*q);
	printf("\n");


	printf("q=%         &q=%p       &q[0]=%p\n",q,&q,&q[0]);
//	printf("p=%c        &p=%d       &p[0]=%d\n",p,&p,&p[0]);


	system("pause");
	return 0;
}