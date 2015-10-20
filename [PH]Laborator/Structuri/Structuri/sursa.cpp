#include<iostream>

struct str{
	int x;
	char c;
	int y;
	short int d;
};

str s;

struct s2{
	int x;
	char c;
	short int y;
	int t;
};

int f1(s2 s){//calculeaza suma membrilor structurii S4
	_asm{
		mov eax,[ebp+8];

		mov bl,[ebp+12];
		movzx ecx,bl
		add eax,ecx;

		mov bx,[ebp+14];
		movzx ecx,bx;
		add eax,ecx;

		add eax,[ebp+16];
	}
}

int f2(s2 *s)
{
	_asm{
		mov ecx,[ebp+8];
		mov eax,[ecx];

		mov bl,[ecx+4];
		movzx edx,bl;
		add eax,edx;

		mov bx,[ecx+6];
		movzx edx,bx;
		add eax,edx;

		add eax,[ecx+8];
	}
}

struct Punct{
	int x;
	char c;
	short int d;
	char e;
	char f;
	short int z;
};


int Sum(Punct *p)
{
	_asm{
	mov edx,[ebp+8];
	mov eax,[edx];

	mov bl,[edx+4];
	movzx ecx,bl;
	add eax,ecx;

	mov bx,[edx+6];
	movzx ecx,bx;
	add eax,ecx;

	mov bl,[edx+8];
	movzx ecx,bl;
	add eax,ecx;

	mov bl,[edx+10];
	movzx ecx,bl;
	add eax,ecx;

	mov bx,[edx+12];
	movzx ecx,bx;
	add eax,ecx;
	}
}

void main()
{
	printf("%d\n",sizeof(s));
	printf("x: %d	<->%d\nc: %d	<->%d\ny: %d	<->%d\nd: %d	<->%d\n",&s,sizeof(s.x),&s.c,sizeof(s.c),&s.y,sizeof(s.y),&s.d,sizeof(s.d));

	s2 ss;
	ss.x=1;
	ss.c=2;
	ss.y=3;
	ss.t=4;


	//printf("suma=%d\n",f1(ss));
	//printf("suma=%d\n",f2(&ss));

	Punct p;
	p.x=1;
	p.c=1;
	p.d=1;
	p.e=1;
	p.f=1;
	p.z=1;

	printf("suma=%d\n",Sum(&p));
	system("pause");
}