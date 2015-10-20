/*


6.  Fie S1 o stivă ce conţine ca informaţii în noduri, numere din intervalul [1, n] ordonate crescător de  
    la bază la vârf şi S2 o stivă ce conţine ca informaţii în noduri, numere din intervalul [n+1, n+m]  
    ordonate crescător de la bază la vârf. Să se construiască o stivă ce conţine numerele din cele     
    stive, S1 şi S2, ordonate crescător de la bază la vârf. 
    Exemple: 
    pentru stivele S1 = [1 2 2 5 7 şi S2 = [8 8 9 9, stiva rezultat va fi [1 2 2 5 7 8 8 9 9. 
    pentru stivele S1 = [1 şi S2 = [9 11, stiva rezultat va fi [1 9 11. 


*/

#include<iostream>
#include<stdio.h>


typedef struct st
{
	int val;
	st *prec;
}st;

typedef struct stiva
{
	st *top;
}stiva;

stiva S;
int ns;

stiva stivaVida()
{
	stiva S;
	S.top=NULL;
	return S;
}

void push(stiva *S,int v)
{
	st *s=(st *)malloc(sizeof(st));
	s->val=v;
	s->prec=S->top;
	S->top=s;
}

void citire(stiva *S)
{
	printf("Introduceti numarul de elemente: ");
	scanf("%d",&ns);

	int i,s;
	for(i=1;i<=ns;i++)
	{
		printf("s%d=",i);
		scanf("%d",&s);

		push(S,s);
	}
}

int top(stiva *S)
{
	return S->top->val; 
}

void pop(stiva *S)
{
	S->top=S->top->prec;
}

stiva oglindit(stiva S1)
{
	stiva o;
	st *p;
	o=stivaVida();

	for(p=S1.top;p!=NULL;p=p->prec)
		push(&o,p->val);
	return o;
}

stiva concatenare(stiva S1,stiva S2)
{
	stiva o1=oglindit(S1);
	stiva o2=oglindit(S2);
	stiva c;
	c=stivaVida();

	st *p;
	for(p=o1.top;p!=NULL;p=p->prec)
		push(&c,p->val);
	for(p=o2.top;p!=NULL;p=p->prec)
		push(&c,p->val);

	return c;
}

void afisare(stiva S)
{
	st *p;
	for(p=S.top;p!=NULL;p=p->prec)
		printf("%d\n",p->val);
	printf("\n");
}

int main()
{
	stiva S1,S2;
	S1=stivaVida();
	S2=stivaVida();

	citire(&S1);
	afisare(S1);

	citire(&S2);
	afisare(S2);

	S=concatenare(S1,S2);
	afisare(S);
	system("pause");
	return 0;
}