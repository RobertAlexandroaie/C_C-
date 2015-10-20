
#include <stdio.h>
#include <string.h>
class MyString{
	char s[256];
public:
	void strcpy(char*){
		_asm{
			mov eax,[ebp+8]
			xor edx,edx
_loop:	
			mov bl,[eax+edx]
			cmp bl,0
			je _out
			mov [ecx+edx],bl
			inc edx
			jmp _loop
_out:
			mov [ecx+edx],byte ptr 0
		}
	}
	void strcat(char*){
		_asm{
			mov eax,[ebp+8]
final_str_loop:
			cmp [ecx],byte ptr 0
			jz concat
			inc ecx
			jmp final_str_loop
concat:
			xor edx,edx
_loop:	
			mov bl,[eax+edx]
			cmp bl,0
			je _out
			mov [ecx+edx],bl
			inc edx
			jmp _loop
_out:
			mov [ecx+edx],byte ptr 0
		}
	}
};

void main(){
	MyString ms;
	ms.strcpy("Ana are ");
	ms.strcat("mere");
	printf("%s",(char*)&ms);
}