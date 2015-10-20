#include <iostream>
using namespace std;

struct Str1{
char c;
short s;
int i;
};
 
struct Str2{
char c;
int i;
short s;
};


Str1 generate(char c)
{
 _asm{
	 mov al,[ebp+8]
    }
}


Str1 generate(short s)
{
 _asm{
		mov ax,[ebp+8]
		shl eax,16
 }
}


Str1 generate(int i)
{
 _asm{
		mov edx,[ebp+8]
 }
}

Str1 generate(char c,short s, int i)
{
 _asm{
		mov ax,[ebp+12]
		shl eax,16
		mov al,[ebp+8]
		mov edx,[ebp+16]
    }
}

Str2 generate_2(char c)
{
 _asm{
 mov eax,[ebp+8]
 mov bl, [ebp+12]
 mov [eax], bl
 } 
}



Str2 generate_2(short s)
{
 _asm{
 mov eax,[ebp+8]
 mov bx, [ebp+12]
 mov [eax+8], bx
 } 
}



Str2 generate_2(int i)
{
 _asm{
 mov eax,[ebp+8]
 mov ebx, [ebp+12]
 mov [eax+4], ebx
 } 
}

Str2 generate_2(char c,short s, int i)
{
 _asm{
	 mov eax,[ebp+8]
	 mov bl, [ebp+12]
	 mov [eax], bl
	 mov bx, [ebp+16]
	 mov [eax+8], bx
	 mov eax,[ebp+8]
	 mov [eax+4], ebx
    }
}

void afisare(Str1 s1)
{
	cout<<"Str1: c: " <<s1.c << ", i: " << s1.i << ", s: " << s1.s<<endl;
	//printf("Str1: c: %c, i: %d, s: %d\n",s1.c,s1.i,s1.s);
}

void afisare(Str2 s2)
{
	cout<<"Str1: c: " <<s2.c << ", i: " << s2.i << ", s: " << s2.s<<endl;
	//printf("Str2: c: %c, i: %d, s: %d\n",s2.c,s2.i,s2.s);
}

void main()
{
	afisare(generate('a'));
	afisare(generate((short)2));
	afisare(generate((int)2000));
	afisare(generate('a',2,2000));
	cout<<endl;
	afisare(generate_2('a'));
	afisare(generate_2((int)2000));
	afisare(generate_2((short)2));
	afisare(generate_2('a',2,2000));
}