#include<iostream>

using namespace std;

class MyString
{
public:
	 char s[128];

public:
	 MyString()
	 {
		 strcpy(s,"");
	 }

	 void setString(char *ss)
	 {
		//strcpy(s, ss);
		 _asm
		 {
			mov ebx,0;
			mov eax,[ebp+8];

_bucla:
			mov dl,[eax+ebx];
			mov [ecx+ebx],dl;
			inc ebx;
			cmp dl,0;
			jne _bucla;

			dec ebx;
			mov [ecx+ebx],dl;
		 }
	 }

	 void addString(char *ss)
	 {
		//strcat(s, ss);
		 _asm
		 {
			 mov ebx,0;
			 cmp byte ptr [ecx+ebx],0;
			 je _exit_bucla;
_bucla:
			 inc ebx;
			 cmp byte ptr [ecx+ebx],0;
			 jne _bucla;

_exit_bucla:
			 mov esi,0;
			 mov eax,[ebp+8];
			 
			 mov dl,[eax+esi];
			 mov [ecx+ebx],dl;
			 cmp dl,0;
			 je _exit_bucla2;
_bucla2:
			 inc ebx;
			 inc esi;
			 mov dl,[eax+esi];
			 mov [ecx+ebx],dl;
			 cmp dl,0;
			 jne _bucla2;
_exit_bucla2:

		 }
	 }

	 void showString()
	 {
		 cout<<s<<endl;
	 }
};

void main()
{
	MyString s;
	s.setString("Robert ");
	s.showString();

	s.addString("Alexandroaie");
	s.showString();
	system("pause");
}